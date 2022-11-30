// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	absBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	StaticMeshMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube"));
	SetRootComponent(StaticMeshMesh);
	absBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	absBox->SetupAttachment(StaticMeshMesh);
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("StaticMesh'/Engine/BasicShapes/Cube'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> ghostMaterialAsset(*ghostMaterialName);
	_ghostMaterial = ghostMaterialAsset.Object;
	
	if (mesh.Succeeded())
	{
		absBox->SetWorldScale3D(FVector(2.0f, 2.0f, 2.0f));
		StaticMeshMesh->SetStaticMesh(mesh.Object);
		StaticMeshMesh->SetMaterial(0, _ghostMaterial);

	}
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	EnemyGI = UGameInstance::GetSubsystem<UEnemyGameInstanceSubsystem>(GetWorld()->GetGameInstance());
	const UEnum* EnemyStateEnum = FindObject<UEnum>(ANY_PACKAGE, TEXT("EState"), true);
	if (EnemyStateEnum)
	{
		EnemyStateName = EnemyStateEnum->GetNameStringByValue((int64)EnemyState);
	}
	if (EnemyGI == nullptr)
	{
		return;
	}
	else
	{
		EnemyGI->SetHp(EnemyHp);
		EnemyGI->SetMaxHp(EnemyGI->GetHp());
		EnemyGI->SetState(EnemyState);
		EnemyGI->EnemydieCheck = false;
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("[ Attack ] : %d"), EnemyGI->GetHp()));
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("[ Max ] : %d"), EnemyGI->GetMaxHp()));
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, "State : " + EnemyStateName);
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("===[Enemy]===")));

	}
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}


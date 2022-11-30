// Fill out your copyright notice in the Description page of Project Settings.


#include "Absorption.h"

// Sets default values
AAbsorption::AAbsorption()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	absBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	StaticMeshMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube"));
	SetRootComponent(StaticMeshMesh);
	absBox->SetupAttachment(StaticMeshMesh);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("StaticMesh'/Engine/BasicShapes/Cube'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> ghostMaterialAsset(*ghostMaterialName);
	_ghostMaterial = ghostMaterialAsset.Object;
	if (mesh.Succeeded())
	{
		absBox->SetWorldScale3D(FVector(2.0f, 2.0f, 2.0f));
		StaticMeshMesh->SetStaticMesh(mesh.Object);
		StaticMeshMesh->SetMaterial(0, _ghostMaterial);
		AbsorptionSpawnCheck = false;
	}

}

// Called when the game starts or when spawned
void AAbsorption::BeginPlay()
{
	Super::BeginPlay();
	EnemyGI = UGameInstance::GetSubsystem<UEnemyGameInstanceSubsystem>(GetWorld()->GetGameInstance());
	AbsorGI = UGameInstance::GetSubsystem<UAbsorptionGameInstanceSubsystem>(GetWorld()->GetGameInstance());
	if (AbsorGI == nullptr && EnemyGI == nullptr)
	{
		return;
	}
	else
	{
		AbsorGI->SetHp(EnemyGI->GetMaxHp());
		AbsorGI->GetHp();
		int(AbsorGI->Hp *= 1.5f);
		AbsorptionHp = AbsorGI->Hp;
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("[ Max 2 ] : %d"), AbsorptionHp));

	}
}

// Called every frame
void AAbsorption::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AAbsorption::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


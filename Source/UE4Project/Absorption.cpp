// Fill out your copyright notice in the Description page of Project Settings.


#include "Absorption.h"

// Sets default values
AAbsorption::AAbsorption()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	absBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	StaticMeshMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Boat"));
	SetRootComponent(StaticMeshMesh);
	absBox->SetupAttachment(StaticMeshMesh);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("StaticMesh'/Game/Cartoon_ships/Models/SM_Boat1'"));
	ghostMaterialName = "Material'/Game/Cartoon_ships/Materials/MI_PirateBoatsSmallGreen'";
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> ghostMaterialAsset(*ghostMaterialName);
	_ghostMaterial = ghostMaterialAsset.Object;
	if (mesh.Succeeded())
	{
		absBox->SetWorldScale3D(FVector(2.0f, 2.0f, 2.0f));
		absBox->SetWorldLocation(FVector(0.0f, 0.0f, 0.0f));
		StaticMeshMesh->SetStaticMesh(mesh.Object);
		StaticMeshMesh->SetMaterial(0, _ghostMaterial);
		AbsorptionSpawnCheck = false;
	}

}

// Called when the game starts or when spawned
void AAbsorption::BeginPlay()
{
	Super::BeginPlay();
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

void AAbsorption::AbsorptionInit_Implementation()
{
	AMonster* monster = Cast<AMonster>(GetInstigator());
	if (monster == nullptr)
	{
		return;
	}
	else
	{
		AbsorptionHp = monster->monsterPowerMax;
		const UEnum* AbsorptionStateEnum = FindObject<UEnum>(ANY_PACKAGE, TEXT("EAState"), true);
		if (AbsorptionStateEnum)
		{
			AbsorptionStateName = AbsorptionStateEnum->GetNameStringByValue((int64)AbsorptionState);
		}
		int(AbsorptionHp *= 1.5f);
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("[ Hp ] : %d"), AbsorptionHp));

	}
}

void AAbsorption::AbsorptionRandomInit_Implementation()
{
	const UEnum* AbsorptionStateEnum = FindObject<UEnum>(ANY_PACKAGE, TEXT("EAState"), true);
	if (AbsorptionStateEnum)
	{
		AbsorptionStateName = AbsorptionStateEnum->GetNameStringByValue((int64)AbsorptionState);
	}
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("[ RandomHp ] : %d"), AbsorptionHp));
}
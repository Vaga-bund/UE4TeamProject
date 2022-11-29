// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "EnemyGameInstanceSubsystem.h"
#include "Engine/Classes/Components/StaticMeshComponent.h"
#include "Engine/Classes/Components/BoxComponent.h"
#include "Enemy.generated.h"

UCLASS()
class UE4PROJECT_API AEnemy : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UEnemyGameInstanceSubsystem* EnemyGI;


	UPROPERTY(EditAnyWhere, BlueprintReadWrite, category = "EnemyStat")
		int EnemyHp;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, category = "EnemyStat")
		EState EnemyState;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, category = "EnemyStat")
		FString EnemyStateName = FString(TEXT(""));

public:
	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent* StaticMeshMesh;
	UPROPERTY(VisibleAnywhere)
		class UBoxComponent* absBox;
	UPROPERTY(VisibleInstanceOnly)
		UMaterialInterface* _ghostMaterial = nullptr;
	FString ghostMaterialName = "Material'/Game/Material/EnemyColor_Inst'";
	
};

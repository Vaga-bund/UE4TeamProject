// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Monster.h"
#include "Engine/Classes/Components/StaticMeshComponent.h"
#include "Engine/Classes/Components/BoxComponent.h"
#include "Absorption.generated.h"


UENUM(BlueprintType)
enum class EAState : uint8
{
	RandomSpawn,
	DieAfterSpawn
};
UCLASS()
class UE4PROJECT_API AAbsorption : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAbsorption();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


public:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, category = "AbsorptionStat")
		int AbsorptionHp;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, category = "AbsorptionStat")
		bool AbsorptionSpawnCheck;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, category = "AbsorptionStat")
		EAState AbsorptionState;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, category = "AbsorptionStat")
		FString AbsorptionStateName = FString(TEXT(""));


public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* StaticMeshMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UBoxComponent* absBox;
	UPROPERTY(VisibleInstanceOnly)
		UMaterialInterface* _ghostMaterial = nullptr;
	FString ghostMaterialName = "Material'/Game/Material/AbsorptionColor_Inst'";


public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, category = "AbsorptionStat")
		void AbsorptionInit();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, category = "AbsorptionStat")
		void AbsorptionRandomInit();


};

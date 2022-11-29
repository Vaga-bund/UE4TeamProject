// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AbsorptionGameInstanceSubsystem.generated.h"

/**
 *
 */
UCLASS()
class UE4PROJECT_API UAbsorptionGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, category = "AbsorptionStat")
		int Hp;

public:
	UFUNCTION(BlueprintPure, category = "AbsorptionStat")
		int GetHp() const { return Hp; }

public:
	UFUNCTION(BlueprintCallable, category = "AbsorptionStat")
		void SetHp(int curHp) { Hp = curHp; }
};

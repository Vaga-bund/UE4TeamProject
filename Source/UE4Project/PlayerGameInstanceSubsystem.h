// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
//#include "MyGameInstance.h"
#include "PlayerGameInstanceSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class UE4PROJECT_API UPlayerGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, category = "PlayerStat")
		int Damage;


	UFUNCTION(BlueprintPure, category = "PlayerStat")
		int GetDamage() const { return Damage; }


	UFUNCTION(BlueprintCallable, category = "PlayerStat")
		void SetDamage(int curDamage) { Damage = curDamage; }
};

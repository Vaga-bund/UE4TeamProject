// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "EnemyGameInstanceSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class UE4PROJECT_API UEnemyGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, category = "MonsterStat")
		int Damage;


	UFUNCTION(BlueprintPure, category = "MonsterStat")
		int GetDamage() const { return Damage; }


	UFUNCTION(BlueprintCallable, category = "MonsterStat")
		void SetDamage(int curDamage) { Damage = curDamage; }
};

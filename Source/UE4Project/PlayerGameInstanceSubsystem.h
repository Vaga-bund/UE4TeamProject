// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
//#include "MyGameInstance.h"
#include "EnemyGameInstanceSubsystem.h"
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
		int Damage = 1;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, category = "PlayerStat")
		int Hp;

public:
	UFUNCTION(BlueprintPure, category = "PlayerStat")
		int GetHp() const { return Hp; }

public:
	UFUNCTION(BlueprintCallable, category = "PlayerStat")
		void SetHp(int curHp) { Hp = curHp; }
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, category = "PlayerStat")
		void SetAddDamage(int fightDamage);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, category = "PlayerStat")
		void SetSubDamage();
	UFUNCTION(BlueprintCallable, category = "PlayerDie")
		void PlayerDie();


};

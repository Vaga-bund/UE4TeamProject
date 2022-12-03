// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
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
		int Hp;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, category = "PlayerStat")
		int MaxHp;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, category = "PlayerStat")
		bool PlayerDieCheck;
	

public:
	UFUNCTION(BlueprintPure, category = "PlayerStat")
		int GetHp() const { return Hp; }
	UFUNCTION(BlueprintPure, category = "PlayerStat")
		int GetMaxHp() const { return MaxHp; }
	

public:
	UFUNCTION(BlueprintCallable, category = "PlayerStat")
		void SetHp(int curHp) { Hp = curHp; }
	UFUNCTION(BlueprintCallable, category = "PlayerStat")
		void SetMaxHp(int curMaxHp) { MaxHp = curMaxHp; }
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, category = "PlayerStat")
		void SetAddDamage(int fightDamage);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, category = "PlayerStat")
		void SetSubDamage(int fightDamage);
	UFUNCTION(BlueprintCallable, category = "PlayerDie")
		void PlayerDie();


};

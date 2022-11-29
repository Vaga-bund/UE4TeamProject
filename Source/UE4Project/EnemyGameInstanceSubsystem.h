// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PlayerGameInstanceSubsystem.h"
#include "EnemyGameInstanceSubsystem.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EState : uint8
{
	Enemy,
	Absorption
};

UCLASS()
class UE4PROJECT_API UEnemyGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()


public:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, category = "EnemyStat")
		int Damage = 1;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, category = "EnemyStat")
		int Hp;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, category = "EnemyStat")
		int MaxHp;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, category = "EnemyStat")
		EState enemyState = EState::Enemy;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, category = "EnemyStat")
		FString EnemyStateName = FString(TEXT(""));


public:
	UFUNCTION(BlueprintPure, category = "EnemyStat")
		int GetHp() const { return Hp; }
	UFUNCTION(BlueprintPure, category = "EnemyStat")
		int GetMaxHp() const { return MaxHp; }
	UFUNCTION(BlueprintPure, category = "EnemyStat")
		EState GetState() const { return enemyState; }
	

public:
	UFUNCTION(BlueprintCallable, category = "EnemyStat")
		void SetHp(int curHp) { Hp = curHp; }
	UFUNCTION(BlueprintCallable, category = "EnemyStat")
		void SetMaxHp(int curMaxHp) { MaxHp = curMaxHp; }
	UFUNCTION(BlueprintCallable, category = "EnemyStat")
		void SetState(EState curState) { enemyState = curState; }
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, category = "EnemyStat")
		void SetAddDamage(int fightDamage);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, category = "EnemyStat")
		void SetSubDamage();
	UFUNCTION(BlueprintCallable, category = "EnemyDie")
		void EnemyDie();
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyGameInstanceSubsystem.h"
#include "Enemy.h"
#include "Absorption.h"

void UEnemyGameInstanceSubsystem::SetAddDamage_Implementation(int fightDamage)
{

	Hp += fightDamage;
	SetHp(Hp);
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("[ curEnDamage_add ] : %d"), GetHp()));


}

void UEnemyGameInstanceSubsystem::SetSubDamage_Implementation(int fightDamage)
{
	UPlayerGameInstanceSubsystem* PlayerGI;
	PlayerGI = UGameInstance::GetSubsystem<UPlayerGameInstanceSubsystem>(GetWorld()->GetGameInstance());
	if (PlayerGI == nullptr)
	{
		return;
	}
	else
	{
		if (MaxHp > fightDamage)
		{
			Hp = MaxHp - fightDamage;
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("[ curEnDamage_sub ] : %d"), GetHp()));
		}
		else if (Hp == fightDamage)
		{
			;
		}
		else
		{
			Hp = MaxHp - fightDamage;
			if (Hp <= 0)
			{
				Hp = 0;
				EnemydieCheck = true;
			}
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("[ curEnDamage_sub ] : %d"), GetHp()));
		}
	}
	

}


void UEnemyGameInstanceSubsystem::EnemyDie()
{
	if (Hp <= 0)
	{
		enemyState = EState::Absorption;
		const UEnum* EnemyStateEnum = FindObject<UEnum>(ANY_PACKAGE, TEXT("EState"), true);
		if (EnemyStateEnum)
		{
			EnemyStateName = EnemyStateEnum->GetNameStringByValue((int64)enemyState);
		}
		SetState(enemyState);
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, "State : " + EnemyStateName);
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("[ Absorption ] ")));


	}


}
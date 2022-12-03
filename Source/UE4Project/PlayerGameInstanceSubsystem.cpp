// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerGameInstanceSubsystem.h"


void UPlayerGameInstanceSubsystem::SetAddDamage_Implementation(int fightDamage)
{
	Hp += fightDamage;
	SetHp(Hp);
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("[ curCaDamage_add ] : %d"), GetHp()));


}

void UPlayerGameInstanceSubsystem::SetSubDamage_Implementation(int fightDamage)
{
	if (MaxHp >= fightDamage)
	{
		Hp = Hp - fightDamage;
		SetHp(Hp);
		if (Hp <= 0)
		{
			Hp = 0;
			PlayerDieCheck = true;
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("[ PlayerDie ] : %d"), PlayerDieCheck));
		}
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("[ curCaDamage_sub ] : %d"), GetHp()));
	}
	/*else
	{
		Hp = fightDamage - Hp;
		SetHp(Hp);
		if (Hp <= 0)
		{
			Hp = 0;
			PlayerDieCheck = true;
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("[ PlayerDie ] : %d"), PlayerDieCheck));
			PlayerDie();
		}
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("[ curCaDamage_sub ] : %d"), GetHp()));
	}*/
}

void UPlayerGameInstanceSubsystem::PlayerDie()
{
	if (Hp <= 0)
	{
		//게임오버 화면
	}
}
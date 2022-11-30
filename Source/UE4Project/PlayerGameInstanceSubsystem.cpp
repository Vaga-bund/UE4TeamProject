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
	UEnemyGameInstanceSubsystem* EnemyGI;
	EnemyGI = UGameInstance::GetSubsystem<UEnemyGameInstanceSubsystem>(GetWorld()->GetGameInstance());
	if (EnemyGI == nullptr)
	{
		return;
	}
	else
	{
		if (MaxHp > fightDamage)
		{
			Hp = MaxHp - fightDamage;
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("[ curCaDamage_sub ] : %d"), GetHp()));
		}
		else if (Hp == fightDamage)
		{
			;
		}
		else
		{
			Hp = MaxHp - fightDamage;
			if (Hp < 1)
			{
				Hp = 0;
			}
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("[ curCaDamage_sub ] : %d"), GetHp()));
		}
	}
	

}

void UPlayerGameInstanceSubsystem::PlayerDie()
{
	if (Hp <= 0)
	{
		//게임오버 화면
	}
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerGameInstanceSubsystem.h"


void UPlayerGameInstanceSubsystem::SetAddDamage_Implementation(int fightDamage)
{
	Hp += fightDamage;
	SetHp(Hp);
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("[ CaAttack ] : %d"), GetHp()));


}

void UPlayerGameInstanceSubsystem::SetSubDamage_Implementation()
{
	UEnemyGameInstanceSubsystem* EnemyGI;
	EnemyGI = UGameInstance::GetSubsystem<UEnemyGameInstanceSubsystem>(GetWorld()->GetGameInstance());
	if (EnemyGI == nullptr)
	{
		return;
	}
	if (Hp < EnemyGI->Hp)
	{
		Hp = EnemyGI->Damage - Hp;
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("[ caAttack_2 ] : %d"), GetHp()));
	}	

}

void UPlayerGameInstanceSubsystem::PlayerDie()
{
	if (Hp <= 0)
	{
		//게임오버 화면
	}
}
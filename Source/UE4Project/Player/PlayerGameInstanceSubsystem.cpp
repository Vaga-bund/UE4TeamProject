// Fill out your copyright notice in the Description page of Project Settings.
//¹Ú¿¬Áö

#include "PlayerGameInstanceSubsystem.h"

UPlayerGameInstanceSubsystem::UPlayerGameInstanceSubsystem() : playerPower(5)
{

}

void UPlayerGameInstanceSubsystem::SetAddDamage_Implementation(int fightDamage)
{
	playerPower += fightDamage;
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("[ CaAttack ] : %d"), playerPower));


}

// Fill out your copyright notice in the Description page of Project Settings.


#include "Monster.h"

// Sets default values
AMonster::AMonster()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMonster::BeginPlay()
{
	Super::BeginPlay();
	
	playerGISS = GetGameInstance()->GetSubsystem<UPlayerGameInstanceSubsystem>(GetWorld()->GetGameInstance());
}

// Called every frame
void AMonster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMonster::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMonster::Crash()
{
	if (monsterPower <= playerGISS->playerPower)
	{
		playerGISS->playerPower -= monsterPower; //여기서 플레이어도 같이 처리해줌
		monsterPower = 0;
		Destroy();
	}
	else
	{
		monsterPower -= playerGISS->playerPower;
		playerGISS->playerPower = 0;
	}
}

void AMonster::SetMonsterPower(const int32& plusPower)
{
	monsterPower += plusPower;
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "TreasureIsland.h"

// Sets default values
ATreasureIsland::ATreasureIsland()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATreasureIsland::BeginPlay()
{
	Super::BeginPlay();

	playerGISS = GetGameInstance()->GetSubsystem<UPlayerGameInstanceSubsystem>(GetWorld()->GetGameInstance());
}

// Called every frame
void ATreasureIsland::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATreasureIsland::Reinforcement()
{
	radomInt = FMath::RandRange(0, 10);

	if (radomInt >= 0 && radomInt <= 2) //30퍼 확률로 강화 성공
	{
		playerGISS->playerPower *= 2;
	}
	else //실패하면
	{
		playerGISS->playerPower /= 2;
	}

	Destroy();
}
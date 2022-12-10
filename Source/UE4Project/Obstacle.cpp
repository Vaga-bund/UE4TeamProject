// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle.h"

// Sets default values
AObstacle::AObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AObstacle::BeginPlay()
{
	Super::BeginPlay();
	
	playerGISS = GetGameInstance()->GetSubsystem<UPlayerGameInstanceSubsystem>(GetWorld()->GetGameInstance());
}

// Called every frame
void AObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AObstacle::Crash()
{
	playerGISS->playerPower -= playerGISS->playerPower * 0.2;

	Destroy();
}
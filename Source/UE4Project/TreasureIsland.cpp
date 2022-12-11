// Fill out your copyright notice in the Description page of Project Settings.


#include "TreasureIsland.h"

// Sets default values
ATreasureIsland::ATreasureIsland()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	static ConstructorHelpers::FObjectFinder<UBlueprint> spawnTI(TEXT("Blueprint'/Game/TreasureIsland/TreasureIslandBPClear.TreasureIslandBPClear'"));
	
	if (spawnTI.Object != NULL)
	{
		spawnTIBlueprint = (UClass*)spawnTI.Object->GeneratedClass;
	}
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

	if (radomInt >= 0 && radomInt <= 2)
	{
		playerGISS->playerPower *= 2;
	}
	else
	{
		playerGISS->playerPower /= 2;
	}

	Destroy();
}

void ATreasureIsland::Destroyed()
{
	Super::Destroyed();

	UWorld* world = GetWorld();
	if (world)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		FRotator rotator = GetActorRotation();
		FVector  SpawnLocation = GetActorLocation();
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("!"));
		world->SpawnActor<AActor>(spawnTIBlueprint, SpawnLocation, rotator, SpawnParams);
	}
}
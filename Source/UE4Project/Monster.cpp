// Fill out your copyright notice in the Description page of Project Settings.


#include "Monster.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMonster::AMonster()/*addMonsterBool(false)*/
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
	monsterPowerMax = monsterPower;

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

void AMonster::SetMonsterPower(int32 plusPower)
{
	monsterPower += plusPower;
}
/*
void AMonster::AddMonster(AActor* otherActor)
{
	AMonster* otherMonster = Cast<AMonster>(otherActor);

	if (monsterPower > otherMonster->monsterPower)
	{
		SetMonsterPower(otherMonster->monsterPower);
		addMonsterBool = true;
	}
	else if (monsterPower == otherMonster->monsterPower)
	{
		//둘 중 하나만 삭제할 방법을 알면 추가할 것
	}
}*/
/*
void AMonster::Destroyed()
{
	Super::Destroyed();


}*/
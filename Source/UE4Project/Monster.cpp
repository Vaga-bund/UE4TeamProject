// Fill out your copyright notice in the Description page of Project Settings.


#include "Monster.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMonster::AMonster() : radomInt(0)
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
		playerGISS->playerPower -= monsterPower; //���⼭ �÷��̾ ���� ó������
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

void AMonster::AddMonster(AActor* otherActor)
{
	AMonster* otherMonster = Cast<AMonster>(otherActor);

	if (otherMonster != nullptr)
	{
		if (monsterPower > otherMonster->monsterPower)
		{
			SetMonsterPower(otherMonster->monsterPower);
			SetUIPowerCpp();
		}
		else if (monsterPower == otherMonster->monsterPower)
		{
			radomInt = FMath::RandRange(0, 100);
			
			/*
			while (true)
			{
				//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("while"));
				if (radomInt > otherMonster->radomInt)
				{
					SetMonsterPower(otherMonster->monsterPower);
					GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("radomInt > otherMonster->radomInt"));
					SetUIPowerCpp_Implementation();
					break;
				}
				else if (radomInt < otherMonster->radomInt)
				{
					dead = true;
					Destroy();
					break;
				}
				else
				{
					radomInt = FMath::RandRange(0, 10);
				}
			}*/

			if (radomInt > otherMonster->radomInt)
			{
				SetMonsterPower(otherMonster->monsterPower);
				SetUIPowerCpp();
			}
			else if (radomInt < otherMonster->radomInt)
			{
				Destroy();
			}
			else
			{
				radomInt = FMath::RandRange(0, 100);
			}
		}
		else
		{
			Destroy();
		}
	}

}

/*
void AMonster::Destroyed()
{
	Super::Destroyed();


}*/
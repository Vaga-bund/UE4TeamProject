// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	EnemyGI = UGameInstance::GetSubsystem<UEnemyGameInstanceSubsystem>(GetWorld()->GetGameInstance());
	const UEnum* EnemyStateEnum = FindObject<UEnum>(ANY_PACKAGE, TEXT("EState"), true);
	if (EnemyStateEnum)
	{
		EnemyStateName = EnemyStateEnum->GetNameStringByValue((int64)EnemyState);
	}
	if (EnemyGI == nullptr)
	{
		return;
	}
	else
	{
		EnemyGI->SetHp(EnemyHp);
		EnemyGI->SetState(EnemyState);
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("===[Enemy]===")));
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("[ Attack ] : %d"), EnemyGI->GetHp()));
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, "State : " + EnemyStateName);
		
	}
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}


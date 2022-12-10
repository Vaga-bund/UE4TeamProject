// Fill out your copyright notice in the Description page of Project Settings.
//박연지 추가
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UE4Project/Player/PlayerGameInstanceSubsystem.h"
#include "TreasureIsland.generated.h"

UCLASS()
class UE4PROJECT_API ATreasureIsland : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATreasureIsland();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void Reinforcement();

private:
	UPROPERTY()
	int32 radomInt;

	UPROPERTY()
	UPlayerGameInstanceSubsystem* playerGISS;
};

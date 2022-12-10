// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UE4Project/Player/PlayerGameInstanceSubsystem.h"
#include "Obstacle.generated.h"

UCLASS()
class UE4PROJECT_API AObstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObstacle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void Crash(); //�ε����� ��

private:
	UPROPERTY()
	UPlayerGameInstanceSubsystem* playerGISS;
};

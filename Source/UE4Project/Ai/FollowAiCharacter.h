// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FollowAiCharacter.generated.h"

UCLASS()
class UE4PROJECT_API AFollowAiCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFollowAiCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public :
	UPROPERTY(EditAnywhere, Category = "BehaviorTree")
		class UBehaviorTree* BehaviorTree;
};

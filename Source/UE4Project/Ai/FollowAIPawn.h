// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "FollowAIPawn.generated.h"

UCLASS()
class UE4PROJECT_API AFollowAIPawn : public APawn
{
	GENERATED_BODY()

public:
	AFollowAIPawn();

public:
	UPROPERTY(EditAnywhere, Category = "BehaviorTree")
		class UBehaviorTree* BehaviorTree;
};

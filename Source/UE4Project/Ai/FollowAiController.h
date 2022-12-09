// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "FollowAiController.generated.h"

/**
 * 
 */
UCLASS()
class UE4PROJECT_API AFollowAiController : public AAIController
{
	GENERATED_BODY()
public:
	AFollowAiController();

	virtual void OnPossess(APawn* InPawn) override;

	static const FName TargetKey;
protected :
	class UBehaviorTreeComponent* BehaviorComp;
	class UBlackboardComponent* BlackboardComp;
};
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "FollowerToPlayerBTService.generated.h"

/**
 * 
 */
UCLASS()
class UE4PROJECT_API UFollowerToPlayerBTService : public UBTService
{
	GENERATED_BODY()
public :
	UFollowerToPlayerBTService();
protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};

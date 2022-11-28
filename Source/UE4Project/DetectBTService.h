// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "DetectBTService.generated.h"

/**
 * 
 */
UCLASS()
class UE4PROJECT_API UDetectBTService : public UBTService
{
	GENERATED_BODY()
public:
	UDetectBTService();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};

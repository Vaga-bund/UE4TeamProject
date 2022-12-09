// Fill out your copyright notice in the Description page of Project Settings.


#include "FollowAiController.h"
#include "FollowAiCharacter.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

const FName AFollowAiController::TargetKey(TEXT("Player"));

AFollowAiController::AFollowAiController()
{
	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(FName("BehaviorComponent"));
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(FName("BlackboardComponent"));
}

void AFollowAiController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	AFollowAiCharacter* AICharacter = Cast<AFollowAiCharacter>(InPawn);

	if (AICharacter)
	{
		if (AICharacter->BehaviorTree->BlackboardAsset)
		{
			BlackboardComp->InitializeBlackboard(*(AICharacter->BehaviorTree->BlackboardAsset));
			BehaviorComp->StartTree(*AICharacter->BehaviorTree);
		}
	}

}
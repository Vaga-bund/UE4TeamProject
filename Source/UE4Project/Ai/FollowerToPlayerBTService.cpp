// Fill out your copyright notice in the Description page of Project Settings.

#include "FollowerToPlayerBTService.h"
#include "FollowAiController.h"
#include "UE4Project/Player/MouseCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UFollowerToPlayerBTService::UFollowerToPlayerBTService()
{
	NodeName = TEXT("DetectNPC");
}

void UFollowerToPlayerBTService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	APawn* ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (nullptr == ControllingPawn) return;

	UWorld* World = ControllingPawn->GetWorld();
	if (nullptr == World) return;

	AMouseCharacter* Player = Cast<AMouseCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

	if (Player && Player->GetController()->IsPlayerController())
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(AFollowAiController::TargetKey, Player);
		return;
	}

	OwnerComp.GetBlackboardComponent()->SetValueAsObject(AFollowAiController::TargetKey, nullptr);
}
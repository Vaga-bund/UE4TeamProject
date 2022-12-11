// Fill out your copyright notice in the Description page of Project Settings.

#include "DetectBTService.h"
#include "EnemyAIController.h"
#include "UE4Project/Player/MouseCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"

UDetectBTService::UDetectBTService()
{
	NodeName = TEXT("Detect");
	detectdRadius = 600.0f;
	Interval = 1.0f;
}

void UDetectBTService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	APawn* ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (nullptr == ControllingPawn) return;

	UWorld* World = ControllingPawn->GetWorld();
	FVector Center = ControllingPawn->GetActorLocation();

	if (nullptr == World) return;
	TArray<FOverlapResult> OverlapResults;
	FCollisionQueryParams CollisionQueryParam(NAME_None, false, ControllingPawn);
	bool bResult = World->OverlapMultiByChannel(
		OverlapResults,
		Center,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(detectdRadius),
		CollisionQueryParam
	);

	if (bResult)
	{
		for (auto const& OverlapResult : OverlapResults)
		{
			AMouseCharacter* ABCharacter = Cast<AMouseCharacter>(OverlapResult.GetActor());
			if (ABCharacter && ABCharacter->GetController()->IsPlayerController())
			{
				OwnerComp.GetBlackboardComponent()->SetValueAsObject(AEnemyAIController::TargetKey, ABCharacter);
				
				return;
			}
		}
	}
	//무한 추적을 위해서 초기화 제거
	//OwnerComp.GetBlackboardComponent()->SetValueAsObject(AEnemyAIController::TargetKey, nullptr);
}
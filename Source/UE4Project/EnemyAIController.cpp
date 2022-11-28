// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyAIController.h"
#include "UObject/ConstructorHelpers.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "BlackBoardKeys.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "EngineGlobals.h"
#include "UE4ProjectCharacter.h"

const FName AEnemyAIController::HomePosKey(TEXT("HomePos"));
const FName AEnemyAIController::TargetLocation(TEXT("TargetLocation"));

AEnemyAIController::AEnemyAIController(FObjectInitializer const& object_initializer)
{
	//ConstructorHelpers로 에디터에 미리 만들어둔 비헤이비어트리를 지정
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BTObject(TEXT("BehaviorTree'/Game/Movable/AI/EnemyBT.EnemyBT'"));

	if (BTObject.Succeeded())
	{
		btree = BTObject.Object;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("BT completed!"));
	}

	behavior_tree_component = object_initializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorComp"));
	blackboard = object_initializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackboardComp"));

	//Perception초기화
	SetPerceptionSystem();
}

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();
	RunBehaviorTree(btree);
	behavior_tree_component->StartTree(*btree);
}

void AEnemyAIController::OnPossess(APawn* pawn)
{
	Super::OnPossess(pawn);
	if (blackboard)
	{
		//비헤이비어트리에 있는 블랙보드로 초기화
		blackboard->InitializeBlackboard(*btree->BlackboardAsset);
	}

}

UBlackboardComponent* AEnemyAIController::get_blackboard() const
{
	return blackboard;
}

void AEnemyAIController::OnUpdated(TArray<AActor*> const& updated_actors)
{
}

void AEnemyAIController::OnTargetDetected(AActor* actor, FAIStimulus const Stimulus)
{
	if (auto const player = Cast<AUE4ProjectCharacter>(actor))
	{
		//성공적으로 감지하면 블랙보드에 true값을 넣어준다.
		get_blackboard()->SetValueAsBool(BB_Keys::canSeePlayer, Stimulus.WasSuccessfullySensed());
	}
}

void AEnemyAIController::SetPerceptionSystem()
{
	SightConfig = CreateOptionalDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	SetPerceptionComponent(*CreateOptionalDefaultSubobject<UAIPerceptionComponent>(TEXT("AI Perception")));


	SightConfig->SightRadius = AISightRadius;
	SightConfig->LoseSightRadius = SightConfig->SightRadius + AILoseSightRadius;
	SightConfig->PeripheralVisionAngleDegrees = AIFieldOfView;
	SightConfig->SetMaxAge(AISightAge);
	SightConfig->AutoSuccessRangeFromLastSeenLocation = AILastSeenLocation;

	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;

	GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());
	GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &AEnemyAIController::OnTargetDetected);
	GetPerceptionComponent()->ConfigureSense(*SightConfig);
}
// Fill out your copyright notice in the Description page of Project Settings.
//박연지
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "UE4Project/Player/PlayerGameInstanceSubsystem.h"
#include "Monster.generated.h"

UCLASS()
class UE4PROJECT_API AMonster : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMonster();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//virtual void Destroyed() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 monsterPower;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 monsterPowerMax; 
	//중립체력 계속할 때 필요( monsterPower이걸로 사용하면 적 체력
	// 계산된 상태로 나와서 0이 출력...)


	UFUNCTION(BlueprintCallable)
	void Crash(); //부딪쳤을 때

	UFUNCTION(BlueprintCallable)
	void SetMonsterPower(int32 plusPower); //중립(랜덤 스폰 되는 것만) 또는 몬스터와 충돌했을 때 파워를 받음

	UFUNCTION(BlueprintCallable)
	void AddMonster(AActor* otherActor);

	UFUNCTION(BlueprintImplementableEvent)
	void SetUIPowerCpp();

private:
	UPROPERTY()
	UPlayerGameInstanceSubsystem* playerGISS;

	UPROPERTY()
	int32 radomInt;
};

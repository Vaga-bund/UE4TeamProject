// Fill out your copyright notice in the Description page of Project Settings.
//�ڿ���
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
	//�߸�ü�� ����� �� �ʿ�( monsterPower�̰ɷ� ����ϸ� �� ü��
	// ���� ���·� ���ͼ� 0�� ���...)


	UFUNCTION(BlueprintCallable)
	void Crash(); //�ε����� ��

	UFUNCTION(BlueprintCallable)
	void SetMonsterPower(int32 plusPower); //�߸�(���� ���� �Ǵ� �͸�) �Ǵ� ���Ϳ� �浹���� �� �Ŀ��� ����

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

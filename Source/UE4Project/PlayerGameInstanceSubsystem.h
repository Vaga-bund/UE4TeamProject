// Fill out your copyright notice in the Description page of Project Settings.
//�ڿ���
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PlayerGameInstanceSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class UE4PROJECT_API UPlayerGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
	//�÷��̾� HP �� �÷��̾� ���ݷ��� ������ ���������� ���� �Ǳ� ������ ���� �ν��Ͻ��� ������
public:
	UPlayerGameInstanceSubsystem();

	UPROPERTY(BlueprintReadOnly)
	int32 playerPower;
};
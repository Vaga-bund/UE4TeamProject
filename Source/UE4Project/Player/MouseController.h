// Fill out your copyright notice in the Description page of Project Settings.
//�ڿ���
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "MouseController.generated.h"

/**
 * 
 */
UCLASS()
class UE4PROJECT_API AMouseController : public APlayerController
{
	GENERATED_BODY()

public:
	AMouseController();

	UPROPERTY()
	FVector mouseLocation;

	UPROPERTY(BlueprintReadWrite)
	bool mouseClick;

	UFUNCTION(BlueprintCallable)
	void MouseMove();

	UFUNCTION()
	void MouseCursor(); //���콺 ��ġ ������

	UFUNCTION()
	virtual void SetupInputComponent() override;

	UFUNCTION()
	void InputMouseLeft(float AxisValue);
};

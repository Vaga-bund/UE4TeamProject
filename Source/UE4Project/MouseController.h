// Fill out your copyright notice in the Description page of Project Settings.

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

	UPROPERTY()
	FVector playerLocation;

	UPROPERTY(BlueprintReadWrite)
	bool mouseClick;

	UFUNCTION(BlueprintCallable)
	void MouseLeftPressed(const FVector& Location);

	UFUNCTION()
	void MoveToMouseCursor();
};

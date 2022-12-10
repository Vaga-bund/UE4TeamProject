// Fill out your copyright notice in the Description page of Project Settings.
//박연지 추가

#include "MouseGameModeBase.h"

AMouseGameModeBase::AMouseGameModeBase()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	PlayerControllerClass = AMouseController::StaticClass(); //마우스 컨트롤러를 기본으로
}
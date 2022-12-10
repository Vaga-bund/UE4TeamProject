// Fill out your copyright notice in the Description page of Project Settings.
//�ڿ��� �߰�

#include "MouseGameModeBase.h"

AMouseGameModeBase::AMouseGameModeBase()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	PlayerControllerClass = AMouseController::StaticClass(); //���콺 ��Ʈ�ѷ��� �⺻����
}
// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE4TeamProjectGameMode.h"
#include "UE4TeamProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE4TeamProjectGameMode::AUE4TeamProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE4ProjectGameMode.h"
#include "UE4ProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE4ProjectGameMode::AUE4ProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

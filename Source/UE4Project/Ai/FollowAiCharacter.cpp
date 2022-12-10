// Fill out your copyright notice in the Description page of Project Settings.

#include "FollowAiCharacter.h"
#include "FollowAiController.h"
#include "UE4Project/Player/UE4ProjectCharacter.h"

// Sets default values
AFollowAiCharacter::AFollowAiCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFollowAiCharacter::BeginPlay()
{
	Super::BeginPlay();
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "NpcSample.h"

// Sets default values
ANpcSample::ANpcSample()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANpcSample::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANpcSample::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANpcSample::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

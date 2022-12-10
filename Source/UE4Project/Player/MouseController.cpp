// Fill out your copyright notice in the Description page of Project Settings.
//�ڿ���

#include "MouseController.h"
//#include "Engine/Engine.h"

AMouseController::AMouseController()
{
    //bShowMouseCursor = true;
    SetShowMouseCursor(true);
    //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("���콺"));
}

void AMouseController::MouseMove()
{
    APawn* const MyPawn = GetPawn();

    MouseCursor(); //���콺 ��ġ ������

    if (mouseClick == true)
    {
        UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, mouseLocation);
    }
    else if (mouseClick == false)
    {
        UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, MyPawn->GetActorLocation());
    }
}

void AMouseController::MouseCursor()
{
    FHitResult Hit;
    GetHitResultUnderCursor(ECC_Visibility, false, Hit);

    if (Hit.bBlockingHit)
    {
        mouseLocation = Hit.ImpactPoint;
    }
}

void AMouseController::SetupInputComponent()
{
    Super::SetupInputComponent();

    InputComponent->BindAxis("MouseLeft", this, &AMouseController::InputMouseLeft);
}

void AMouseController::InputMouseLeft(float AxisValue)
{
    if (AxisValue > 0)
    {
        mouseClick = true;
    }
    else
    {
        mouseClick = false;
    }

    MouseMove();
}
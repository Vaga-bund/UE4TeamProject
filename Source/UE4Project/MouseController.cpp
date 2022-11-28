// Fill out your copyright notice in the Description page of Project Settings.


#include "MouseController.h"

AMouseController::AMouseController()
{
    bShowMouseCursor = true;
}

void AMouseController::MouseLeftPressed(const FVector& Location)
{
    MoveToMouseCursor();

    //처음에 실행하면 가운데로 갔다가 멈추는 오류 있음
    //시작할때 마우스 입력이 0이여서 else if문이 시작되는데 플레이어의 위치 값이 0, 0, 0이여서 그런 것 같음
    //시작할때 플레이어의 위치 값 설정 필요 or 최초의 마우스 클릭 없이는 이동할 수 없게 막아놓기
    if (mouseClick == true)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("mouseClick == true"));
        playerLocation = Location;
        UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, mouseLocation);
    }
    else if (mouseClick == false)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("mouseClick == false"));
        UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, playerLocation);
    }

    //이렇게 하면 무조건 마우스를 누른 그 쪽까지 쭉 간다.
    //마우스를 떼면 바로 멈추게 해야함
}

void AMouseController::MoveToMouseCursor()
{
    FHitResult Hit;
    GetHitResultUnderCursor(ECC_Visibility, false, Hit);

    if (Hit.bBlockingHit)
    {
        mouseLocation = Hit.ImpactPoint;
    }
}
// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

ATank * ATankPlayerController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());



}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerConroller Begin Play"));

	ATank *ControllerTank =  GetControllerTank();
	if (ControllerTank) {
		UE_LOG(LogTemp, Warning, TEXT(".. controlling tank [%s]"), *ControllerTank->GetName() );
	}
	else {
		UE_LOG(LogTemp, Error, TEXT(".. Could NOT get tank "));
	}

}

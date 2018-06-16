// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

ATank * ATankPlayerController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());



}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("TankPlayerController: Begin Play"));

	ATank *ControllerTank =  GetControllerTank();
	if (ControllerTank) {
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController: controlling tank [%s]"), *ControllerTank->GetName() );
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("TankPlayerController: Could NOT get tank "));
	}

}

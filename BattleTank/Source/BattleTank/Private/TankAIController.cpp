// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Classes/Engine/World.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("TankAIController: Begin Play"));

	ControllerTank = GetControllerTank();
	if (ControllerTank) {		UE_LOG(LogTemp, Warning, TEXT("TankAIController: controlling tank [%s]"), *ControllerTank->GetName());
	}	else {		UE_LOG(LogTemp, Error, TEXT("TankAIController:  Could NOT get controlling tank "));	}

	PlayerTank = GetPlayerTank();
	if (PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("TankAIController: player tank [%s]"), *PlayerTank->GetName());
	}
	else { UE_LOG(LogTemp, Error, TEXT("TankAIController:  Could NOT get player tank ")); }



}


void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	if ((ControllerTank) && (PlayerTank)) {
		// TODO Move Towards Player

		// Aim Towards Player
		AimAtPlayer();

		// Fire at Player

	}

	
	
}


ATank * ATankAIController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}


ATank * ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

//-------------------
void ATankAIController::AimAtPlayer() {
	if ((ControllerTank) && (PlayerTank)) {
		ControllerTank->AimAt(PlayerTank->GetActorLocation());
	}
	
}
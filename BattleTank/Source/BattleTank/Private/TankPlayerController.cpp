// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

///------------------
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("TankPlayerController: Begin Play"));

	//ATank *ControllerTank =  GetControllerTank();
	ControllerTank = GetControllerTank();
	if (ControllerTank) {
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController: controlling tank [%s]"), *ControllerTank->GetName() );
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("TankPlayerController: Could NOT get tank "));
	}

}
///------------------
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("TankPlayerController: Tick.."));

	AimTowardsCrosshair();

}
///------------------
ATank * ATankPlayerController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}
///------------------
void ATankPlayerController::AimTowardsCrosshair() {
	if (!ControllerTank) return;

	FVector HitLocation; 
	if (GetSightRayHitLocation(HitLocation)) {
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController: HitLocation: %s"), *HitLocation.ToString());
	}
	// TODO Aim at point
}

///------------------
bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation) const
{
	/// get location of Crosshair
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	FVector2D ScreenLocation( (ViewPortSizeX*CrossHairXLocation) , (ViewPortSizeY*CrossHairYLocation) );
	
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController: WorldDirection: %s"), *LookDirection.ToString());
		
		

	}
	


	HitLocation = FVector(1.0);
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const
{
	/// deproject screen to world direction
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);

}

bool ATankPlayerController::GetVectorHitLocation(FVector LookDirection, FVector &HitLocation) const
{
	// Raytrace along lookdirection
	/*
	FHitResult OutHit;
	bool result = GetWorld()->LineTraceSingleByChannel(
		OutHit,
		LookDirection,
		LookDirection,
		*/
	return false;
}
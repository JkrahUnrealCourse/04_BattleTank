// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "CollisionQueryParams.h"
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
		//UE_LOG(LogTemp, Warning, TEXT("TankPlayerController: HitLocation: %s"), *HitLocation.ToString());
		// TODO Aim at point
		ControllerTank->AimAt(HitLocation);
	}
}

///------------------
bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation) 
{
	/// get location of Crosshair
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	FVector2D ScreenLocation( (ViewPortSizeX*CrossHairXLocation) , (ViewPortSizeY*CrossHairYLocation) );
	
	if (GetLookDirection(ScreenLocation)) {
		//UE_LOG(LogTemp, Warning, TEXT("TankPlayerController: WorldDirection: %s"), *LookDirection.ToString());
		
		if (GetVectorHitLocation(HitLocation)) {
			//UE_LOG(LogTemp, Warning, TEXT("TankPlayerController: GetVectorHitLocation: %s"), *HitLocation.ToString());
			return true;
		}
	}
	
	HitLocation = FVector(0);
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation) 
{
	/// deproject screen to world direction
	//FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);

}

bool ATankPlayerController::GetVectorHitLocation(FVector &HitLocation) const
{
	// Raytrace along lookdirection
	FHitResult HitResult;
	//FVector RayCastStart = PlayerCameraManager->GetCameraLocation();

	FVector RayCastEnd(CameraWorldLocation + (LookDirection*LineTraceRange));
	//RayCastEnd += CameraWorldLocation;

	FCollisionQueryParams CollisionQueryParams;
	FCollisionResponseParams CollisionResponseParams;

	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		CameraWorldLocation,
		RayCastEnd,
		ECollisionChannel::ECC_Visibility)){ 
//		CollisionQueryParams,
	//	CollisionResponseParams)) {

		HitLocation = HitResult.Location;
		return true;
	}
			
	return false;
}
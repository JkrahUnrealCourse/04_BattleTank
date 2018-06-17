// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "Tank.h"

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // must be last include

class ATank;

/**
 * 
 */
UCLASS() class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere) float CrossHairXLocation = 0.5;
	UPROPERTY(EditAnywhere) float CrossHairYLocation = 0.33333f;
	UPROPERTY(EditAnywhere) float LineTraceRange = 200000.0f;



private:
	ATank * GetControllerTank() const;
	ATank * ControllerTank = nullptr;
	FVector CameraWorldLocation;
	FVector LookDirection;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;	// TODO do we need to tick

	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector &HitLocation) ;
	bool GetLookDirection(FVector2D ScreenLocation);
	bool GetVectorHitLocation(FVector &HitLocation) const;
};

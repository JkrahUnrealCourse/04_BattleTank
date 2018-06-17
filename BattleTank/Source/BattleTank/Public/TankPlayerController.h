// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // must be last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere) float CrossHairXLocation = 0.5;
	UPROPERTY(EditAnywhere) float CrossHairYLocation = 0.33333f;
	UPROPERTY(EditAnywhere) float LineTraceRange = 10.0f;



private:
	ATank * GetControllerTank() const;
	ATank * ControllerTank = nullptr;
	FVector CameraWorldLocation;

	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector &HitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const;
	bool GetVectorHitLocation(FVector LookDirection, FVector &HitLocation) const;
};
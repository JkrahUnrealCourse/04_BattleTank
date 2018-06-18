// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"


void UTankTurret::Rotate(float RelativeSpeed) {
	// RelativeSpeed -1 max down, +1 max up
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	//float time = GetWorld()->GetTimeSeconds();
	//UE_LOG(LogTemp, Warning, TEXT("UTankBarrel.Elevate[%f]: %s DegreesPerSecond: %f"), time, *(GetOwner()->GetName()), RelativeSpeed);

	float RotationChange = RelativeSpeed * MaxRotationDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float NewRotation = RelativeRotation.Yaw + RotationChange;

	//float NewRotation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);

	SetRelativeRotation(FRotator(0, NewRotation, 0));

}



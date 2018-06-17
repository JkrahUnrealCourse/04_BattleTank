// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed) {
	// RelativeSpeed -1 max down, +1 max up
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	//float time = GetWorld()->GetTimeSeconds();
	//UE_LOG(LogTemp, Warning, TEXT("UTankBarrel.Elevate[%f]: %s DegreesPerSecond: %f"), time, *(GetOwner()->GetName()), RelativeSpeed);

	float ElevationChange = RelativeSpeed * MaxElevationDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	float NewElevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);

	SetRelativeRotation(FRotator(NewElevation, 0, 0));

}





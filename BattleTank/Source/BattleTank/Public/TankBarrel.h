// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
//UCLASS()

// Tank Barrel Params
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
	class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float RelativeSpeed);
	

private:
	UPROPERTY(EditAnywhere, Category = Setup) float MaxElevationDegreesPerSecond = 10;
	UPROPERTY(EditDefaultsOnly, Category = Setup) float MinElevationDegrees = 0;
	UPROPERTY(EditDefaultsOnly, Category = Setup) float MaxElevationDegrees = 40;
	
	

};

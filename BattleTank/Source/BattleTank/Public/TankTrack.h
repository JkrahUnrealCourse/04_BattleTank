// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
 // Tank Trank Params
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
		UFUNCTION(BlueprintCallable, Category = Input) void SetThrottle(float Throttle);

		// max force per track in newtons
		// f=ma =  40000 x 10m/s
		UPROPERTY(EditDefaultsOnly, Category = Setup) float TrackMaxDrivingForce = 40000000.0f;

		
};

// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"


void UTankMovementComponent::IntendMoveForward(float Throw) {

	UE_LOG(LogTemp, Warning, TEXT("UTankMovementComponent.IntendMoveForward[%f]: %s Throttle = %f"),
		GetWorld()->GetTimeSeconds(), *(GetOwner()->GetName()), Throw);
}


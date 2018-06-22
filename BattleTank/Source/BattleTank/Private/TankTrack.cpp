// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "Components/PrimitiveComponent.h"

void  UTankTrack::SetThrottle(float Throttle) {
	//UE_LOG(LogTemp, Warning, TEXT("UTankTrack.SetThrottle[%f]: %s Throttle = %f"), GetWorld()->GetTimeSeconds(), *(GetOwner()->GetName()), Throttle);
	// TODO clamp Throttle
	FVector ForceApplied = GetForwardVector() * TrackMaxDrivingForce * Throttle;
	FVector ForceLoction = GetComponentLocation();

	UPrimitiveComponent *TankRoot = Cast<UPrimitiveComponent> (GetOwner()->GetRootComponent());

	TankRoot->AddForceAtLocation(ForceApplied, ForceLoction);
}


// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAimingComponent.h"	// must be first include

#include "Components/StaticMeshComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent *BarrelToSel) {	Barrel = BarrelToSel;	}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//UE_LOG(LogTemp, Warning, TEXT("ATank: %s AimLocation: %s"), *GetName(), *HitLocation.ToString());
	// ...
}

void UTankAimingComponent::AimAt(FVector HitLocation) {
	//UE_LOG(LogTemp, Warning, TEXT("UTankAimingComponent: %s AimLocation: %s"), *GetName(), *HitLocation.ToString());
	if (Barrel) {
		FVector BarrelLocation = Barrel->GetComponentLocation();
		UE_LOG(LogTemp, Warning, TEXT("UTankAimingComponent: %s BarrelLocation: %s AimLocation: %s"), 
			*(GetOwner()->GetName()), *BarrelLocation.ToString(), *HitLocation.ToString());

	}
}

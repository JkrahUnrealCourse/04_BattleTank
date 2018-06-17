// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAimingComponent.h"	// must be first include

#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankBarrel.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel *BarrelToSel) {	Barrel = BarrelToSel;	}


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

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed) {
	
	if (Barrel) {
		FVector OutLaunchVelocity;
		bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
			this,
			OutLaunchVelocity,
			Barrel->GetSocketLocation(FName("Projectile")),
			HitLocation,
			LaunchSpeed,
			ESuggestProjVelocityTraceOption::DoNotTrace);
			if (bHaveAimSolution) {
				// getsafe normal = 1 unit vector
				FVector AimDirection = OutLaunchVelocity.GetSafeNormal();
				//UE_LOG(LogTemp, Warning, TEXT("UTankAimingComponent: %s AimDirection: %s"), *(GetOwner()->GetName()), *AimDirection.ToString());

				MoveBarrelTowards(AimDirection);


		}



	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) {
	// Move Barrel
	// get rotation from AimDirection
	// move barrel to new rotation
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	
	//UE_LOG(LogTemp, Warning, TEXT("UTankAimingComponent: %s MoveBarrelTowards BarrelRotator: %s AimAsRotator: %s"), *(GetOwner()->GetName()), *BarrelRotator.ToString(), *AimAsRotator.ToString());
	Barrel->Elevate(5); // TODO remove magic number
}
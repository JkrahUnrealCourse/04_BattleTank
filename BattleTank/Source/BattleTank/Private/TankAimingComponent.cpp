// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAimingComponent.h"	// must be first include

#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "TankTurret.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel *BarrelToSel) {	Barrel = BarrelToSel;	}
void UTankAimingComponent::SetTurretReference(UTankTurret *TurretToSel) { Turret = TurretToSel; }

// Called when the game starts
void UTankAimingComponent::BeginPlay(){			Super::BeginPlay();		}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//UE_LOG(LogTemp, Warning, TEXT("ATank: %s AimLocation: %s"), *GetName(), *HitLocation.ToString());
	// ...
}
//--------------------------
void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed) {
	if ((!Barrel) || (!Turret)) return;

	
	FVector OutLaunchVelocity;
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		Barrel->GetSocketLocation(FName("Projectile")),
		HitLocation,
		LaunchSpeed,
		false, 
		0, 
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace);
		if (bHaveAimSolution) {
			FVector AimDirection = OutLaunchVelocity.GetSafeNormal();	// getsafe normal = 1 unit vector
			MoveBarrelTowards(AimDirection);
			//UE_LOG(LogTemp, Warning, TEXT("UTankAimingComponent.AimAt[%f]: %s Found Solution"), GetWorld()->GetTimeSeconds(), *(GetOwner()->GetName()));
		}
	//	else {	
	//		UE_LOG(LogTemp, Warning, TEXT("UTankAimingComponent.AimAt[%f]: %s NO Found Solution"), GetWorld()->GetTimeSeconds(), *(GetOwner()->GetName()));
	//	}
			
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) {

	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	FRotator DeltaRotator = AimAsRotator - BarrelRotator;
	//UE_LOG(LogTemp, Warning, TEXT("UTankAimingComponent: %s MoveBarrelTowards BarrelRotator: %s AimAsRotator: %s"), *(GetOwner()->GetName()), *BarrelRotator.ToString(), *AimAsRotator.ToString());
	Barrel->Elevate(DeltaRotator.Pitch); 
	Turret->Rotate(DeltaRotator.Yaw); 
}
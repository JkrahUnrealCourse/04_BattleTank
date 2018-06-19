// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
#include "Classes/Engine/World.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMeshSocket.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Add TankAimingComponent
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("AimingComponent"));


}

// Called when the game starts or when spawned
void ATank::BeginPlay(){	Super::BeginPlay();	}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent){
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
//-------------------
void ATank::AimAt(FVector HitLocation) {					
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);	
}

void ATank::SetBarrelReference(UTankBarrel *BarrelToSel) {
	Barrel = BarrelToSel;
	TankAimingComponent->SetBarrelReference(BarrelToSel); 
}

void ATank::SetTurretReference(UTankTurret *TurretToSel) {	
	TankAimingComponent->SetTurretReference(TurretToSel);	
}
//-------------
void ATank::Fire() {

	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTime;
	if (Barrel && isReloaded) {
		// spawn projective at barrel socket
		AProjectile *Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBluePrint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);
		if (Projectile) {
			Projectile->LaunchProjectile(LaunchSpeed);

			LastFireTime = FPlatformTime::Seconds();
		}
	}
}
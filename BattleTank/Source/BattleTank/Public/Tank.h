// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
//#include "GameFramework/Actor.h"
//#include "TankAimingComponent.h"
#include "Tank.generated.h" // must be last include

// Forward Declaration (ie we ar enot calling methods ?)
class UTankBarrel; 
class UTankTurret;
class UTankAimingComponent;
class UTankMovementComponent;
class AProjectile;


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = Firing) float ReloadTime = 3.0f;
	UPROPERTY(EditDefaultsOnly, Category = Firing) float LaunchSpeed = 4000.f;
	UPROPERTY(EditDefaultsOnly, Category = Setup) TSubclassOf<AProjectile> ProjectileBluePrint;

	UFUNCTION(BlueprintCallable, Category = Setup) void SetBarrelReference(UTankBarrel *BarrelToSet);
	UFUNCTION(BlueprintCallable, Category = Setup) void SetTurretReference(UTankTurret *TurretToSet);

	UFUNCTION(BlueprintCallable, Category = Setup) void Fire();

	

	void AimAt(FVector HitLocation);

protected:
	UTankAimingComponent *TankAimingComponent = nullptr;
	UPROPERTY(BlueprintReadOnly)	UTankMovementComponent *TankMovementComponent = nullptr;
private:	
	ATank();
	UTankBarrel *Barrel = nullptr;	// local barrel for projectiles
	virtual void BeginPlay() override;
	//virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	double LastFireTime = 0;

};

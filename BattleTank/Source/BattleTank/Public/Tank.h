// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
//#include "GameFramework/Actor.h"
//#include "TankAimingComponent.h"
#include "Tank.generated.h" // must be last include

// Forward Declaration (ie we ar enot calling methods ?)
class UTankBarrel; 
class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// TODO tweak LaunchSpeed
	UPROPERTY(EditAnywhere, Category = Firing) float LaunchSpeed = 1000000.0f;
	UFUNCTION(BlueprintCallable, Category = Setup) void SetBarrelReference(UTankBarrel *BarrelToSet);
	void AimAt(FVector HitLocation);

protected:
	UTankAimingComponent *TankAimingComponent = nullptr;

private:	
	ATank();
	virtual void BeginPlay() override;
	//virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
};

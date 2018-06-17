// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
//#include "GameFramework/Actor.h"
#include "TankAimingComponent.h"

#include "Tank.generated.h" // must be last include

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);
	UFUNCTION(BlueprintCallable, Category = Setup) void SetBarrelReference(UStaticMeshComponent *BarrelToSet);

protected:
	UTankAimingComponent *TankAimingComponent = nullptr;

private:	
	ATank();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
};

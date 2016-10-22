// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // generated.h must be the last included	

class ATank;

UCLASS()
class BATTLETANKPROJECT_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank* GetControlledTank() const;

private:	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	//start the tank moving the so that the shot hits where the crosshair intersects the world
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& HitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
	
	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5;
	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.33333;
	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.0;
};

// Copyright Micro Knight Games

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // generated.h must be the last included	

class UTankAimingComponent;

/**
* Responsible for heping the player aim
*/

UCLASS()
class BATTLETANKPROJECT_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimingComponentRef);

	UFUNCTION()
	void OnPossessedTankDeath();

private:	
	void SetPawn(APawn * InPawn);
	
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

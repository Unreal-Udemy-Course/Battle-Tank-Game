// Copyright Micro Knight Games

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // paste new includes above

class UTankBarrel; //Forward declaration
class UTankTurret;
class UTankAimingComponent;
class AProjectile;
class UTankMovementComponent;

UCLASS()
class BATTLETANKPROJECT_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);
	
	UFUNCTION(BlueprintCallable, Category = "Gameplay")	
	void Fire();

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;
	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;
	
private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	// Local barrel reference for spawning projectile 
	UTankBarrel* Barrel = nullptr;
	
	double LastFireTime = 0;
		
};

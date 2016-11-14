// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "AIController.h"
#include "TankAIController.generated.h"

class UTankAimingComponent;

UCLASS()
class BATTLETANKPROJECT_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

private:
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	virtual void SetPawn(APawn* Inpawn) override;

	UFUNCTION()
		void OnPossessedTankDeath();

protected:
	UPROPERTY(EditDefaultsOnly) // How close can AI Tank get to the player
	float AcceptanceRadiance = 8000;
};

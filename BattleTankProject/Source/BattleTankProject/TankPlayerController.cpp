// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankProject.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Player Controller Begin Play"))
		auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
		{
			UE_LOG(LogTemp, Warning, TEXT("Player Controller not Possesing a Tank"));
		}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("Possesed tank is: %s"), *ControlledTank->GetName());
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();

}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	//if we don't have a controlled, tank do nothing
	if (!GetControlledTank()) {return;}
	else
	{
		FVector HitLocation; // OUT Parameter
		if (GetSightRayHitLocation(HitLocation)) //has "side-effect", is going to ray trace
		{
			UE_LOG(LogTemp, Warning, TEXT("Player aiming at:%s"), *HitLocation.ToString());			
			//if it hits something
				//TODO get controlled tank to shoot at point
		}
	}
}

//Get World location by linetracing using the crosshair, return true if we hit something
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//return location as an OUT parameter
	//return true if we hit something, if not false
	HitLocation = FVector(1.0);
	return 1;
}
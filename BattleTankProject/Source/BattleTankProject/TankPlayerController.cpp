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
						
			//if it hits something
				//TODO get controlled tank to shoot at point
		}
	}
}

//Get World location by linetracing using the crosshair, return true if we hit something
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//find the crosshair position in pixel co-ordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeX * CrosshairYLocation);

	// "De-project the screen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *LookDirection.ToString());
	}

	// Line trace along the  loolk direction and see what we hit up to a max range
	return 1;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const
{
	FVector CameraWorldLocation; //To be discarded
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}
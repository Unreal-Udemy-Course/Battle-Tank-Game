// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankProject.h"
#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

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

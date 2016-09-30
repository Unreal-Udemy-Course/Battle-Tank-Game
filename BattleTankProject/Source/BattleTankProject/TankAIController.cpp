// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankProject.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Tank Ai Controller Begin Play"))
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank AI Controller not Possesing a Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank AI Controller possesing: %s"), *ControlledTank->GetName());
	}

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Tank not found."));
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Tank is %s"), *PlayerTank->GetName());
	}
}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (GetPlayerTank())
	{
		//TODO Move towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		//AimAtPlayer();
		//Fire if ready
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) 
	{
		return nullptr;
	}
		return Cast<ATank>(PlayerPawn);
}

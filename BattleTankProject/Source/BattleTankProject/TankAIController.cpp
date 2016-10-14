// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankProject.h"
#include"Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	auto PlayerPawn = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	if (PlayerPawn)
	{
		//TODO Move towards the player

		//Aim at player
		ControlledTank->AimAt(PlayerPawn->GetActorLocation());
		//Fire if ready
		ControlledTank->Fire(); // TODO Limit firing rate
	}
}


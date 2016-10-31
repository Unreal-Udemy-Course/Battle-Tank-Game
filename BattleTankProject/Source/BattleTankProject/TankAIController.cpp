// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankProject.h"
#include "TankAIController.h"
#include "TankAimingComponent.h"

// Depends on movement component via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();
	if (!ensure(PlayerPawn && ControlledTank)) { return; }
	//Move towards the player
	MoveToActor(PlayerPawn, AcceptanceRadiance); // TODO Check radius in cm

	//Aim at player
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerPawn->GetActorLocation());
	
	//Fire if ready
	AimingComponent->Fire(); // TODO Limit firing rate
}


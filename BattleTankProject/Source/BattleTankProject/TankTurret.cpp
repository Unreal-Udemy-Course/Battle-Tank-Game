// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankProject.h"
#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto Rotationchange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto NewRotation = RelativeRotation.Yaw + Rotationchange;
	SetRelativeRotation(FRotator(0, NewRotation, 0));
}



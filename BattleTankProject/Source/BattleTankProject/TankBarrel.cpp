// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankProject.h"
#include "TankBarrel.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{
	// move the barrel closer to the aim direction this frame
	// given max speed, elevation and frame time
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed,-1,1);
	auto Elevationchange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + Elevationchange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation,MinElevation,MaxElevation);
	SetRelativeRotation(FRotator(Elevation,0,0));
}


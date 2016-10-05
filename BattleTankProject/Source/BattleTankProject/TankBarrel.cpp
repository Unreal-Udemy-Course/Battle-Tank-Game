// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankProject.h"
#include "TankBarrel.h"


void UTankBarrel::Elevate(float DegreesPerSecond)
{
	// move the barrel closer to the aim direction this frame
	// given max speed, elevation and frame time
	UE_LOG(LogTemp, Warning, TEXT("Barrel->Elevate() called at speed %f"),DegreesPerSecond);
}


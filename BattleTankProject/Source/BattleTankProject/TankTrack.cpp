// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankProject.h"
#include "TankTrack.h"


void UTankTrack::SetThrottle(float Throttle)
{
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s Throttle: %f"), *Name, Throttle);

	// TODO clamp actual throttle value so player cant make tank faster
}


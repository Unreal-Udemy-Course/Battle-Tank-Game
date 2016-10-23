// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANKPROJECT_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max down movement and +1 is max up movement
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "SetUp")
	float MaxDegreesPerSecond = 10;
	UPROPERTY(EditDefaultsOnly, Category = "SetUp")
	float MaxElevation = 40;
	UPROPERTY(EditDefaultsOnly, Category = "SetUp")
	float MinElevation = 0;

};

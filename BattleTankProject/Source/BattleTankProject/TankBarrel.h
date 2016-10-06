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
	void Elevate(float DegreesPerSecond);
	
private:
	UPROPERTY(EditAnywhere, Category = SetUp)
	float MaxDegreesPerSecond = 10;
	UPROPERTY(EditAnywhere, Category = SetUp)
	float MaxElevation = 40;
	UPROPERTY(EditAnywhere, Category = SetUp)
	float MinElevation = 0;

};

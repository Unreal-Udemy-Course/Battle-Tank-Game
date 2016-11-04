// Copyright Micro Knight Games

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving force and to apply forces to the tank
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANKPROJECT_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

private:
	virtual void BeginPlay() override;
	void ApplySidewaysForce();
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
	
public:
	// Sets a Throttle between -1 and +1
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);

	void DriveTrack();

	// This is max force per track in newtons
	UPROPERTY(EditDefaultsOnly)
	float TankMaxDrivingForce = 400000; // assume 40 tonne tank and 1g acceleration
	
	UTankTrack();

	float CurrentThrottle = 0;

};

// Copyright Micro Knight Games

#include "BattleTankProject.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::BeginPlay()
{
	// So that first fire is after inital reload
	LastFireTime = FPlatformTime::Seconds();
}

void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	if (Ammo < 1 )
	{
		FiringStatus = EFiringStatus::NoAmmo;
	}
	else if ((FPlatformTime::Seconds() - LastFireTime) < ReloadTimeInSeconds)
	{
		FiringStatus = EFiringStatus::Reloading;
	}
	else if (IsBarrelMoving())
	{
		FiringStatus = EFiringStatus::Aiming;
	}
	else
	{
		FiringStatus = EFiringStatus::Locked;
	}
}

void UTankAimingComponent::Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet)
{
	Barrel = BarrelToSet;
	Turret = TurretToSet;
}

EFiringStatus UTankAimingComponent::GetFiringStatus() const
{
	return FiringStatus;
}

int UTankAimingComponent::GetAmmoCount() const
{
	return Ammo;
}

void UTankAimingComponent::AimAt(FVector HitLocation)
{
	if (!ensure(Barrel)) { return; } //protects the from a null barrel pointer
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile")); // We have to construct an FName for the socket as that is the argument type
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace // Parameter must be present to prevent bug
	);
	if (bHaveAimSolution)
	{
		// Calculate the out Launch Velocity
		AimDirection = OutLaunchVelocity.GetSafeNormal();
		auto TankName = GetOwner()->GetName();
		MoveBarrelTowards(AimDirection);
		//auto Time = GetWorld()->GetTimeSeconds();
		//UE_LOG(LogTemp, Warning, TEXT("%f Aim Solution found"), Time);
	}
	else
	{
		//auto Time = GetWorld()->GetTimeSeconds();
		//UE_LOG(LogTemp, Warning, TEXT("%f No Solution found"), Time);
	}
	// if no solution found, do nothing
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	// pointer protection
	if (!ensure(Barrel && Turret)) { return; }
	
	// calculate the difference in rotation between the barrel and the aim direction
	
	auto BarrelRotator = Barrel->GetForwardVector().Rotation(); // get cuurent rotation of turret
	auto AimAsRotator = AimDirection.Rotation(); // get the AimDirection as a Rotation
	auto DeltaRotator = AimAsRotator - BarrelRotator; 
		
	// add rotation adjustment	
	Barrel->Elevate(DeltaRotator.Pitch); 

	// take shortest route
	if (DeltaRotator.Yaw < 180)
	{
		Turret->Rotate(DeltaRotator.Yaw);
	}
	else
	{
		Turret->Rotate(- DeltaRotator.Yaw);
	}
}

void UTankAimingComponent::Fire()
{	
	if (FiringStatus != EFiringStatus::Reloading && Ammo >= 1)
	{
		Ammo -= 1;
		// Spawn a projectile at the socket location on the barrel
		if (!ensure(Barrel)) { return; }
		if (!ensure(ProjectileBlueprint)) { return; }
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}

bool UTankAimingComponent::IsBarrelMoving()
{
	if(!ensure(Barrel)) { return false; }
	if (Barrel->GetForwardVector().Equals(AimDirection, 0.01))
	{
		return false;
	}
	return true;
}

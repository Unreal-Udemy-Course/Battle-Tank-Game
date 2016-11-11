// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class BATTLETANKPROJECT_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void LaunchProjectile(float Speed);	

private:
	void OnTimerExpire();

	UProjectileMovementComponent* ProjectileMovementComponent = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* CollisionComponent = nullptr;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UParticleSystemComponent* ParticleSystemComponent = nullptr;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UParticleSystemComponent* ImpactBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	URadialForceComponent* ExplosionForce = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float DestroyDelay = 10.f;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ProjectileDamage = 10.f;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
	
};

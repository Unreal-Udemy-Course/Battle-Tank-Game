// Copyright Micro Knight Games

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // paste new includes above

UCLASS()
class BATTLETANKPROJECT_API ATank : public APawn
{
	GENERATED_BODY()
	
private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingHealth = 100;

	UPROPERTY(VisibleAnywhere, Category = "Health")
 	int32 CurrentHealth = StartingHealth;

public:
	//called by the engine when actor damage is dealt
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
		
};

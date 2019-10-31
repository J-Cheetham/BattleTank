// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//-1 is the max downward speed and +1 is max upwards speed
	void ElevateBarrel(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreesPerSecond = 20;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxElevation = 30;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MinElevation = 0;
};

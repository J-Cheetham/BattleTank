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
	void ElevateBarrel(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPreSecond = 20;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevation = 30;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevation = 0;
};

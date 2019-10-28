// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	

public:
void RotateTurret(float RelativeSpeed);

private:

UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 20;

//Use below if the rotation needs to have a min and a max

//UPROPERTY(EditAnywhere, Category = Setup)
//	float MaxElevation = 30;
//
//UPROPERTY(EditAnywhere, Category = Setup)
//	float MinElevation = 0;



};

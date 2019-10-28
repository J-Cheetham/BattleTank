// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"

void UTankBarrel::ElevateBarrel(float RelativeSpeed)
{
	//In case the relative speed is outside of the bounds of 1 and -1
	auto ClampedRelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	//Framerate independent
	auto ElevationChange = ClampedRelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto ClampedNewElevation = FMath::Clamp<float>(RawNewElevation, MinElevation, MaxElevation);
	SetRelativeRotation(FRotator(ClampedNewElevation, 0, 0));
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

void UTankTurret::RotateTurret(float RelativeSpeed)
{
	//In case the relative speed is outside of the bounds of 1 and -1
	auto ClampedRelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	//Framerate independent
	auto RotationChange = ClampedRelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;
	//auto ClampedNewRotation = FMath::Clamp<float>(RawNewRotation, MinElevation, MaxElevation);
	SetRelativeRotation(FRotator(RawNewRotation, 0, 0));
}
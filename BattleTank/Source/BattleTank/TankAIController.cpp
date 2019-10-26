// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto AIControlledTank = GetControlledTank();
	if (!AIControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank is not possessed by AI controller"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank AI controller is possessing %s"), *(AIControlledTank->GetName()))
	}
}



ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
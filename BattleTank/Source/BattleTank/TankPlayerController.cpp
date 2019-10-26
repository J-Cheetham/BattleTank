// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControlledTank() const
{
	//Gets the pawn and casts it to the identified ATank
	return Cast<ATank>(GetPawn());
}
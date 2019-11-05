// Fill out your copyright notice in the Description page of Project Settings.


#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	//unit vector showing the direction that the AI tank intends to move
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();

	UE_LOG(LogTemp, Warning, TEXT("AI tank wanting to move in direction: %s"), *AIForwardIntention.ToString())

	//direction the tank is currently facing
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal(); 

	auto ThrowRequired = FVector::DotProduct(TankForward, AIForwardIntention);
	IntendMoveForward(ThrowRequired);
}
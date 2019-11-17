// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "SprungBlock_BP.generated.h"

class UStaticMeshComponent;
class UPhysicsConstraintComponent;
class USphereComponent;

UCLASS()
class BATTLETANK_API ASprungBlock_BP : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASprungBlock_BP();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void AddDrivingForce(float ForceMagnitude);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void SetupConstaint();

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UStaticMeshComponent* Wheel = nullptr;

	//UPROPERTY(VisibleAnywhere, Category = "Components")
	//	USphereComponent* Axle = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UPhysicsConstraintComponent* MassWheelConstraint = nullptr;

	//UPROPERTY(VisibleAnywhere, Category = "Components")
	//	UPhysicsConstraintComponent* AxleWheelConstraint = nullptr;

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	void ApplyForce();

	float TotalForceMagnitudeThisFrame = 0;
};

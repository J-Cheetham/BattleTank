// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:


virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

//Returns current health as a percentage of starting health
UFUNCTION(BlueprintPure, Category = "Health")
float GetHealthPercent() const;

FTankDelegate OnDeath;

private:
ATank();

UPROPERTY(EditDefaultsOnly, Category = "Setup")
int32 StartingHealth = 40;

UPROPERTY(VisibleAnywhere, Category = "Health")
int32 CurrentHealth;

virtual void BeginPlay() override;

};

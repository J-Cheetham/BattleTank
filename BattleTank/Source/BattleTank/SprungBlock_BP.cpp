// Fill out your copyright notice in the Description page of Project Settings.


#include "SprungBlock_BP.h"
#include "Components/StaticMeshComponent.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
ASprungBlock_BP::ASprungBlock_BP()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickGroup = TG_PostPhysics;

	MassWheelConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("MassWheelConstraint"));
	SetRootComponent(MassWheelConstraint);

	Wheel = CreateDefaultSubobject<UStaticMeshComponent>(FName("Wheel"));
	Wheel->SetupAttachment(MassWheelConstraint);
}

// Called when the game starts or when spawned
void ASprungBlock_BP::BeginPlay()
{
	Super::BeginPlay();

	Wheel->SetNotifyRigidBodyCollision(true);
	Wheel->OnComponentHit.AddDynamic(this, &ASprungBlock_BP::OnHit);

	SetupConstaint();
}

// Called every frame
void ASprungBlock_BP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetWorld()->TickGroup == TG_PostPhysics)
	{
		TotalForceMagnitudeThisFrame = 0;
	}
}

void ASprungBlock_BP::SetupConstaint()
{
	if (!GetAttachParentActor()) { return; }
	UPrimitiveComponent* BodyRoot = Cast<UPrimitiveComponent>(GetAttachParentActor()->GetRootComponent());
	if (!BodyRoot) { return; }
	MassWheelConstraint->SetConstrainedComponents(BodyRoot, NAME_None, Wheel, NAME_None);
}

void ASprungBlock_BP::AddDrivingForce(float ForceMagnitude)
{
	TotalForceMagnitudeThisFrame += ForceMagnitude;
}

void ASprungBlock_BP::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	ApplyForce();
}

void ASprungBlock_BP::ApplyForce()
{
	Wheel->AddForce(Wheel->GetForwardVector() * TotalForceMagnitudeThisFrame);
	UE_LOG(LogTemp, Warning, TEXT("Force Applied: %f"), TotalForceMagnitudeThisFrame)
}

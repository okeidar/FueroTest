// Fill out your copyright notice in the Description page of Project Settings.


#include "FaceTargetComponent.h"

#include "Kismet/KismetMathLibrary.h"


UFaceTargetComponent::UFaceTargetComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled=false;	
}

void UFaceTargetComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	const FVector parentLocation = GetOwner()->GetActorLocation();
	const FRotator parentRotation = GetOwner()->GetActorRotation();
	const FVector targetPosition = ActiveTarget->GetActorLocation();

	const FRotator requiredRotation = UKismetMathLibrary::FindLookAtRotation(parentLocation, targetPosition);
	
	GetOwner()->SetActorRotation(UKismetMathLibrary::RInterpTo_Constant(parentRotation,requiredRotation,DeltaTime,RotationRate));	
}

void UFaceTargetComponent::StartRotating(AActor* Target)
{
	ActiveTarget=Target;
	SetComponentTickEnabled(true);
}

void UFaceTargetComponent::StopRotating()
{	
	SetComponentTickEnabled(false);
}

FORCEINLINE bool UFaceTargetComponent::IsRotating() const
{
	return IsComponentTickEnabled();
}


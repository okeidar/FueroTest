// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterComponent.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"


UShooterComponent::UShooterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UShooterComponent::Shoot()
{
	UWorld* const World = GetWorld();	
	if (!World) return;

	//cooldown is setting the time of the next available shot and comparing the game time to it
	float gameTime=UGameplayStatics::GetTimeSeconds(World);
	if(gameTime<NextShotTime) return;

	const FRotator SpawnRotation = GetOwner()->GetActorRotation();
	const FVector SpawnLocation = GetOwner()->GetActorLocation() + SpawnRotation.RotateVector(ShotOriginOffset);

	FActorSpawnParameters ActorSpawnParams;
	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

	World->SpawnActor<ABaseProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);

	NextShotTime=gameTime+CooldownSeconds;
}

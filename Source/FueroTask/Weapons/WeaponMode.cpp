// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponMode.h"

#include "BaseProjectile.h"
#include "Kismet/GameplayStatics.h"


UWeaponMode::UWeaponMode()
{
	PrimaryComponentTick.bCanEverTick = false;	
}

void UWeaponMode::BeginFire_Implementation()
{
	UWorld* const World = GetWorld();
	if (!World ) return;

	//I tend to separate player logic and general logic because they are different types of entities in a broad manner. Generalizing everything usually takes to much effort with little return. so this is a weapon for a player.
	
	const APlayerController* PlayerController = UGameplayStatics::GetPlayerController(World,0);
	const FRotator SpawnRotation = PlayerController->PlayerCameraManager->GetCameraRotation();
	const FVector SpawnLocation = GetOwner()->GetActorLocation() + SpawnRotation.RotateVector(ShotOriginOffset);

	FActorSpawnParameters ActorSpawnParams;
	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

	World->SpawnActor<ABaseProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);	
}

void UWeaponMode::EndFire_Implementation()
{
	//implement in derived types
}


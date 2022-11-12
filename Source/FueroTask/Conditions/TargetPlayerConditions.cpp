// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetPlayerConditions.h"

#include "GameplayTagAssetInterface.h"
#include "Kismet/GameplayStatics.h"


UInPlayerViewportCondition::UInPlayerViewportCondition()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UInPlayerViewportCondition::IsConditionMet(const AActor* context) const
{
	/*
	 * I could have used a dot product+-FOV check between the the player forward and the lookat vector to the target,
	 * but that would have required FOV scaling when using zoom.
	 * I also didnt have time to profile and check whether this is significantly slower, but I dont think it is.
	 */

	const UWorld* const world = GetWorld();
	if (!world) return false;

	const APlayerController* playerController = UGameplayStatics::GetPlayerController(world, 0);
	const FVector ownerLocation = GetOwner()->GetActorLocation();
	int32 viewportX, viewportY;
	FVector2D screenLocation;

	//checking if the owner can be projected on the players screen and that it fits in the viewport	
	playerController->GetViewportSize(viewportX, viewportY);
	const bool bSuccess = playerController->ProjectWorldLocationToScreen(ownerLocation, screenLocation);

	return bSuccess && screenLocation.X >= 0 && screenLocation.X <= viewportX
					&& screenLocation.Y >= 0 && screenLocation.Y <= viewportY;
}


ULOSToTargetCondition::ULOSToTargetCondition()
{
}

bool ULOSToTargetCondition::IsConditionMet(const AActor* context) const
{
	FHitResult hit;
	FCollisionQueryParams traceParams;

	traceParams.AddIgnoredActor(GetOwner());

	bool bHit = GetWorld()->LineTraceSingleByChannel(hit, GetOwner()->GetActorLocation()
														   , context->GetActorLocation(), VisibilityTraceChannel
														   , traceParams);
	return bHit && hit.GetActor() == context;
}


UContextHasGameplayTagCondition::UContextHasGameplayTagCondition()
{
}

bool UContextHasGameplayTagCondition::IsConditionMet(const AActor* context) const
{
	const AController* controller = context->GetInstigatorController();
	if (!controller) { return false; }

	const IGameplayTagAssetInterface* const tagOwner = Cast<IGameplayTagAssetInterface>(controller);
	if (!tagOwner) { return false; }

	return tagOwner->HasMatchingGameplayTag(TagToCheck);
}

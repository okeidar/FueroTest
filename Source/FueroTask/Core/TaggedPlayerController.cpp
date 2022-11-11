// Fill out your copyright notice in the Description page of Project Settings.


#include "TaggedPlayerController.h"

ATaggedPlayerController::ATaggedPlayerController()
{
}

void ATaggedPlayerController::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
	TagContainer=GameplayTags;
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "ToggleVisibilityByTag.h"


UToggleVisibilityByTag::UToggleVisibilityByTag()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UToggleVisibilityByTag::SwitchMode_Implementation(const ESupportedModes NewMode)
{
	const bool IsFps=NewMode== ESupportedModes::ESM_FPS;
	for (const auto FPSComponent : FPSComponents)
	{
		FPSComponent->SetVisibility(IsFps);
	}

	for (const auto TPSComponent : TPSComponents)
	{		
		TPSComponent->SetVisibility(!IsFps);
	}
}

void UToggleVisibilityByTag::BeginPlay()
{
	Super::BeginPlay();

	TArray<UActorComponent*> foundItems = GetOwner()->GetComponentsByTag(USceneComponent::StaticClass(), FPSTagName);
	for (const auto FoundItem : foundItems)
	{
		FPSComponents.Add(Cast<USceneComponent>(FoundItem));
	}
	foundItems =GetOwner()->GetComponentsByTag(USceneComponent::StaticClass(),TPSTagName);
	for (const auto FoundItem : foundItems)
	{
		TPSComponents.Add(Cast<USceneComponent>(FoundItem));
	}
}


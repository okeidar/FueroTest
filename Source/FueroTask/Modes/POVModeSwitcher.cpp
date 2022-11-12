// Fill out your copyright notice in the Description page of Project Settings.


#include "POVModeSwitcher.h"

#include "IModeSwitcher.h"


UPOVModeSwitcher::UPOVModeSwitcher()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UPOVModeSwitcher::SwitchModeToAllObjects(const ESupportedModes NewMode)
{
	if (ParentSupportingObjects.IsEmpty())
	{
		SearchForSupportingObjects();
	}

	for (const auto& ParentSupportingComponent : ParentSupportingObjects)
	{
		if(ParentSupportingComponent)
			IModeSwitcher::Execute_SwitchMode(ParentSupportingComponent,NewMode);
	}
}

void UPOVModeSwitcher::SearchForSupportingObjects()
{
	TArray<UActorComponent*> foundSupportingObjects = GetOwner()->GetComponentsByInterface(UModeSwitcher::StaticClass());
	
	for (const auto& foundSupportingObject : foundSupportingObjects)
	{
		UObject* itemAsObject = Cast<UObject>(foundSupportingObject);
		ParentSupportingObjects.Add(itemAsObject);
	}
	
	TArray<AActor*> attachedActors;
	GetOwner()->GetAttachedActors(attachedActors);
	
	for (const auto& attachedActor : attachedActors)
	{
		if(attachedActor->Implements<UModeSwitcher>())
		{
			UObject* itemAsObject = Cast<UObject>(attachedActor);
			ParentSupportingObjects.Add(itemAsObject);
		}
	}
}

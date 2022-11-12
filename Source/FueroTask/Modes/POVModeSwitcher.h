// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IModeSwitcher.h"
#include "Components/ActorComponent.h"
#include "POVModeSwitcher.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FUEROTASK_API UPOVModeSwitcher : public UActorComponent
{
	GENERATED_BODY()

public:
	
	UPOVModeSwitcher();

	/**
	 * @brief Scans the owner for components and attached actors that implement @IModeSwitcher and calls switch mode on them.
	 * @param NewMode The mode to change to
	 * @warning new components/actors added after the first call will not be accounted.
	 */
	UFUNCTION(BlueprintCallable, Category=ModeSwitch)
	void SwitchModeToAllObjects(const ESupportedModes NewMode);

private:
	
	UPROPERTY()
	TArray<UObject*> ParentSupportingObjects;
	
	/**
	 * @brief Scans the owner for components and attached actors that implement @IModeSwitcher and saves them in a TArray
	 */
	void SearchForSupportingObjects();
};


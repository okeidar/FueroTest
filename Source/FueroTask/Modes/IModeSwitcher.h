// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IModeSwitcher.generated.h"

UENUM(BlueprintType)
enum class ESupportedModes: uint8
{	
	ESM_TPS UMETA(DisplayName = "Third Person POV"),
	ESM_FPS UMETA(DisplayName = "First Person POV")
};

// This class does not need to be modified.
UINTERFACE()
class UModeSwitcher : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FUEROTASK_API IModeSwitcher
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	/**
	 * @brief Switching POV mode
	 * @param NewMode @ESupportedMode mode to switch to
	 */
	UFUNCTION(BlueprintNativeEvent , BlueprintCallable)		
	void SwitchMode(const ESupportedModes NewMode);
};

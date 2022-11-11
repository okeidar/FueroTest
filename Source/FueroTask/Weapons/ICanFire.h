// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ICanFire.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCanFire : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FUEROTASK_API ICanFire
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent , BlueprintCallable)		
	void BeginFire();
	
	UFUNCTION(BlueprintNativeEvent , BlueprintCallable)
	 void EndFire();
};

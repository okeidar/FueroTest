// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ConditionRequirementComponent.generated.h"

/** Base component to implement condition logics over an actor context. */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FUEROTASK_API UConditionRequirementComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = Condition)
	virtual bool IsConditionMet(const AActor* context=nullptr) const ;
	
	
	UConditionRequirementComponent();
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ConditionRequirementComponent.h"
#include "GameplayTagContainer.h"
#include "TargetPlayerConditions.generated.h"


/** Checks if the owner is in the players viewport. */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FUEROTASK_API UInPlayerViewportCondition : public UConditionRequirementComponent
{
	GENERATED_BODY()

public:

	UInPlayerViewportCondition();

	virtual bool IsConditionMet(const AActor* context=nullptr) const override;
};

/** Checks if the owner has LOS to a target. */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FUEROTASK_API ULOSToTargetCondition : public UConditionRequirementComponent
{
	GENERATED_BODY()

public:

	ULOSToTargetCondition();

	virtual bool IsConditionMet(const AActor* context=nullptr) const override;

private:
	
	UPROPERTY(EditAnywhere, Category=Config, meta=(AllowPrivateAccess=true))
	TEnumAsByte<ECollisionChannel> VisibilityTraceChannel = ECC_Visibility;
};


/** Checks if the context has a tag. */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FUEROTASK_API UContextHasGameplayTagCondition : public UConditionRequirementComponent
{
	GENERATED_BODY()

public:

	UContextHasGameplayTagCondition();
	
	virtual bool IsConditionMet(const AActor* context=nullptr) const override;

private:

	UPROPERTY(EditAnywhere, Category=Config, meta=(AllowPrivateAccess=true))
	FGameplayTag TagToCheck;	
};

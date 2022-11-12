// Fill out your copyright notice in the Description page of Project Settings.


#include "ConditionRequirementComponent.h"


UConditionRequirementComponent::UConditionRequirementComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UConditionRequirementComponent::IsConditionMet(const AActor* context) const
{
	return true;
}

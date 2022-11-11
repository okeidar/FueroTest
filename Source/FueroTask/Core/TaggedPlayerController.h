// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagAssetInterface.h"
#include "GameFramework/PlayerController.h"
#include "TaggedPlayerController.generated.h"

/**
 * 
 */
UCLASS(Blueprintable,BlueprintType)
class FUEROTASK_API ATaggedPlayerController : public APlayerController, public IGameplayTagAssetInterface
{
	GENERATED_BODY()
public:
	
	ATaggedPlayerController() ;
	
	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Tags, meta=(AllowPrivateAccess="true"))
	FGameplayTagContainer GameplayTags;
};



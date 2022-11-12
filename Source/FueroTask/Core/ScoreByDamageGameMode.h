// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ScoreByDamageGameMode.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScoreUpdated, int, ScoreValue);

UCLASS(minimalapi, BlueprintType, Blueprintable)
class AScoreByDamageGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	UPROPERTY(BlueprintAssignable, BlueprintCallable, EditAnywhere, Category=Score)
	FOnScoreUpdated OnScoreUpdated;


	AScoreByDamageGameMode();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category=Score)
	FORCEINLINE int GetScore() const { return PlayerScore; }

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category=Score)
	void EnemyDestroyed(const UDamageType* DestroyingDamage);

protected:
	
	UPROPERTY(BlueprintReadWrite, Category=Score)
	int PlayerScore = 0;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FueroTask/Weapons/BaseProjectile.h"
#include "ShooterComponent.generated.h"


UCLASS(ClassGroup=(Custom),Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent))
class FUEROTASK_API UShooterComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, Category = Config)
	TSubclassOf<ABaseProjectile> ProjectileClass=nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
	FVector ShotOriginOffset= FVector {0,0,0};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Config)
	float CooldownSeconds=1.3;


	UShooterComponent();

	UFUNCTION(BlueprintCallable, Category = Shooter)
	void Shoot();

private:
	float NextShotTime = 0;
};

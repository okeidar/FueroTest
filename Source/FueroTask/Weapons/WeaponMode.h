// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ICanFire.h"
#include "Components/ActorComponent.h"
#include "WeaponMode.generated.h"

class ABaseProjectile;

UCLASS(ClassGroup=(Custom),Blueprintable, meta=(BlueprintSpawnableComponent))
class FUEROTASK_API UWeaponMode : public UActorComponent, public ICanFire
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = Config)
	TSubclassOf<ABaseProjectile> ProjectileClass;	

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = Config)
	FVector ShotOriginOffset;

	
	UWeaponMode();	

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void BeginFire();	
	virtual void BeginFire_Implementation() override;
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void EndFire();
	virtual void EndFire_Implementation() override;
};

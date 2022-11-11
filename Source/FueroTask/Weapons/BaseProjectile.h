// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;

UCLASS(Blueprintable,BlueprintType)
class FUEROTASK_API ABaseProjectile : public AActor
{
	GENERATED_BODY()

public:	
	
	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly, Category=Projectile)
	USphereComponent* CollisionComponent = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Movement)
	UProjectileMovementComponent* ProjectileMovement = nullptr;

	/**
	 * @brief Damage type this projectile inflicts.
	 */
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = Config)
	TSubclassOf<UDamageType> DamageType;

	
	ABaseProjectile(const class FObjectInitializer& ObjectInitializer);
	
	UFUNCTION(BlueprintCallable,BlueprintNativeEvent)
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	void OnHit_Implementation(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};

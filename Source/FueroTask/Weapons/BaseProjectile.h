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
	
	ABaseProjectile(const class FObjectInitializer& ObjectInitializer);
	
	UFUNCTION(BlueprintCallable,BlueprintNativeEvent)
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	void OnHit_Implementation(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

private:

	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly, Category=Projectile, meta=(AllowPrivateAccess=true))
	USphereComponent* CollisionComponent = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Movement, meta=(AllowPrivateAccess=true))
	UProjectileMovementComponent* ProjectileMovement = nullptr;

	/** Damage type this projectile inflicts. */ 
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = Config, meta=(AllowPrivateAccess=true))
	TSubclassOf<UDamageType> DamageType;

};

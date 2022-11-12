// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FaceTargetComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FUEROTASK_API UFaceTargetComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UFUNCTION(BlueprintCallable, Category = FaceTarget)
	void StartRotating(AActor* Target);
	
	UFUNCTION(BlueprintCallable, Category = FaceTarget)
	void StopRotating();
	
	UFaceTargetComponent();
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = FaceTarget)
	bool IsRotating() const;
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

private:
	
	UPROPERTY(EditAnywhere, Category = Config, meta=(AllowPrivateAccess=true))
	float RotationRate=20.f;
	
	UPROPERTY()
	AActor* ActiveTarget = nullptr;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IModeSwitcher.h"
#include "Components/ActorComponent.h"
#include "ToggleVisibilityByTag.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FUEROTASK_API UToggleVisibilityByTag : public UActorComponent,public IModeSwitcher
{
	GENERATED_BODY()

public:
	
	/**
	 * @brief Tag to search and activate when switching to FPS mode
	 */
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category=Config)
	FName FPSTagName = FName("FPS");

	/**
	 * @brief Tag to search and activate when switching to TPS mode
	 */
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category=Config)
	FName TPSTagName = FName("TPS");


	UToggleVisibilityByTag();
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SwitchMode(ESupportedModes NewMode);
	virtual void SwitchMode_Implementation(ESupportedModes NewMode) override;
	
protected:
	
	UPROPERTY(Transient)
	TArray<USceneComponent*> FPSComponents;
	
	UPROPERTY(Transient)
	TArray<USceneComponent*> TPSComponents;

	
	virtual void BeginPlay() override;
};

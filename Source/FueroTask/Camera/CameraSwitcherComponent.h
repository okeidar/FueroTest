// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FueroTask/Modes/IModeSwitcher.h"
#include "CameraSwitcherComponent.generated.h"

class UCameraComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FUEROTASK_API UCameraSwitcherComponent : public UActorComponent, public IModeSwitcher
{
	GENERATED_BODY()

public:	

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = Camera)
	 UCameraComponent* ThirdPersonCamera = nullptr;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = Camera)
	 UCameraComponent* FirstPersonCamera = nullptr;

	
	UCameraSwitcherComponent();
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SwitchMode(ESupportedModes NewMode);
	virtual void SwitchMode_Implementation(ESupportedModes NewMode) override;
	
	
	
	virtual void BeginPlay() override;	

		
};


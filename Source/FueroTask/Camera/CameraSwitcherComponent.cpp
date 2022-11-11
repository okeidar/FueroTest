// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraSwitcherComponent.h"

#include "Camera/CameraComponent.h"

UCameraSwitcherComponent::UCameraSwitcherComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UCameraSwitcherComponent::SwitchMode_Implementation(ESupportedModes NewMode)
{	
	if(NewMode==ESM_FPS)
	{
		ThirdPersonCamera->SetActive(false);
		FirstPersonCamera->SetActive(true);
	}
	else
	{
		FirstPersonCamera->SetActive(false);
		ThirdPersonCamera->SetActive(true);
	}
}

void UCameraSwitcherComponent::BeginPlay()
{
	Super::BeginPlay();	
	
	ThirdPersonCamera->SetActive(true);
	FirstPersonCamera->SetActive(false);
}



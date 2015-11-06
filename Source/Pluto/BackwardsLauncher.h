// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "JumpPad.h"
#include "BackwardsLauncher.generated.h"

/**
 * 
 */
UCLASS()
class PLUTO_API ABackwardsLauncher : public AJumpPad
{
	GENERATED_BODY()
	
public:

	virtual void Launch(ACharacter* Character) override;

	
	
};

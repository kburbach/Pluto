// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "JumpPad.h"
#include "Trampoline.generated.h"

/**
 * 
 */
UCLASS()
class PLUTO_API ATrampoline : public AJumpPad
{
	GENERATED_BODY()
	
public:

	virtual void Launch(ACharacter* Character) override;
	
	
};

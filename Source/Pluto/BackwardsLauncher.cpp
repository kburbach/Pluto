// Fill out your copyright notice in the Description page of Project Settings.

#include "Pluto.h"
#include "BackwardsLauncher.h"


void ABackwardsLauncher::Launch(ACharacter* Character){
	FVector currentVelocity = Character->GetVelocity();
	FVector launchVector = FVector(-2 * currentVelocity.X, -2 * currentVelocity.Y, 1000);
	Character->LaunchCharacter(launchVector, false, true);
}


// Fill out your copyright notice in the Description page of Project Settings.

#include "Pluto.h"
#include "Trampoline.h"


void ATrampoline::Launch(ACharacter* Character){
	FVector currentVelocity = Character->GetVelocity();
	FVector launchVector = FVector(-currentVelocity.X, -currentVelocity.Y, -currentVelocity.Z + 1000);
	Character->LaunchCharacter(launchVector, false, false);
}


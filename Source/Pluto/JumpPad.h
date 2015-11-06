// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "JumpPad.generated.h"

UCLASS()
class PLUTO_API AJumpPad : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AJumpPad();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called when this actor overlaps another (but since this actor doesn't move, its effectively called when something walks over it)
	virtual void NotifyActorBeginOverlap( AActor * OtherActor ) override;

	// This launches a Character
	virtual void Launch(ACharacter* Character);
};

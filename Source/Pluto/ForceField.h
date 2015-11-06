// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ForceField.generated.h"

UCLASS()
class PLUTO_API AForceField : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AForceField();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//Determines if the player is within the forcefield, and should therefore be affected
	bool isPlayerInForceField();
	
	//The reference to the player
	ACharacter* player;

	//How far sure this force reach?
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 affectedDistance;

	//How strong is the force? Negative values pull towards, positive values push away
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 force;

	//Normal for the forcefield
	FVector normal;
};

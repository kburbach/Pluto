// Fill out your copyright notice in the Description page of Project Settings.

#include "Pluto.h"
#include "ForceField.h"
#include "DrawDebugHelpers.h"
#include "Engine.h"
#include "PlutoCharacter.h"


// Sets default values
AForceField::AForceField()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//How far should this forcefield reach?
	affectedDistance = 20000; 

	//how strong is the force?
	force = -25;

}

// Called when the game starts or when spawned
void AForceField::BeginPlay()
{
	Super::BeginPlay();

	//Get a reference to the player for later
	player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

}

// Called every frame
void AForceField::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	bool playerInField = isPlayerInForceField();
	if (playerInField){
		//The player is in the field, so act upon them. the value is negative because it should be pulling towards the surface
		player->GetMovementComponent()->Velocity += force * normal;
	}

}

bool AForceField::isPlayerInForceField(){
	//Hit result that line trace will store info in
	FHitResult HitResult(ForceInit);

	//The start vector is the world coordinates of the center of this forcefield actor
	FVector start = GetActorLocation();

	//We want to shoot in the direction of the normal of this forcefield actor
	FRotator rotation = GetActorRotation();
	FVector directionVector = rotation.Vector(); //this is a vector in the direction this actor is facing

	if (directionVector.IsZero()){
		//we funked upd
		UE_LOG(LogTemp, Warning, TEXT("Normal is zero, we funked up"));
		return false;
	}
	normal = directionVector.GetUnsafeNormal();

	//The end vector will be the start vector plus some constant distance in the direction of the normal vector
	FVector endVector = start + affectedDistance * normal;

	//Need to create collision parameters
	FCollisionQueryParams traceParams = FCollisionQueryParams();

	//Run the actual line trace
	bool isHit = GetWorld()->LineTraceSingle(HitResult, start, endVector, traceParams, FCollisionObjectQueryParams(ECC_Pawn)); //saying to trace and look for first "blocking" collision with any World_Static objects, i think...
	DrawDebugLine(GetWorld(), start, endVector, FColor::Blue, true, 1.0F, (uint8)'\000', 5.0f);

	if (isHit){
		//something was hit!
		if (HitResult.GetActor()->IsA(APlutoCharacter::StaticClass())){
			//we hit our character!
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("We hit the character!")));
			return true;
		}
	}

	//either nothing was hit, or whatever was hit was not our guy
	return false;
}


// Fill out your copyright notice in the Description page of Project Settings.

#include "Pluto.h"
#include "JumpPad.h"
#include "PlutoCharacter.h"
#include "DrawDebugHelpers.h"



// Sets default values
AJumpPad::AJumpPad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true; //its just going to sit there so no need to have tick enabled

}

// Called when the game starts or when spawned
void AJumpPad::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AJumpPad::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );


}

void AJumpPad::NotifyActorBeginOverlap(class AActor *OtherActor){
	APlutoCharacter *other = (APlutoCharacter*)(OtherActor);

	//make sure the cast worked
	if (other){
		Launch(other);
	}
	else{
		UE_LOG(LogTemp, Warning, TEXT("Failed cast"));
	}

	//Don't forget to call the super function
	Super::NotifyActorBeginOverlap(OtherActor);
}

void AJumpPad::Launch(ACharacter* Character){
	FVector launchVector = FVector(0, 0, 1000);
	Character->LaunchCharacter(launchVector, false, false);
}

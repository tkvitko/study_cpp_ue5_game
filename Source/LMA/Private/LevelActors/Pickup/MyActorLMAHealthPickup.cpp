// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelActors/Pickup/MyActorLMAHealthPickup.h"

// Sets default values
AMyActorLMAHealthPickup::AMyActorLMAHealthPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActorLMAHealthPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActorLMAHealthPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


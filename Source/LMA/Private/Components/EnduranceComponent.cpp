// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/EnduranceComponent.h"

// Sets default values for this component's properties
UEnduranceComponent::UEnduranceComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

bool UEnduranceComponent::IsEnduranceFull() const
{
	return FMath::IsNearlyEqual(Endurance, MaxEndurance);
}

bool UEnduranceComponent::IsEnduranceEmpty() const
{
	return Endurance <= 0.0f;
}

bool UEnduranceComponent::IncreaseEndurance(float AddingEndurance)
{
	if (IsEnduranceFull()) {
		return false;
	} else {
		Endurance = FMath::Clamp(Endurance + AddingEndurance, 0.0f, MaxEndurance);
		return true;
	}
}

bool UEnduranceComponent::DecreaseEndurance(float TakingEndurance)
{
	if (IsEnduranceEmpty()) {
		return false;
	} else {
		Endurance = FMath::Clamp(Endurance - TakingEndurance, 0.0f, MaxEndurance);
		return true;
	}
}


// Called when the game starts
void UEnduranceComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UEnduranceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


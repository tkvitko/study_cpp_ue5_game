// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnduranceComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LMA_API UEnduranceComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEnduranceComponent();

	UFUNCTION(BlueprintCallable)
	float GetEndurance() const { return Endurance; }
	bool IsEnduranceFull() const;
	bool IsEnduranceEmpty() const;
	bool IncreaseEndurance(float AddingEndurance);
	bool DecreaseEndurance(float TakingEndurance);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float MaxEndurance = 100.0f;

	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	float Endurance = 0.0f;
};

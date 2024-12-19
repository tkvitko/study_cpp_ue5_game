// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LMABaseWeapon.generated.h"


DECLARE_MULTICAST_DELEGATE(FOnClearClipSignature);

USTRUCT(BlueprintType)
struct FAmmoWeapon
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	int32 Bullets;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	int32 Clips;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	bool Infinite;
};

UCLASS()
class LMA_API ALMABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALMABaseWeapon();

	void Fire();
	void ChangeClip();
	void FOnClearClip();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Weapon")
	USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	float TraceDistance = 800.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	FAmmoWeapon DefaultAmmoWeapon{30, 0, true};

	virtual void BeginPlay() override;

	void Shoot();
	void DecrementBullets();
	bool IsCurrentClipEmpty() const;

public:	
	virtual void Tick(float DeltaTime) override;
	FAmmoWeapon GetCurrentAmmoWeapon() const { return CurrentAmmoWeapon; }
	FOnClearClipSignature OnClearClip;
	bool IsCurrentClipFull() const;

private:
	FAmmoWeapon CurrentAmmoWeapon;

};

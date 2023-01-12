// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlatformRotator.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GP4TEAM3_API UPlatformRotator : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlatformRotator();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
	float TimeBetweenRotations = 2.f;

	UPROPERTY(EditAnywhere)
	float RotationTime = 2.f;

	UPROPERTY(EditAnywhere)
	FRotator RotationStep = FRotator(0, 0, 180);

	float WaitTimer = 0.f;

	bool IsRotating = false;

	float TimeSpentRotating = 0.f;

	FRotator FromRotation;
	FRotator ToRotation;
};

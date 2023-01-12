// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlatformMover.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GP4TEAM3_API UPlatformMover : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlatformMover();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
	TArray<FVector> RelativeLocations;

	UPROPERTY(EditAnywhere)
	float TimeBetweenMoving = 1.f;

	UPROPERTY(EditAnywhere)
	float MoveTime = 1.f;

	float WaitTimer = 0.f;

	bool IsMoving = false;

	float TimeSpentMoving = 0.f;

	FVector StartLocation;

	int CurrentIndex = -1;
	FVector FromLocation;
	FVector ToLocation;
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformMover.h"

// Sets default values for this component's properties
UPlatformMover::UPlatformMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlatformMover::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetOwner()->GetActorLocation();
	
}


// Called every frame
void UPlatformMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!IsMoving) 
	{
		WaitTimer += DeltaTime;
		if (WaitTimer >= TimeBetweenMoving && RelativeLocations.Num() >= 2)
		{
			CurrentIndex = (CurrentIndex + 1) % (RelativeLocations.Num() - 1);
			FromLocation = StartLocation + RelativeLocations[CurrentIndex];
			ToLocation = StartLocation + RelativeLocations[CurrentIndex + 1];
			IsMoving = true;
			WaitTimer = 0;
		}
	}

	if (IsMoving) 
	{
		TimeSpentMoving += DeltaTime;
		if (TimeSpentMoving < MoveTime) 
		{
			FVector NewLocation = FMath::Lerp(FromLocation, ToLocation, TimeSpentMoving / MoveTime);
			GetOwner()->SetActorLocation(NewLocation);
		}
		else 
		{
			GetOwner()->SetActorLocation(ToLocation);
			IsMoving = false;
			TimeSpentMoving = 0;
		}
	}
}


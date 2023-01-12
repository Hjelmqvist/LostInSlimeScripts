// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformRotator.h"

// Sets default values for this component's properties
UPlatformRotator::UPlatformRotator()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlatformRotator::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPlatformRotator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!IsRotating)
	{
		WaitTimer += DeltaTime;
		if (WaitTimer >= TimeBetweenRotations)
		{
			FromRotation = GetOwner()->GetActorRotation();
			ToRotation = FromRotation + RotationStep;
			IsRotating = true;
			WaitTimer = 0;
		}
	}

	if (IsRotating) 
	{
		TimeSpentRotating += DeltaTime;
		if (TimeSpentRotating < RotationTime)
		{
			FRotator NewRotation = FMath::Lerp(FromRotation, ToRotation, TimeSpentRotating / RotationTime);
			GetOwner()->SetActorRotation(NewRotation);
		}
		else
		{
			GetOwner()->SetActorRotation(ToRotation);
			IsRotating = false;
			TimeSpentRotating = 0;
		}
	 }
}


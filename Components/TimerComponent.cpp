// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerComponent.h"

// Sets default values for this component's properties
UTimerComponent::UTimerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTimerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTimerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (TimerIsRunning) 
	{
		Time += DeltaTime;
	}
}

FString UTimerComponent::GetFormattedTime()
{
	int Minutes = Time / 60;
	int Seconds = (int)Time % 60;
	const FString FormattedTime = FString::Printf(TEXT("%02d:%02d"), Minutes, Seconds);
	return FormattedTime;
}

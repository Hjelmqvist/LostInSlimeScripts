// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "LevelSelectButtonWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLevelSelectClicked, FName, LevelToStart);

UCLASS()
class GP4TEAM3_API ULevelSelectButtonWidget : public UButton
{
	GENERATED_BODY()

	ULevelSelectButtonWidget();
	
public:
	UPROPERTY()
	FOnLevelSelectClicked OnLevelSelectClicked;

	UFUNCTION()
	void HandleOnClick();

	UPROPERTY(EditAnywhere)
	FName LevelToStart;

	UPROPERTY(EditAnywhere)
	bool BroadcastEvent = true;
};

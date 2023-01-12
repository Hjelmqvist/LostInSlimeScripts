// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LevelSelectWidget.generated.h"

class ULevelSelectButtonWidget;

UCLASS()
class GP4TEAM3_API ULevelSelectWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void NativeConstruct() override;

	UFUNCTION(BlueprintImplementableEvent)
	TArray<ULevelSelectButtonWidget*> GetLevelButtons();

	UFUNCTION(BlueprintImplementableEvent)
	void StartLevel(FName LevelToStart);

	UFUNCTION(BlueprintCallable)
	void LockAllLevels();

	UFUNCTION(BlueprintCallable)
	void UnlockLevels(int LastLevelIndex);

	UFUNCTION(BlueprintCallable)
	void UnlockAllLevels();

private:
	UFUNCTION()
	void HandleLevelButtonClicked(FName LevelToLoad);

	UPROPERTY()
	TArray<ULevelSelectButtonWidget*> LevelButtons;
};
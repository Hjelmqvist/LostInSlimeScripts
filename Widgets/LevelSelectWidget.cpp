// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelSelectWidget.h"
#include "Components/Button.h"
#include "LevelSelectButtonWidget.h"

void ULevelSelectWidget::NativeConstruct()
{
	LevelButtons = GetLevelButtons();

	for (auto Button : LevelButtons) 
	{
		Button->OnLevelSelectClicked.AddDynamic(this, &ULevelSelectWidget::HandleLevelButtonClicked);
	}

	Super::NativeConstruct();
}

void ULevelSelectWidget::LockAllLevels()
{
	for (size_t i = 1; i < LevelButtons.Num(); i++)
	{
		LevelButtons[i]->SetIsEnabled(false);
	}
}

void ULevelSelectWidget::UnlockLevels(int LastLevelIndex)
{
	if (LastLevelIndex < 0)
	{
		return;
	}

	for (size_t i = 1; i <= LastLevelIndex && i < LevelButtons.Num(); i++)
	{
		LevelButtons[i]->SetIsEnabled(true);
	}
}

void ULevelSelectWidget::UnlockAllLevels()
{
	for (auto LevelButton : LevelButtons) 
	{
		LevelButton->SetIsEnabled(true);
	}
}

void ULevelSelectWidget::HandleLevelButtonClicked(FName LevelToLoad)
{
	StartLevel(LevelToLoad);
}

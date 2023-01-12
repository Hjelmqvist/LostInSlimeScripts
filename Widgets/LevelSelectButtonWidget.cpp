// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelSelectButtonWidget.h"

ULevelSelectButtonWidget::ULevelSelectButtonWidget()
{
	OnClicked.AddDynamic(this, &ULevelSelectButtonWidget::HandleOnClick);
}

void ULevelSelectButtonWidget::HandleOnClick()
{
	if (BroadcastEvent) 
	{
		OnLevelSelectClicked.Broadcast(LevelToStart);
	}
}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OptionsWidget.generated.h"

class UCheckBox;
class UComboBoxString;
class USlider;

UCLASS()
class GP4TEAM3_API UOptionsWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void NativeConstruct() override;

	UFUNCTION(BlueprintImplementableEvent)
	UComboBoxString* GetFullscreenDropdown();

	UFUNCTION(BlueprintImplementableEvent)
	UComboBoxString* GetResolutionDropdown();

	UFUNCTION(BlueprintImplementableEvent)
	UComboBoxString* GetQualityDropdown();

private:
	void SetupFullscreenDropdown(UComboBoxString* FullscreenDropdown);

	void SetupResolutionDropdown(UComboBoxString* ResolutionDropdown);

	void SetupQualityDropdown(UComboBoxString* QualityDropdown);

	UFUNCTION()
	void HandleFullscreenChange(FString SelectedItem, ESelectInfo::Type SelectionType);

	UFUNCTION()
	void HandleResolutionChange(FString SelectedItem, ESelectInfo::Type SelectionType);

	UFUNCTION()
	void HandleQualityChange(FString SelectedItem, ESelectInfo::Type SelectionType);

	UPROPERTY()
	UGameUserSettings* Settings;

	TArray<FIntPoint> Resolutions;
};

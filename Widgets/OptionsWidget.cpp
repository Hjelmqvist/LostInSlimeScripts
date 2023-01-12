// Fill out your copyright notice in the Description page of Project Settings.


#include "OptionsWidget.h"
#include "Components/ComboBoxString.h"
#include "GameFramework/GameUserSettings.h"
#include <Kismet/KismetSystemLibrary.h>

void UOptionsWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Settings = GEngine->GameUserSettings;

	SetupFullscreenDropdown(GetFullscreenDropdown());
	SetupResolutionDropdown(GetResolutionDropdown());
	SetupQualityDropdown(GetQualityDropdown());
}

void UOptionsWidget::SetupFullscreenDropdown(UComboBoxString* FullscreenDropdown)
{
	EWindowMode::Type FullscreenMode = Settings->GetFullscreenMode();
	GetFullscreenDropdown()->SetSelectedIndex((int)FullscreenMode);
	FullscreenDropdown->OnSelectionChanged.AddDynamic(this, &UOptionsWidget::HandleFullscreenChange);
}

void UOptionsWidget::SetupResolutionDropdown(UComboBoxString* ResolutionDropdown)
{
	//Load resolution options
	ResolutionDropdown->ClearOptions();
	UKismetSystemLibrary::GetSupportedFullscreenResolutions(Resolutions);
	FString OptionText;

	for (auto Resolution : Resolutions) 
	{
		OptionText = FString::Printf(TEXT("%i : %i"), Resolution.X, Resolution.Y);
		ResolutionDropdown->AddOption(OptionText);
	}

	//Set current resolution in dropdown
	FIntPoint Resolution = Settings->GetScreenResolution();
	ResolutionDropdown->SetSelectedOption(FString::Printf(TEXT("%i : %i"), Resolution.X, Resolution.Y));

	ResolutionDropdown->OnSelectionChanged.AddDynamic(this, &UOptionsWidget::HandleResolutionChange);
}

void UOptionsWidget::SetupQualityDropdown(UComboBoxString* QualityDropdown)
{
	QualityDropdown->SetSelectedIndex(Settings->GetOverallScalabilityLevel());
	QualityDropdown->OnSelectionChanged.AddDynamic(this, &UOptionsWidget::HandleQualityChange);
}

void UOptionsWidget::HandleFullscreenChange(FString SelectedItem, ESelectInfo::Type SelectionType)
{
	EWindowMode::Type FullscreenMode = EWindowMode::ConvertIntToWindowMode(GetFullscreenDropdown()->GetSelectedIndex());
	Settings->SetFullscreenMode(FullscreenMode);
	Settings->ApplySettings(false);
}

void UOptionsWidget::HandleResolutionChange(FString SelectedItem, ESelectInfo::Type SelectionType)
{
	FIntPoint NewResolution = Resolutions[GetResolutionDropdown()->GetSelectedIndex()];
	Settings->SetScreenResolution(NewResolution);
	Settings->ApplyResolutionSettings(false);
}

void UOptionsWidget::HandleQualityChange(FString SelectedItem, ESelectInfo::Type SelectionType)
{
	Settings->SetOverallScalabilityLevel(GetQualityDropdown()->GetSelectedIndex());
	Settings->ApplyHardwareBenchmarkResults();
}
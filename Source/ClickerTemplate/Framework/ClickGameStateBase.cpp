// Fill out your copyright notice in the Description page of Project Settings.


#include "ClickGameStateBase.h"

AClickGameStateBase::AClickGameStateBase()
{
	// Get the item data table for the upgrade items
	static ConstructorHelpers::FObjectFinder<UDataTable> UpgradeTableObject(TEXT("DataTable'/Game/Tables/BP_UpgradeInfoTable.BP_UpgradeInfoTable'"));
	if (UpgradeTableObject.Succeeded())
	{
		UpgradeInfoTable = UpgradeTableObject.Object;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to get Upgrade Info Table in Game State Base"))
	}
	
	// Get the item data table for the multiplication items
	static ConstructorHelpers::FObjectFinder<UDataTable> MultiplicationTableObject(TEXT("DataTable'/Game/Tables/BP_MultiplicationInfoTable.BP_MultiplicationInfoTable'"));
	if (MultiplicationTableObject.Succeeded())
	{
		MultiplicationInfoTable = MultiplicationTableObject.Object;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to get Multiplication Info Table in Game State Base"))
	}

	// Sets the default values for this item
	DefaultClickValue = 1.0f;
	DefaultAutomaticValue = 0.f;
	DefaultMultiplier = 0.f;
}

void AClickGameStateBase::BeginPlay()
{
	Super::BeginPlay();

	// TODO If a save file, load this instead
	CurrentClickValue = DefaultClickValue;
	CurrentAutomaticClicks = DefaultAutomaticValue;
	CurrentMultiplier = DefaultMultiplier;
	
}

void AClickGameStateBase::DealWithButtonClick(bool AddManualIn, EUpgradeTypes UpgradeTypeIn, EMultiplicationTypes MultiplicationTypeIn)
{
	if (AddManualIn)
	{
		// Add the current click value to the total
		CurrentTotal += CurrentClickValue;
		// Reset the timer for automatic updating
		CurrentUpdateTime = 0.f;
		// Call the update screen function
		CurrentTotalUpdated();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AddManualIn is %s"), AddManualIn ? TEXT("true") : TEXT("false"));
		const FString UpgradeType = UEnum::GetDisplayValueAsText(UpgradeTypeIn).ToString();
		UE_LOG(LogTemp, Warning, TEXT("UpgradeTypeIn is %s"), *UpgradeType);
		const FString MultiplicationType = UEnum::GetDisplayValueAsText(MultiplicationTypeIn).ToString();
		UE_LOG(LogTemp, Warning, TEXT("MultiplicationTypeIn is %s"), *MultiplicationType);

	}
	
}

void AClickGameStateBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentAutomaticClicks > 0)
	{
		CurrentTotal += (CurrentAutomaticClicks * CurrentMultiplier) *DeltaTime;
		CurrentUpdateTime += DeltaTime;

		if (CurrentUpdateTime > TimeBetweenUpdates)
		{
			CurrentUpdateTime = 0.f;
			CurrentTotalUpdated();
		}
	}


}

void AClickGameStateBase::CurrentTotalUpdated() const
{
	const int32 TotalAsInt = FMath::RoundHalfToZero(CurrentTotal);
	const FString TotalAsString = FString::FromInt(TotalAsInt) + TEXT("m/s");
	const FText TotalAsText = FText::FromString(TotalAsString);
	OnUpdateCurrentTotal.Broadcast(TotalAsText);
}

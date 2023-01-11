// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ClickerTemplate/ClickerBlueprintFunctionLibrary.h"
#include "GameFramework/GameStateBase.h"
#include "ClickGameStateBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUpdateCurrentTotal, FText, NewTotalValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUpdateAutomatic, FText, NewAutoValue);

USTRUCT(BlueprintType)
struct FAdvancesInUse
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Set Up")
	EUpgradeTypes UpgradeTypes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Set Up")
	int32 NumberInPlay;

	// Taken from Data table
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Set Up")
	float ValuePerAdvancedItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Set Up")
	int32 AdvanceMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Set Up")
	float TotalValuePerSecond;

	FAdvancesInUse()
	{
		UpgradeTypes = EUpgradeTypes::UpgradeType0;
		NumberInPlay = 0;
		ValuePerAdvancedItem = 0.f;
		AdvanceMultiplier = 0;
		TotalValuePerSecond = 0.f;
	}

};

/**
 * 
 */
UCLASS()
class CLICKERTEMPLATE_API AClickGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

	AClickGameStateBase();

public:
	// The default value each time the player clicks the mouse button
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Set Up")
	float DefaultClickValue;

	// The default value for automatic additions to the click
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Set Up")
	float DefaultAutomaticValue;

	// The default value for the multiplier
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Set Up")
	float DefaultMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Set Up")
	TArray<FAdvancesInUse> AdvancesInUse;
	
	virtual void BeginPlay() override;

	void DealWithButtonClick(bool AddManualIn, EUpgradeTypes UpgradeTypeIn, EMultiplicationTypes MultiplicationTypeIn);

	// Specific Struct info for this item based on entry that matches row in ThisItemInfo
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item Info")
	UDataTable* UpgradeInfoTable;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item Info")
	UDataTable* MultiplicationInfoTable;
	
	virtual void Tick(float DeltaTime) override;

	// Time in seconds in between the current total automatically updating
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Set Up")
	float TimeBetweenUpdates;
	
	UPROPERTY(BlueprintAssignable, Category = "Delegates")
	FOnUpdateCurrentTotal OnUpdateCurrentTotal;

	UPROPERTY(BlueprintAssignable, Category = "Delegates")
	FOnUpdateAutomatic OnUpdateAutomatic;

private:
	float CurrentUpdateTime;

	float CurrentAutomaticClicks;
	float CurrentMultiplier;	

	float CurrentClickValue;

	float CurrentTotal;

	void CurrentTotalUpdated() const;
};

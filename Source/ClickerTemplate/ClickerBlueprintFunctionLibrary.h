// Copyright 2023 DME Games.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ClickerBlueprintFunctionLibrary.generated.h"

UENUM(BlueprintType)
enum class EUpgradeTypes : uint8
{
	UpgradeType0		UMETA(DisplayName = "Engineers"),
	UpgradeType1		UMETA(DisplayName = "Nanobots"),
	UpgradeType2		UMETA(DisplayName = "Repair Crews"),
	UpgradeType3		UMETA(DisplayName = "Chief Engineers"),
	UpgradeType4		UMETA(DisplayName = "Androids"),	
	UpgradeType5		UMETA(DisplayName = "Automated Repair Systems"),
	UpgradeType6		UMETA(DisplayName = "Starbases"),
	UpgradeType7		UMETA(DisplayName = "Science Officers"),
	UpgradeType8		UMETA(DisplayName = "Senior Staff"),
	UpgradeType9		UMETA(DisplayName = "Captains"),
	UpgradeTypeNone		UMETA(DisplayName = "None")
};

UENUM(BlueprintType)
enum class EMultiplicationTypes : uint8
{
	MultiplicationTypeUpgrade	UMETA(DisplayName = "Upgrade"),	
	MultiplicationTypeNone		UMETA(DisplayName = "None")
};

USTRUCT(BlueprintType)
struct FUpgradeItemInfo : public FTableRowBase
{
	GENERATED_BODY()

	// The name of this item
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table")
	EUpgradeTypes ObjectType;

	// A brief description of this item
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table")
	FText ObjectDescription;

	// Image to display as an icon
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table")
	UTexture2D* ObjectIconImage;

	// Base number of automatic clicks per second this item adds
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table")
	float BaseItemEffect = 1.0f;

	// Base Cost for this item
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table")
	float BaseItemCost;

                // Multiplication cost for level 2
                UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table")
                float Level02Multiplication = 2.0f;

                // Multiplication cost for level 3
                UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table")
                float Level03Multiplication = 3.0f;

                // Multiplication cost for level 4
                UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table")
                float Level04Multiplication = 4.0f;

                // Multiplication cost for level 5
                UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table")
                float Level05Multiplication = 5.0f;

                // Multiplication cost for level 6
                UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table")
                float Level06Multiplication = 6.0f;

                // Multiplication cost for level 7
                UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table")
                float Level07Multiplication = 7.0f;

                // Multiplication cost for level 8
                UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table")
                float Level08Multiplication = 8.0f;

                // Multiplication cost for level 9
                UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table")
                float Level09Multiplication = 9.0f;

                // Multiplication cost for level 10
                UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table")
                float Level10Multiplication = 10.0f;

                // Multiplication cost for level 11
                UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table")
                float Level11Multiplication = 11.0f;

                // Multiplication cost for level 12
                UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table")
                float Level12Multiplication = 12.0f;

                // Multiplication cost for level 13
                UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table")
                float Level13Multiplication = 13.0f;

                // Multiplication cost for level 14
                UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table")
                float Level14Multiplication = 14.0f;

                // Multiplication cost for level 15
                UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table")
                float Level15Multiplication = 15.0f;

                // Multiplication cost for level 16
                UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table")
                float Level16Multiplication = 16.0f;

                // Multiplication cost for level 17
                UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table")
                float Level17Multiplication = 17.0f;

                // Multiplication cost for level 18
                UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table")
                float Level18Multiplication = 18.0f;

                // Multiplication cost for level 19
                UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table")
                float Level19Multiplication = 19.0f;

                // Multiplication cost for level 20
                UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table")
                float Level20Multiplication = 20.0f;

                // Multiplication cost for level 21 And Above
                UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table")
                float LevelAbove20Multiplication = 21.0f;

	// Whether this item is locked at game start by another item or just needs sufficient "coins"
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table")
	bool bIsLockedByAnother;

	// If locked, which item unlocks it
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table", meta = (EditCondition="bIsLockedByAnother"))
	EUpgradeTypes ObjectTypeThatUnlocks;

	// If locked, how many of the item that unlocks it must be purchased before this item is unlocked
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table", meta = (EditCondition="bIsLockedByAnother"))
	int32 NumOfObjectsNeeded = 1;
};

USTRUCT(BlueprintType)
struct FMultiplierItemInfo : public FTableRowBase
{
	GENERATED_BODY()

	// The name of this item
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table")
	FText ObjectName;

	// A brief description of this item
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table")
	FText ObjectDescription;

	// Image to display as an icon
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table")
	UTexture2D* ObjectIconImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table")
	EMultiplicationTypes TypeOfMultiplication;
	
	// Which item, found in the Upgrade Item Info Table does this multiply
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table", meta = (EditCondition="TypeOfMultiplication==EMultiplcationTypes::MultiplicationTypeUpgrade"))
	EUpgradeTypes TypeThisMultiplies;
	
	// Base number of automatic clicks per second this item adds
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table")
	float BaseItemEffect = 2.0f;

	// Base Cost for this item
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table")
	float BaseItemCost;
	
	// Whether this item is locked at game start by another item or just needs sufficient "coins"
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table")
	bool bIsLockedByAnother;

	// If locked, which item unlocks it
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table", meta = (EditCondition="bIsLockedByAnother"))
	EUpgradeTypes ObjectTypeThatUnlocks;

	// If locked, how many of the item that unlocks it must be purchased before this item is unlocked
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Table", meta = (EditCondition="bIsLockedByAnother"))
	int32 NumOfObjectsNeeded = 1;
};


/**
 * 
 */
UCLASS()
class CLICKERTEMPLATE_API UClickerBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
};

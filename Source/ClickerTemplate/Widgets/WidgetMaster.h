// Copyright 2023 DME Games.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "../ClickerBlueprintFunctionLibrary.h"
#include "WidgetMaster.generated.h"

/**
 * 
 */
UCLASS()
class CLICKERTEMPLATE_API UWidgetMaster : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual bool Initialize() override;

	// Sets default values for this component's properties
	UWidgetMaster(const FObjectInitializer& ObjectInitializer);
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Framework")
	class AClickGameStateBase* GameStateRef;

	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void ButtonClicked();

	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void AddManualClick();

	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void AddUpgradeItem();

	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void AddNewToMultiplier(float MultiplierIn);

	// Type that this item is, to be used with the data table
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info")
	EUpgradeTypes UpgradeType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info")
	EMultiplicationTypes MultiplicationType;
/*	
	// Specific Struct info for this item based on entry that matches row in ThisItemInfo
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item Info")
	UDataTable* UpgradeInfoTable;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item Info")
	UDataTable* MultiplicationInfoTable;
*/	
private:
	bool bAddManualClick;
	EUpgradeTypes UpgradeButtonPressed;
	EMultiplicationTypes MultiplicationButtonPressed;

	int32 CurrentItemLevel;
};

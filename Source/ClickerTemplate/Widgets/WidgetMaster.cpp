// Copyright 2023 DME Games.


#include "WidgetMaster.h"
#include "ClickerTemplate/Framework/ClickGameStateBase.h"


UWidgetMaster::UWidgetMaster(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{
	// Get the item data table for the upgrade items
/*	static ConstructorHelpers::FObjectFinder<UDataTable> UpgradeTableObject(TEXT("DataTable'/Game/Tables/BP_UpgradeInfoTable.BP_UpgradeInfoTable'"));
	if (UpgradeTableObject.Succeeded())
	{
		UpgradeInfoTable = UpgradeTableObject.Object;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to get Upgrade Info Table in Widget Master"))
	}
	
	// Get the item data table for the multiplication items
	static ConstructorHelpers::FObjectFinder<UDataTable> MultiplicationTableObject(TEXT("DataTable'/Game/Tables/BP_MultiplicationInfoTable.BP_MultiplicationInfoTable'"));
	if (MultiplicationTableObject.Succeeded())
	{
		MultiplicationInfoTable = MultiplicationTableObject.Object;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to get Multiplication Info Table in Widget Master"))
	}
*/
}

bool UWidgetMaster::Initialize()
{
	Super::Initialize();

	// Get the Game State Reference for calling functions on it
	GameStateRef = Cast<AClickGameStateBase>(GetWorld()->GetGameState());
	
	// TODO sort out save and load up 
	CurrentItemLevel = 0;
	
	return true;
}




void UWidgetMaster::ButtonClicked()
{
	if (GameStateRef)
	{
		GameStateRef->DealWithButtonClick(bAddManualClick, UpgradeButtonPressed, MultiplicationButtonPressed);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("GameStateRef doesn't exist in %s"), *GetName());
	}
}

void UWidgetMaster::AddManualClick()
{
	bAddManualClick = true;
	UpgradeButtonPressed = EUpgradeTypes::UpgradeTypeNone;
	MultiplicationButtonPressed = EMultiplicationTypes::MultiplicationTypeNone;

	ButtonClicked();
}

void UWidgetMaster::AddUpgradeItem()
{
	bAddManualClick = false;
	UpgradeButtonPressed = UpgradeType;
	MultiplicationButtonPressed = EMultiplicationTypes::MultiplicationTypeNone;

	ButtonClicked();
}

void UWidgetMaster::AddNewToMultiplier(float MultiplierIn)
{
	bAddManualClick = false;
	UpgradeButtonPressed = EUpgradeTypes::UpgradeTypeNone;
	MultiplicationButtonPressed = MultiplicationType;

	ButtonClicked();
}


// Copyright 2023 DME Games.


#include "ClickPlayerController.h"
#include "ClickerTemplate/Widgets/WidgetMaster.h"

void AClickPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (WidgetToDisplay)
	{
		UUserWidget* WidgetInstance = CreateWidget(this, WidgetToDisplay);
		WidgetInstance->AddToViewport();
		FInputModeUIOnly Mode;
		Mode.SetWidgetToFocus(WidgetInstance->GetCachedWidget());
		SetInputMode(Mode);
		bShowMouseCursor = true;
		
	}

}

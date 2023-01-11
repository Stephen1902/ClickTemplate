// Copyright 2023 DME Games.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ClickPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CLICKERTEMPLATE_API AClickPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	
protected:
	// Widget to draw on screen when the game starts
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Widgets")
	TSubclassOf<class UWidgetMaster> WidgetToDisplay;
};

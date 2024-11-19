// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/SCUserWidget.h"
#include "SCInventory.generated.h"

class USCItemContainerGrid;
/**
 * 
 */
UCLASS()
class SURVIVALCRAFT_API USCInventory : public USCUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,meta=(BindWidget))
	TObjectPtr<USCItemContainerGrid> WBP_ItemContainerGrid;
	
};

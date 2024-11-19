// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/SCUserWidget.h"
#include "SCHotBar.generated.h"

class USCItemContainerGrid;
/**
 * 
 */
UCLASS()
class SURVIVALCRAFT_API USCHotBar : public USCUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,meta=(BindWidget))
	TObjectPtr<USCItemContainerGrid> WBP_ItemContainerGrid;
	
};

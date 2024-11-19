// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/SCUserWidget.h"
#include "SCMainHUD.generated.h"

class USCHotBar;
class USCInventory;
/**
 * 
 */
UCLASS()
class SURVIVALCRAFT_API USCMainHUD : public USCUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable,Client,Unreliable)
	void ToggleInventoryVisibility();

	UPROPERTY(VisibleAnywhere,meta=(BindWidget))
	TObjectPtr<USCInventory> WBP_Inventory;

	UPROPERTY(VisibleAnywhere,meta=(BindWidget))
	TObjectPtr<USCHotBar> WBP_HotBar;
	

public:
	UPROPERTY(BlueprintReadOnly)
	bool InventoryVisibility=false;
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SCMainHUD.h"

#include "SCInventory.h"


void USCMainHUD::ToggleInventoryVisibility_Implementation()
{
	InventoryVisibility = !InventoryVisibility;
	if (InventoryVisibility)
	{
		WBP_Inventory->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		WBP_Inventory->SetVisibility(ESlateVisibility::Hidden);
	}
}

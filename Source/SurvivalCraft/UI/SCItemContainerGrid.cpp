// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SCItemContainerGrid.h"

#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"


void USCItemContainerGrid::AddSlots(int Amount)
{
	if (SlotsPerRow <= 0)
	{
		UE_LOG(LogTemp,Warning,TEXT("SlotsPerRow must not zero!"));
		return;
	}
	for (int i = 0; i < Amount; i++)
	{
		if(USCUserWidget* InventorySlot= Cast<USCUserWidget>(CreateWidget<UUserWidget>(this,InventorySlotClass)))
		{
			Slots.Add(InventorySlot);
			AddSlotToGrid(i, InventorySlot);
		}
	}
}

void USCItemContainerGrid::AddSlotToGrid(int SlotIndex, USCUserWidget* InSlot)
{
	if(UUniformGridSlot* OutSlot= ItemGrid->AddChildToUniformGrid(InSlot))
	{
		int RowIndex= SlotIndex/SlotsPerRow;
		int ColIndex= SlotIndex%SlotsPerRow;
		OutSlot->SetRow(RowIndex);
		OutSlot->SetColumn(ColIndex);
	}
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "SCPlayerController.h"

#include "Blueprint/UserWidget.h"
#include "Interfaces/SCCharacter.h"
#include "Item/SCItemType.h"
#include "UI/SCHotBar.h"
#include "UI/SCInventory.h"
#include "UI/SCInventorySlot.h"
#include "UI/SCItemContainerGrid.h"
#include "UI/SCMainHUD.h"

void ASCPlayerController::BeginPlay()
{
	Super::BeginPlay();

	checkf(MainHudClass,TEXT("Player controller must set MainHudClass"));

	if(!HasAuthority())
	{
		if(UUserWidget* MainHUDWidget= CreateWidget<UUserWidget>(this,MainHudClass))
		{
			SCMainHUD=Cast<USCMainHUD>(MainHUDWidget);
			MainHUDWidget->AddToViewport();
		}
	}
	

	
}

/**
 * 在UI上更新指定插槽的物品信息
 * @param TargetContainer 
 * @param SlotIndex 
 * @param InventoryItemInfo 
 */
void ASCPlayerController::UpdateItemSlot_Implementation(ESCContainerType TargetContainer, int SlotIndex,
                                                        FSCItemInfo InventoryItemInfo)
{
	USCInventorySlot* TheSlot=nullptr;
	switch (TargetContainer)
	{
	case PlayerInventory:
		TheSlot=Cast<USCInventorySlot>(SCMainHUD->WBP_Inventory->WBP_ItemContainerGrid->Slots[SlotIndex]);
		break;
	case PlayerHotbar:
		TheSlot=Cast<USCInventorySlot>(SCMainHUD->WBP_HotBar->WBP_ItemContainerGrid->Slots[SlotIndex]);
		break;
	default:
		break;
	}
	 if(TheSlot)
	 {
		 TheSlot->UpdateSlotInfo(SlotIndex, InventoryItemInfo);
	 }
}

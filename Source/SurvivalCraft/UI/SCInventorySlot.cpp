// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SCInventorySlot.h"

#include "SCDragDropOperation.h"
#include "SCInventorySlotDrag.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/Border.h"
#include "Components/TextBlock.h"
#include "Item/SCItemType.h"
#include "Kismet/KismetMathLibrary.h"

#define LOCTEXT_NAMESPACE "SCInventorySlot"


void USCInventorySlot::UpdateSlotInfo(int InSlotIndex,const FSCItemInfo& InItemInfo)
{
	SlotHasItem=true;
	ItemInfo=InItemInfo;
	SlotIndex=InSlotIndex;
	
	ItemIcon->SetBrushFromTexture(ItemInfo.ItemIcon);
	ItemIcon->SetVisibility(ESlateVisibility::Visible);
	
	ItemQuantity->SetText(FText::FormatNamed(LOCTEXT("ItemQuantity", "x{ItemQuantity}"),
		TEXT("ItemQuantity"),ItemInfo.ItemQuantity));
	ItemQuantity->SetVisibility(ESlateVisibility::Visible);
}

FReply USCInventorySlot::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	return  UWidgetBlueprintLibrary::DetectDragIfPressed(InMouseEvent,this,EKeys::LeftMouseButton).NativeReply;
}

void USCInventorySlot::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent,
	UDragDropOperation*& OutOperation)
{
	Super::NativeOnDragDetected(InGeometry, InMouseEvent, OutOperation);
	if (SlotHasItem)
	{
		if(USCInventorySlotDrag* SlotDrag= CreateWidget<USCInventorySlotDrag>(this,SlotDragClass))
		{
			SlotDrag->IconImage=ItemInfo.ItemIcon;
			SlotDrag->ItemInfo=ItemInfo;
			SlotDrag->Init();
			if(USCDragDropOperation* DragOperation=Cast<USCDragDropOperation>(UWidgetBlueprintLibrary::CreateDragDropOperation(DragDropOperationClass)))
			{
				DragOperation->SlotIndex=SlotIndex;
				DragOperation->ContainerType=ESCContainerType::PlayerInventory;
				DragOperation->ItemType=ESCItemType::Resource;
				DragOperation->ArmorType=ESCArmorType::Helmet;
				DragOperation->DefaultDragVisual=SlotDrag;
				DragOperation->ItemInfo=ItemInfo;

				OutOperation=DragOperation;
			}
		}
	}
	
}

bool USCInventorySlot::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent,
	UDragDropOperation* InOperation)
{
	USCDragDropOperation* DragDropOperation=Cast<USCDragDropOperation>(InOperation);
	FSCItemInfo TheItemInfo= DragDropOperation->ItemInfo;
	UE_LOG(LogTemp,Warning,TEXT("NativeOnDrop:%s"),*TheItemInfo.ItemName.ToString()) ;

	//清除原始插槽物品
	
	
	//生成新的插槽物品

	//交换位置
	if (SlotHasItem)
	{
		
	}
	

	
	
	//TODO...
	return Super::NativeOnDrop(InGeometry, InDragDropEvent, InOperation);
}


#undef LOCTEXT_NAMESPACE

// Fill out your copyright notice in the Description page of Project Settings.


#include "SCItemContainer.h"

#include "SCItemType.h"
#include "Character/SurvivalCraftCharacter.h"
#include "Player/SCPlayerController.h"


// Sets default values for this component's properties
USCItemContainer::USCItemContainer()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USCItemContainer::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USCItemContainer::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


bool USCItemContainer::FindEmptySlot(int& OutSlotId) const
{
	OutSlotId = -1;
	for(int i=0;i<Items.Num();i++)
	{
		if (Items[i].ItemID==0)
		{
			OutSlotId=i;
			return true;
		}
	}
	return false;
}


bool USCItemContainer::AddItem(const FSCItemInfo& ItemInfo)
{
	int EmptySlotIndex=-1;
	if(FindEmptySlot(EmptySlotIndex))
	{
		Items[EmptySlotIndex]=ItemInfo;
		UpdateItemSlot(EmptySlotIndex,ItemInfo);
		return true;
	}
	return false;
}

void USCItemContainer::AddItemToSlot_Implementation(int SlotIndex, const FSCItemInfo& ItemInfo)
{
	Items[SlotIndex]=ItemInfo;
	UpdateItemSlot(SlotIndex,ItemInfo);
}

void USCItemContainer::UpdateItemSlot_Implementation(int SlotIndex, const FSCItemInfo& ItemInfo, bool ResetSlot)
{
	if(ResetSlot)
	{
		
	}
	else
	{
		if(ASurvivalCraftCharacter* SCCharacter= Cast<ASurvivalCraftCharacter>(GetOwner()))
		{
			if(ASCPlayerController* PC=Cast<ASCPlayerController>(SCCharacter->GetController()))
			{
				PC->UpdateItemSlot(ContainerType, SlotIndex, ItemInfo);
			}
		}
		switch (ContainerType)
		{
		case PlayerInventory:
			break;
		case PlayerHotbar:
			break;
		case PlayerStore:
			break;
		case PlayerAromor:
			break;
		default:
				break;
		}
	}
}

void USCItemContainer::AddItemOnServer_Implementation(const FSCItemInfo& ItemInfo)
{
	AddItem(ItemInfo);
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/SCPlayerHotBar.h"

#include "SCEquipableItem1P.h"
#include "SCEquipableItem3P.h"
#include "SCItemType.h"
#include "Character/SurvivalCraftCharacter.h"
#include "Engine/SkeletalMeshSocket.h"

#define LOCTEXT_NAMESPACE "SCPlayerHotBar"

void USCPlayerHotBar::UseHotBarOnServer_Implementation(int SlotIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("USCPlayerHotBar::UseHotBarOnServer_Implementation Using HotBar on Server"));
	FSCItemInfo ItemInfo;
	if (SlotHasItem(SlotIndex,ItemInfo))
	{
		switch (ItemInfo.ItemType)
		{
		case Equipable:
			if(SlotIndex==LastEquipSlotIndex)
			{
				LastEquipSlotIndex=-1;
				UnequipItem();
			}
			else
			{
				LastEquipSlotIndex=SlotIndex;
				EquipItem(ItemInfo);
			}
			break;
		default:
			break;
		}
	}
	
}

bool USCPlayerHotBar::SlotHasItem(int SlotIndex,FSCItemInfo& ItemInfo)
{
	ItemInfo=Items[SlotIndex];
	return  Items[SlotIndex].ItemID>0;
}

void USCPlayerHotBar::UnequipItem_Implementation()
{
	if(EquippedItem1P)
	{
		EquippedItem1P->Destroy();
	}
	if(EquippedItem3P)
	{
		EquippedItem3P->Destroy();
	}
	if(ASurvivalCraftCharacter* Character=Cast<ASurvivalCraftCharacter>(GetOwner()))
	{
		Character->EquippedState=EEquipableState::Default;
	}
}

void USCPlayerHotBar::EquipItem_Implementation(const FSCItemInfo& ItemInfo)
{
	SpawnItem(ItemInfo);

	//检查装备的物品是否启用了Nanite
	if(const UStaticMesh* TargetStaticMesh= EquippedItem3P->GetMeshComponent()->GetStaticMesh())
	{
		if(TargetStaticMesh->IsNaniteEnabled())
		{
			FMessageLog("PIE").Error(LOCTEXT("禁用Nanite","需禁用静态网格体的Nanite"));
			return;
		}
	}
	
	if(USkeletalMeshComponent* Mesh3P = Cast<ASurvivalCraftCharacter>(GetOwner())->GetMesh3P())
	{
		EquippedItem3P->AttachToComponent(Mesh3P,FAttachmentTransformRules::SnapToTargetNotIncludingScale,"WeaponSocket");
	}

	if(USkeletalMeshComponent* Mesh1P = Cast<ASurvivalCraftCharacter>(GetOwner())->GetMesh1P())
	{
		EquippedItem1P->AttachToComponent(Mesh1P,FAttachmentTransformRules::SnapToTargetNotIncludingScale,"WeaponSocket");
	}

	if(ASurvivalCraftCharacter* Character=Cast<ASurvivalCraftCharacter>(GetOwner()))
	{
		Character->EquippedState=EEquipableState::Hatchet;
	}
}


void USCPlayerHotBar::SpawnItem_Implementation(const FSCItemInfo& ItemInfo)
{
	//生成3P物品
	if(ASCEquipableItem3P* Item3P= Cast<ASCEquipableItem3P>(GetWorld()->SpawnActor(ItemInfo.ItemClass)))
	{
		EquippedItem3P=Item3P;
		EquippedItem3P->SetOwner(GetOwner());
		//生成1P物品
		if(TSubclassOf<ASCEquipableItem1P> Item1PClass= EquippedItem3P->EquipableItemInfo.EquipableItemClass1P)
		{
			if(ASCEquipableItem1P* Item1P= Cast<ASCEquipableItem1P>(GetWorld()->SpawnActor(Item1PClass)))
			{
				EquippedItem1P=Item1P;
				EquippedItem1P->SetOwner(GetOwner());
			}
		}
	}
}


#undef LOCTEXT_NAMESPACE
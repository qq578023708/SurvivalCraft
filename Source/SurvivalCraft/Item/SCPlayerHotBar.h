// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/SCItemContainer.h"
#include "SCPlayerHotBar.generated.h"

class ASCEquipableItem1P;
class ASCEquipableItem3P;
/**
 * 
 */
UCLASS()
class SURVIVALCRAFT_API USCPlayerHotBar : public USCItemContainer
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable,Server,Unreliable)
	void UseHotBarOnServer(int SlotIndex);

	bool SlotHasItem(int SlotIndex,FSCItemInfo& ItemInfo);

	UFUNCTION(BlueprintCallable,Server,unreliable)
	void SpawnItem(const FSCItemInfo& ItemInfo);

	UFUNCTION(BlueprintCallable,Server,unreliable)
	void EquipItem(const FSCItemInfo& ItemInfo);

	UFUNCTION(BlueprintCallable,Server,unreliable)
	void UnequipItem();

	TObjectPtr<ASCEquipableItem3P> EquippedItem3P;
	TObjectPtr<ASCEquipableItem1P> EquippedItem1P;
	int LastEquipSlotIndex=-1;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/DragDropOperation.h"
#include "Item/SCItemType.h"
#include "SCDragDropOperation.generated.h"

struct FSCItemInfo;
enum ESCArmorType : int;
enum ESCItemType : int;
enum ESCContainerType : int;
/**
 * 
 */
UCLASS()
class SURVIVALCRAFT_API USCDragDropOperation : public UDragDropOperation
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly,BlueprintReadOnly,meta=(ExposeOnSpawn="true"))
	int SlotIndex;

	UPROPERTY(EditInstanceOnly,BlueprintReadOnly,meta=(ExposeOnSpawn="true"))
	TEnumAsByte<ESCContainerType> ContainerType;

	UPROPERTY(EditInstanceOnly,BlueprintReadOnly,meta=(ExposeOnSpawn="true"))
	TEnumAsByte<ESCItemType> ItemType;

	UPROPERTY(EditInstanceOnly,BlueprintReadOnly,meta=(ExposeOnSpawn="true"))
	TEnumAsByte<ESCArmorType> ArmorType;

	UPROPERTY(EditInstanceOnly,BlueprintReadOnly,meta=(ExposeOnSpawn="true"))
	FSCItemInfo ItemInfo;
};

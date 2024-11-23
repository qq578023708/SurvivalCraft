// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCItemType.h"
#include "Item/SCItemBase.h"
#include "SCEquipableItemBase.generated.h"

struct FEquipableItemInfo;
/**
 * 
 */
UCLASS()
class SURVIVALCRAFT_API ASCEquipableItemBase : public ASCItemBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	FEquipableItemInfo EquipableItemInfo;
	
};

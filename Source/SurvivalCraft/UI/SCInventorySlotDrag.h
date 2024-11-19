// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCUserWidget.h"
#include "Item/SCItemType.h"
#include "SCInventorySlotDrag.generated.h"

struct FSCItemInfo;
class UProgressBar;
class UTextBlock;
class UBorder;
/**
 * 
 */
UCLASS()
class SURVIVALCRAFT_API USCInventorySlotDrag : public USCUserWidget
{
	GENERATED_BODY()

public:
	void Init();

public:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UTexture2D> IconImage;

	UPROPERTY(EditAnywhere)
	FText ItemTopText;

	UPROPERTY(EditAnywhere)
	FSCItemInfo ItemInfo;

	UPROPERTY(EditAnywhere)
	int SlotIndex;

protected:
	UPROPERTY(EditAnywhere,meta=(BindWidget))
	TObjectPtr<UBorder> ItemIcon;

	UPROPERTY(EditAnywhere,meta=(BindWidget))
	TObjectPtr<UTextBlock> TopText;

	UPROPERTY(EditAnywhere,meta=(BindWidget))
	TObjectPtr<UTextBlock> BottomText;

	UPROPERTY(EditAnywhere,meta=(BindWidget))
	TObjectPtr<UProgressBar> ItemHp;

	UPROPERTY(EditAnywhere,meta=(BindWidget))
	TObjectPtr<UTextBlock> ItemQuantity;
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/SCItemType.h"
#include "UI/SCUserWidget.h"
#include "SCInventorySlot.generated.h"

class USCInventorySlotDrag;
struct FSCItemInfo;
class UProgressBar;
class UTextBlock;
class UBorder;
/**
 * 
 */
UCLASS()
class SURVIVALCRAFT_API USCInventorySlot : public USCUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void UpdateSlotInfo(int InSlotIndex,const FSCItemInfo& InItemInfo);

	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation) override;
	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;

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

	UPROPERTY(BlueprintReadOnly)
	bool SlotHasItem=false;

	UPROPERTY(EditAnywhere)
	TSubclassOf<USCInventorySlotDrag> SlotDragClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UDragDropOperation> DragDropOperationClass;

	UPROPERTY()
	FSCItemInfo ItemInfo;

	UPROPERTY(EditAnywhere)
	int ItemIndex=0;

	UPROPERTY(VisibleAnywhere)
	int SlotIndex;
};

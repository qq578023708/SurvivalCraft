// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/SCUserWidget.h"
#include "SCItemContainerGrid.generated.h"

class UUniformGridPanel;
enum ESCContainerType :uint8;
/**
 * 
 */
UCLASS()
class SURVIVALCRAFT_API USCItemContainerGrid : public USCUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddSlots(int Amount);

	UFUNCTION(BlueprintCallable)
	void AddSlotToGrid(int SlotIndex,USCUserWidget* InSlot);

	

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere,meta=(ExposeOnSpawn="true"))
	int SlotsPerRow = 0;

	UPROPERTY(BlueprintReadOnly, EditAnywhere,meta=(ExposeOnSpawn="true"))
	int TotalSlots = 0;

	UPROPERTY(BlueprintReadOnly, EditAnywhere,meta=(ExposeOnSpawn="true"))
	TEnumAsByte<ESCContainerType> ContainerType;

	UPROPERTY(EditAnywhere)
	TSubclassOf<USCUserWidget> InventorySlotClass;

	UPROPERTY(EditAnywhere,meta=(BindWidget))
	TObjectPtr<UUniformGridPanel> ItemGrid;

public:
	UPROPERTY(EditAnywhere)
	TArray<TObjectPtr<USCUserWidget>> Slots;

	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SCPlayerController.generated.h"

struct FSCItemInfo;
enum ESCContainerType :uint8;
class USCMainHUD;
class USCUserWidget;
/**
 * 
 */
UCLASS()
class SURVIVALCRAFT_API ASCPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	/**
	 * 更新UI上指定插槽的物品信息
	 * @param TargetContainer 
	 * @param SlotIndex 
	 * @param InventoryItemInfo 
	 */
	UFUNCTION(BlueprintCallable,Client,Unreliable)
	void UpdateItemSlot(ESCContainerType TargetContainer,int SlotIndex,FSCItemInfo InventoryItemInfo);

protected:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> MainHudClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> InventoryClass;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<USCMainHUD> SCMainHUD;
};

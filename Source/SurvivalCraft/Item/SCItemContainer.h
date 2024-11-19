// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SCItemContainer.generated.h"


enum ESCContainerType : int;
struct FSCItemInfo;

UCLASS(ClassGroup=(Custom),Blueprintable,BlueprintType, meta=(BlueprintSpawnableComponent))
class SURVIVALCRAFT_API USCItemContainer : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USCItemContainer();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	/**
	 * 寻找一个空插槽
	 * @param OutSlotId 
	 * @return 
	 */
	bool FindEmptySlot(int& OutSlotId) const;

	/**
	 * 寻找一个空插槽并添加物品
	 * @param ItemInfo 
	 * @return 
	 */
	bool AddItem(const FSCItemInfo& ItemInfo);

	/**
	 * 寻找一个空插槽并添加物品(服务端)
	 * @param ItemInfo 
	 */
	UFUNCTION(BlueprintCallable,Server,Unreliable)
	void AddItemOnServer(const FSCItemInfo& ItemInfo);

	/**
	 * 将物品添加到指定插槽,覆盖原有物品信息(服务端)
	 * @param SlotIndex 
	 * @param ItemInfo 
	 */
	UFUNCTION(BlueprintCallable,Server,Unreliable)
	void AddItemToSlot(int SlotIndex,const FSCItemInfo& ItemInfo);


	/**
	 * 更新指定插槽的物品信息(客户端)
	 * @param SlotIndex 
	 * @param ItemInfo 
	 * @param ResetSlot 
	 */
	UFUNCTION(BlueprintCallable,Client,Unreliable)
	void UpdateItemSlot(int SlotIndex,const FSCItemInfo& ItemInfo,bool ResetSlot=false);

	virtual void OnSlotDrop(ESCContainerType FromContainer,int FromSlotIndex,int DropIndex){};

protected:
	UPROPERTY(EditAnywhere)
	TArray<FSCItemInfo> Items;

	UPROPERTY(EditAnywhere)
	TEnumAsByte<ESCContainerType>  ContainerType;
};

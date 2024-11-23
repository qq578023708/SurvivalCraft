// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SCItemType.generated.h"

class ASCEquipableItemBase;
class ASCEquipableItem1P;

UENUM(BlueprintType)
enum ESCItemType:uint8
{
	Resource,//资源
	Equipable,//可装备的
	Armor,//护甲
	Consumable,//可消耗的
	Buildable,//可建造的
};

UENUM(BlueprintType)
enum ESCItemRarity:uint8
{
	Common, //常见的
	Uncommon, //不常见的
	Rare,//稀有的
	Epic, //史诗级
	Legendary, //传说级
};

UENUM(BlueprintType)
enum ESCArmorType:uint8
{
	Helmet, //头盔
	Chest, //上衣
	Pants, //裤子
	Boots, //鞋子
};

USTRUCT(BlueprintType)
struct FSCItemInfo
{
	GENERATED_BODY()

public:

	FSCItemInfo():ItemID(0),ItemQuantity(0),ItemIcon(nullptr),ItemName(FText()),ItemDesc(FText()),ItemDamage(0),ItemRarity(0),ItemCurHp(0),ItemMaxHp(0)
	,ItemStackable(false),ItemStackSize(0),ItemType(0),ItemClass(nullptr),ArmorType(0),UseAmmo(false),CurrAmmo(0),MaxAmmo(0){}

	UPROPERTY(EditAnywhere,meta=(ToolTip="物品ID"))
	int32 ItemID;

	UPROPERTY(EditAnywhere,meta=(ToolTip="物品数量"))
	int32 ItemQuantity;
	
	UPROPERTY(EditAnywhere,meta=(ToolTip="物品图标"))
	TObjectPtr<UTexture2D> ItemIcon;

	UPROPERTY(EditAnywhere,meta=(ToolTip="物品名称"))
	FText ItemName;

	UPROPERTY(EditAnywhere,meta=(ToolTip="物品描述"))
	FText ItemDesc;

	UPROPERTY(EditAnywhere,meta=(ToolTip="物品伤害"))
	int32 ItemDamage;
	
	UPROPERTY(EditAnywhere,meta=(ToolTip="物品稀有度"))
	TEnumAsByte<ESCItemRarity> ItemRarity;

	UPROPERTY(EditAnywhere,meta=(ToolTip="物品当前生命值"))
	int32 ItemCurHp;

	UPROPERTY(EditAnywhere,meta=(ToolTip="物品最大生命值"))
	int32 ItemMaxHp;

	UPROPERTY(EditAnywhere,meta=(ToolTip="物品是否可堆叠"))
	bool ItemStackable;

	UPROPERTY(EditAnywhere,meta=(ToolTip="物品堆叠数量"))
	int32 ItemStackSize;

	UPROPERTY(EditAnywhere,meta=(ToolTip="物品类型"))
	TEnumAsByte<ESCItemType> ItemType;
	
	UPROPERTY(EditAnywhere,meta=(ToolTip="物品类引用"))
	TSubclassOf<AActor> ItemClass;

	UPROPERTY(EditAnywhere,meta=(ToolTip="护甲类型"))
	TEnumAsByte<ESCArmorType> ArmorType;

	UPROPERTY(EditAnywhere,meta=(ToolTip="使用弹药"))
	bool UseAmmo;

	UPROPERTY(EditAnywhere,meta=(ToolTip="当前弹药数量"))
	int32 CurrAmmo;

	UPROPERTY(EditAnywhere,meta=(ToolTip="最大弹药数量"))
	int32 MaxAmmo;
};

UENUM(BlueprintType)
enum ESCContainerType:uint8
{
	PlayerInventory, //库存
	PlayerHotbar, //快捷栏
	PlayerStore, //存储
	PlayerAromor //护甲
};

UENUM(BlueprintType)
enum EEquipableState:uint8
{
	Hatchet, //斧头
	Bow, //弓箭
	Rock, //石头
	Rifle, //步枪
	RocketLauncher, //火箭发射器
	Default, //默认
	Spear, //矛
	Swimming //游泳
};

USTRUCT(BlueprintType)
struct FEquipableItemInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FName SocketName;

	UPROPERTY(EditAnywhere)
	TEnumAsByte<EEquipableState> AnimationState;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ASCEquipableItem1P> EquipableItemClass1P;
};

/**
 * 
 */
UCLASS()
class SURVIVALCRAFT_API USCItemType : public UObject
{
	GENERATED_BODY()
};

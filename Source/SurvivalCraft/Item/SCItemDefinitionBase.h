// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SCItemDefinitionBase.generated.h"

struct FSCItemInfo;
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class SURVIVALCRAFT_API USCItemDefinitionBase : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere,BlueprintReadOnly,meta=(TitleProperty="{ItemName}"))
	TArray<FSCItemInfo> Items;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override {return FPrimaryAssetId("ItemDefinitionBase",GetFName());};
};

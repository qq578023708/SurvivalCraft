// Fill out your copyright notice in the Description page of Project Settings.


#include "SCInventorySlotDrag.h"

#include "Components/Border.h"

void USCInventorySlotDrag::Init()
{
	if (IconImage!=nullptr)
	{
		ItemIcon->SetBrushFromTexture(IconImage);
	}
}

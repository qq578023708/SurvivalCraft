// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SCCharacter.generated.h"

class ASurvivalCraftCharacter;
// This class does not need to be modified.
UINTERFACE()
class USCCharacter : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SURVIVALCRAFT_API ISCCharacter
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual  ASurvivalCraftCharacter* GetCharacter();
};

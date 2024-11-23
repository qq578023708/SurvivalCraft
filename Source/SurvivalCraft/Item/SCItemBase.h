// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SCItemBase.generated.h"

UCLASS()
class SURVIVALCRAFT_API ASCItemBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASCItemBase();

	UStaticMeshComponent* GetMeshComponent(){return StaticMeshComponent;}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USceneComponent> RootSceneComponent;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};

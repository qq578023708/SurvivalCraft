// Fill out your copyright notice in the Description page of Project Settings.


#include "SCItemBase.h"


// Sets default values
ASCItemBase::ASCItemBase()
{
	RootSceneComponent=CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent=RootSceneComponent;
	StaticMeshComponent=CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	StaticMeshComponent->SetupAttachment(RootComponent);
	StaticMeshComponent->SetCollisionProfileName("NoCollision");
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
}

// Called when the game starts or when spawned
void ASCItemBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASCItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


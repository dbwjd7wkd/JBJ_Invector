// Fill out your copyright notice in the Description page of Project Settings.


#include "PadManager.h"
#include "A_Pad.h"
#include "D_Pad.h"
#include "Up_Pad.h"
#include "Down_Pad.h"
#include "Left_Pad.h"
#include "Right_Pad.h"
#include "SpaceBar_Pad.h"

// Sets default values
APadManager::APadManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APadManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APadManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	currentTime += DeltaTime;

	if (currentTime > createTime)
	{
		FActorSpawnParameters param;
		param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		int32 ratio = FMath::RandRange(0, 7);
		if (ratio == 0)
		{
			currentTime = 0;
			return;
		}
		else if (ratio == 1)
		{
			auto apad = GetWorld()->SpawnActor<AA_Pad>(aPadFactory, GetTransform(), param);
			currentTime = 0;
		}
		else if (ratio == 2)
		{
			auto dpad = GetWorld()->SpawnActor<AD_Pad>(dPadFactory, GetTransform(), param);
			currentTime = 0;
		}
		else if (ratio == 3)
		{
			auto uppad = GetWorld()->SpawnActor<AUp_Pad>(upPadFactory, GetTransform(), param);
			currentTime = 0;
		}
		else if (ratio == 4)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform(), param);
			currentTime = 0;
		}
		else if (ratio == 5)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform(), param);
			currentTime = 0;
		}
		else if (ratio == 6)
		{
			auto pad = GetWorld()->SpawnActor<ARight_Pad>(rightPadFactory, GetTransform(), param);
			currentTime = 0;
		}
		else if (ratio == 7)
		{
			auto pad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform(), param);
			currentTime = 0;
		}

			
	}
}


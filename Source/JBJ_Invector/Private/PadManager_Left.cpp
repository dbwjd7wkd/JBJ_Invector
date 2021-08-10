// Fill out your copyright notice in the Description page of Project Settings.


#include "PadManager_Left.h"
#include "D_Pad.h"
#include "Down_Pad.h"
#include "Left_Pad.h"
#include "Kismet/GameplayStatics.h"
#include "JBJPlayer.h"

// Sets default values
APadManager_Left::APadManager_Left()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APadManager_Left::BeginPlay()
{
	Super::BeginPlay();
	
	target = UGameplayStatics::GetActorOfClass(GetWorld(), AJBJPlayer::StaticClass());

	if (target)
	{
		v = FVector::ForwardVector * speed;
		v.Normalize();
		v *= speed;
	}
}

// Called every frame
void APadManager_Left::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	currentTime += DeltaTime;

	if (target)
	{
		FVector P = GetActorLocation() + FVector(v.X, 0.0f, 0.0f) * DeltaTime;

		SetActorLocation(P, true);
	}

	if (check == 0)
	{
		if (currentTime >= 73.250381)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 1;
		}
	}

	if (check == 1)
	{
		if (currentTime >= 73.750488)
		{
			auto dpad = GetWorld()->SpawnActor<AD_Pad>(dPadFactory, GetTransform());
			check = 2;
		}
	}

	if (check == 2)
	{
		if (currentTime >= 120.473167)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 3;
		}
	}

	if (check == 3)
	{
		if (currentTime >= 120.973274)
		{
			auto dpad = GetWorld()->SpawnActor<AD_Pad>(dPadFactory, GetTransform());
			check = 4;
		}
	}

	if (check == 4)
	{
		if (currentTime >= 252.727676)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 5;
		}
	}

	if (check == 5)
	{
		if (currentTime >= 253.244232)
		{
			auto dpad = GetWorld()->SpawnActor<AD_Pad>(dPadFactory, GetTransform());
			check = 6;
		}
	}
}


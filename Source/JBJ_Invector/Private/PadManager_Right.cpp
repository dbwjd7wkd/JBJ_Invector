// Fill out your copyright notice in the Description page of Project Settings.


#include "PadManager_Right.h"
#include "A_Pad.h"
#include "Left_Pad.h"
#include "Kismet/GameplayStatics.h"
#include "JBJPlayer.h"

// Sets default values
APadManager_Right::APadManager_Right()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APadManager_Right::BeginPlay()
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
void APadManager_Right::Tick(float DeltaTime)
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
		if (currentTime >= 77.184639)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 1;
		}
	}

	if (check == 1)
	{
		if (currentTime >= 77.684761)
		{
			auto apad = GetWorld()->SpawnActor<AA_Pad>(aPadFactory, GetTransform());
			check = 2;
		}
	}

	if (check == 2)
	{
		if (currentTime >= 124.424149)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 3;
		}
	}

	if (check == 3)
	{
		if (currentTime >= 124.890923)
		{
			auto apad = GetWorld()->SpawnActor<AA_Pad>(aPadFactory, GetTransform());
			check = 4;
		}
	}

	if (check == 4)
	{
		if (currentTime >= 245.828934)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 5;
		}
	}

	if (check == 5)
	{
		if (currentTime >= 246.295639)
		{
			auto apad = GetWorld()->SpawnActor<AA_Pad>(aPadFactory, GetTransform());
			check = 6;
		}
	}
}


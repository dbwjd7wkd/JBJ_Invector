// Fill out your copyright notice in the Description page of Project Settings.


#include "A_Pad.h"
#include <Components/BoxComponent.h>
#include "JBJPlayer.h"
#include "PlayerMove.h"
#include "JBJ_Invector.h"


// Sets default values
AA_Pad::AA_Pad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	boxCompPerfect = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollisionPerfect"));
	RootComponent = boxCompPerfect;
	boxCompGreat = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollisionGreat"));
	boxCompGreat->SetupAttachment(boxCompPerfect);
	boxCompGreat2 = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollisionGreat2"));
	boxCompGreat2->SetupAttachment(boxCompPerfect);
	boxCompBad = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollisionBad"));
	boxCompBad->SetupAttachment(boxCompPerfect);
	boxCompBad2 = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollisionBad2"));
	boxCompBad2->SetupAttachment(boxCompPerfect);
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	meshComp->SetupAttachment(boxCompPerfect);
}

// Called when the game starts or when spawned
void AA_Pad::BeginPlay()
{
	Super::BeginPlay();

	boxCompPerfect->OnComponentEndOverlap.AddDynamic(this, &AA_Pad::OnCollisionPerfect);
	boxCompGreat->OnComponentEndOverlap.AddDynamic(this, &AA_Pad::OnCollisionGreat);
	boxCompGreat2->OnComponentEndOverlap.AddDynamic(this, &AA_Pad::OnCollisionGreat);
	boxCompBad->OnComponentEndOverlap.AddDynamic(this, &AA_Pad::OnCollisionBad);
	boxCompBad2->OnComponentEndOverlap.AddDynamic(this, &AA_Pad::OnCollisionBad);
}

// Called every frame
void AA_Pad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AA_Pad::OnCollisionPerfect(class UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	auto player = Cast<AJBJPlayer>(OtherActor);
	if (player)
	{
		if (overlapCheck == false)
		{
			if (player->playerMove->left == 1)
			{
				PRINTLOG(TEXT("PerFect!!!!!!!!"));
				overlapCheck = true;
			}
		}
	}
}

void AA_Pad::OnCollisionGreat(class UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	auto player = Cast<AJBJPlayer>(OtherActor);
	if (player)
	{
		if (overlapCheck == false)
		{
			if (player->playerMove->left == 1)
			{
				PRINTLOG(TEXT("Good!!!"));
				overlapCheck = true;
			}
		}
	}
}

void AA_Pad::OnCollisionBad(class UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	auto player = Cast<AJBJPlayer>(OtherActor);
	if (player)
	{
		if (overlapCheck == false)
		{
			if (player->playerMove->left == 1)
			{
				PRINTLOG(TEXT("Bad T.T"));
				overlapCheck = true;
			}
		}
	}
}
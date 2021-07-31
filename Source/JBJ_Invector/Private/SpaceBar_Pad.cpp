// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceBar_Pad.h"
#include <Components/BoxComponent.h>
#include "JBJPlayer.h"
#include "PlayerMove.h"
#include "JBJ_Invector.h"

// Sets default values
ASpaceBar_Pad::ASpaceBar_Pad()
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
void ASpaceBar_Pad::BeginPlay()
{
	Super::BeginPlay();
	
	boxCompPerfect->OnComponentEndOverlap.AddDynamic(this, &ASpaceBar_Pad::OnCollisionPerfect);
	boxCompGreat->OnComponentEndOverlap.AddDynamic(this, &ASpaceBar_Pad::OnCollisionGreat);
	boxCompGreat2->OnComponentEndOverlap.AddDynamic(this, &ASpaceBar_Pad::OnCollisionGreat);
	boxCompBad->OnComponentEndOverlap.AddDynamic(this, &ASpaceBar_Pad::OnCollisionBad);
	boxCompBad2->OnComponentEndOverlap.AddDynamic(this, &ASpaceBar_Pad::OnCollisionBad);
}

// Called every frame
void ASpaceBar_Pad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpaceBar_Pad::OnCollisionPerfect(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	auto player = Cast<AJBJPlayer>(OtherActor);
	if (player)
	{
		if (overlapCheck == false)
		{
			if (player->playerMove->spaceBar == true)
			{
				PRINTLOG(TEXT("PerFect!!!!!!!!"));
				overlapCheck = true;
			}
		}
	}
}

void ASpaceBar_Pad::OnCollisionGreat(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	auto player = Cast<AJBJPlayer>(OtherActor);
	if (player)
	{
		if (overlapCheck == false)
		{
			if (player->playerMove->spaceBar == true)
			{
				PRINTLOG(TEXT("Good!!!"));
				overlapCheck = true;
			}
		}
	}
}

void ASpaceBar_Pad::OnCollisionBad(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	auto player = Cast<AJBJPlayer>(OtherActor);
	if (player)
	{
		if (overlapCheck == false)
		{
			if (player->playerMove->spaceBar == true)
			{
				PRINTLOG(TEXT("Bad T.T"));
				overlapCheck = true;
			}
		}
	}
}


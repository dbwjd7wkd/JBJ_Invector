// Fill out your copyright notice in the Description page of Project Settings.


#include "SectionManager.h"
#include <Components/BoxComponent.h>
#include "JBJPlayer.h"
#include "PlayerMove.h"
#include "JBJ_Invector.h"

// Sets default values
ASectionManager::ASectionManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Coliision"));
	RootComponent = collision;
	collision->SetRelativeScale3D(FVector(1.000000, 17.257500, 14.442500));

}

// Called when the game starts or when spawned
void ASectionManager::BeginPlay()
{
	Super::BeginPlay();
	
	collision->OnComponentBeginOverlap.AddDynamic(this, &ASectionManager::OnCollisionPlayer);
}

// Called every frame
void ASectionManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASectionManager::OnCollisionPlayer(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	auto player = Cast<AJBJPlayer>(OtherActor);
	//PRINTLOG(TEXT("section: %f"), player->playerMove->section);
	if (player)
	{
		float st = player->playerMove->section;
		if(st == 0) player->playerMove->section = 1;
		else if(st == 1) player->playerMove->section = 0;
	}
	
}


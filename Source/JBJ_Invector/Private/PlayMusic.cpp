// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayMusic.h"
#include <Components/BoxComponent.h>
#include "JBJPlayer.h"
#include <Kismet/GameplayStatics.h>
// Sets default values
APlayMusic::APlayMusic()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	RootComponent = boxComp;
}

// Called when the game starts or when spawned
void APlayMusic::BeginPlay()
{
	Super::BeginPlay();
	
	boxComp->OnComponentEndOverlap.AddDynamic(this, &APlayMusic::OnCollisionEnter);
}

// Called every frame
void APlayMusic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayMusic::OnCollisionEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	auto player = Cast<AJBJPlayer>(OtherActor);
	if (player)
	{
		if (overlapCheck == false)
		{
			UGameplayStatics::PlaySound2D(GetWorld(), playMusic);
		}
	}
}


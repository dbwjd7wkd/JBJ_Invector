// Fill out your copyright notice in the Description page of Project Settings.


#include "PadDestroyZone.h"
#include "Components/BoxComponent.h"

// Sets default values
APadDestroyZone::APadDestroyZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	RootComponent = boxComp;
	
}

// Called when the game starts or when spawned
void APadDestroyZone::BeginPlay()
{
	Super::BeginPlay();
	
	boxComp->OnComponentHit.AddDynamic(this, &APadDestroyZone::OnCollisionEnter);

}

// Called every frame
void APadDestroyZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APadDestroyZone::OnCollisionEnter(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	OtherActor->Destroy();
}


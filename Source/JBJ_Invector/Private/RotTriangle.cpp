// Fill out your copyright notice in the Description page of Project Settings.


#include "RotTriangle.h"
#include "JBJPlayer.h"
#include <Components/BoxComponent.h>
#include "GameFramework/RotatingMovementComponent.h"

// Sets default values
ARotTriangle::ARotTriangle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	rotTest = CreateDefaultSubobject<UBoxComponent>(TEXT("RotTest"));
	RootComponent = rotTest;

	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	meshComp->SetupAttachment(rotTest);

	rotateMovement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("ROTATEMOVEMENT"));
	
}

// Called when the game starts or when spawned
void ARotTriangle::BeginPlay()
{
	Super::BeginPlay();
	rotateMovement->RotationRate = FRotator(0.0f, 0.0f, rotSpeed);
}

// Called every frame
void ARotTriangle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}



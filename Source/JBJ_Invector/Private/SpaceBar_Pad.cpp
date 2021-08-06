// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceBar_Pad.h"
#include <Components/BoxComponent.h>
#include "JBJPlayer.h"
#include "PlayerMove.h"
#include "JBJ_Invector.h"
#include "Kismet/GameplayStatics.h"

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
	
	boxCompPerfect->OnComponentBeginOverlap.AddDynamic(this, &ASpaceBar_Pad::OnCollisionPerfect);
	boxCompGreat->OnComponentBeginOverlap.AddDynamic(this, &ASpaceBar_Pad::OnCollisionGreat);
	boxCompGreat2->OnComponentBeginOverlap.AddDynamic(this, &ASpaceBar_Pad::OnCollisionGreat);
	boxCompBad->OnComponentBeginOverlap.AddDynamic(this, &ASpaceBar_Pad::OnCollisionBad);
	boxCompBad2->OnComponentBeginOverlap.AddDynamic(this, &ASpaceBar_Pad::OnCollisionBad);

	target = UGameplayStatics::GetActorOfClass(GetWorld(), AJBJPlayer::StaticClass());
	v = FVector::ForwardVector * speed;
	if (target)
	{
		v = target->GetActorLocation() - GetActorLocation();
		v.Normalize();
		v *= speed;
	}
}

// Called every frame
void ASpaceBar_Pad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector P = GetActorLocation() + v * DeltaTime;

	SetActorLocation(P, true);
}

void ASpaceBar_Pad::OnCollisionPerfect(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	auto player = Cast<AJBJPlayer>(OtherActor);
	if (player)
	{
		if (overlapCheck == false)
		{
			if (player->playerMove->spaceBar == true)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("PerFect!!!!!!!!"), 100, 100));
				PRINTLOG(TEXT("PerFect!!!!!!!!"));
				overlapCheck = true;
				player->playerMove->spaceBar = false;
			}
		}
	}
}

void ASpaceBar_Pad::OnCollisionGreat(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	auto player = Cast<AJBJPlayer>(OtherActor);
	if (player)
	{
		if (overlapCheck == false)
		{
			if (player->playerMove->spaceBar == true)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Good!!!"), 100, 100));

				PRINTLOG(TEXT("Good!!!"));
				overlapCheck = true;
				player->playerMove->spaceBar = false;
			}
		}
	}
}

void ASpaceBar_Pad::OnCollisionBad(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	auto player = Cast<AJBJPlayer>(OtherActor);
	if (player)
	{
		if (overlapCheck == false)
		{
			if (player->playerMove->spaceBar == true)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Bad T.T"), 100, 100));

				PRINTLOG(TEXT("Bad T.T"));
				overlapCheck = true;
				player->playerMove->spaceBar = false;
			}
		}
	}
}


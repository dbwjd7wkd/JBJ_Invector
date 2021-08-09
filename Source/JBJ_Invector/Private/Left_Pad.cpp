// Fill out your copyright notice in the Description page of Project Settings.


#include "Left_Pad.h"
#include <Components/BoxComponent.h>
#include "JBJPlayer.h"
#include "PlayerMove.h"
#include "JBJ_Invector.h"
#include "Kismet/GameplayStatics.h"
#include "JBJ_InvectorGameMode.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ALeft_Pad::ALeft_Pad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	RootComponent = boxComp;
	boxCompPerfect = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollisionPerfect"));
	boxCompPerfect->SetupAttachment(boxComp);
	boxCompGreat = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollisionGreat"));
	boxCompGreat->SetupAttachment(boxComp);
	boxCompGreat2 = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollisionGreat2"));
	boxCompGreat2->SetupAttachment(boxComp);
	boxCompBad = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollisionBad"));
	boxCompBad->SetupAttachment(boxComp);
	boxCompBad2 = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollisionBad2"));
	boxCompBad2->SetupAttachment(boxComp);
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	meshComp->SetupAttachment(boxComp);


}

// Called when the game starts or when spawned
void ALeft_Pad::BeginPlay()
{
	Super::BeginPlay();
	
	boxCompPerfect->OnComponentBeginOverlap.AddDynamic(this, &ALeft_Pad::OnCollisionPerfect);
	boxCompGreat->OnComponentBeginOverlap.AddDynamic(this, &ALeft_Pad::OnCollisionGreat);
	boxCompGreat2->OnComponentBeginOverlap.AddDynamic(this, &ALeft_Pad::OnCollisionGreat);
	boxCompBad->OnComponentBeginOverlap.AddDynamic(this, &ALeft_Pad::OnCollisionBad);
	boxCompBad2->OnComponentBeginOverlap.AddDynamic(this, &ALeft_Pad::OnCollisionBad);

	target = UGameplayStatics::GetActorOfClass(GetWorld(), AJBJPlayer::StaticClass());
	v = FVector::ForwardVector * speed;
	if (target)
	{
		v = target->GetActorLocation() - GetActorLocation();
		v.Normalize();
		v *= speed;
	}

	player = Cast<AJBJPlayer>(UGameplayStatics::GetActorOfClass(GetWorld(), AJBJPlayer::StaticClass()));

	myGameMode = Cast<AJBJ_InvectorGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
}

// Called every frame
void ALeft_Pad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (target)
	{
		FVector P = GetActorLocation() + FVector(v.X, 0.0f, 0.0f) * DeltaTime;

		SetActorLocation(P, true);
	}
	myRot = GetActorRotation();
	Rot();
}

void ALeft_Pad::OnCollisionPerfect(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if (player)
	{
		if (overlapCheck == false)
		{
			if (player->playerMove->left == true)
			{
				//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("PerFect!!!!!!!!"), 100, 100));
				myGameMode->SetScorePerfect();

				PRINTLOG(TEXT("PerFect!!!!!!!!"));
				overlapCheck = true;
				player->playerMove->left = false;
			}
		}
	}
}

void ALeft_Pad::OnCollisionGreat(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if (player)
	{
		if (overlapCheck == false)
		{
			if (player->playerMove->left == true)
			{
				//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Good!!"), 100, 100));
				myGameMode->SetScoreGreat();

				PRINTLOG(TEXT("Good!!!"));
				overlapCheck = true;
				player->playerMove->left = false;
			}
		}
	}
}

void ALeft_Pad::OnCollisionBad(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if (player)
	{
		if (overlapCheck == false)
		{
			if (player->playerMove->left == true)
			{
				//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Bad T.T"), 100, 100));
				myGameMode->SetScoreBad();

				PRINTLOG(TEXT("Bad T.T"));
				overlapCheck = true;
				player->playerMove->left = false;
			}
		}
	}
}

void ALeft_Pad::Rot()
{
	int32 myRotX = myRot.Roll;

	if (player)
	{

		if (player->playerMove->a == true)
		{
			if (0 >= myRotX && myRotX >= -119)
			{
				myRot = FMath::Lerp(myRot, FRotator(0, 0, -120), 20 * GetWorld()->DeltaTimeSeconds);
				SetActorRotation(myRot);
				player->playerMove->d = false;
				if (myRotX == -119)
				{
					myRot = FRotator(0.f, 0.f, -120.f);
					myRotX = -120;
					SetActorRotation(myRot);
					player->playerMove->a = false;
				}

			}

			else if (-120 >= myRotX && myRotX >= -239)
			{
				myRot = FMath::Lerp(myRot, FRotator(0, 0, -240), 20 * GetWorld()->DeltaTimeSeconds);
				SetActorRotation(myRot);
				player->playerMove->d = false;
				if (myRotX == -239)
				{
					myRot = FRotator(0.f, 0.f, -240.f);
					SetActorRotation(myRot);
					myRotX = -240;
					player->playerMove->a = false;
				}

			}

			else if (-240 >= myRotX && myRotX >= -359)
			{
				myRot = FMath::Lerp(myRot, FRotator(0.f, 0.f, 0.f), 20 * GetWorld()->DeltaTimeSeconds);
				SetActorRotation(myRot);
				player->playerMove->d = false;
				if (myRotX == -359)
				{
					myRot = FRotator(0.f, 0.f, 0.f);
					myRotX = 0.f;
					SetActorRotation(myRot);
					player->playerMove->a = false;
				}
			}

			else if (120 >= myRotX && myRotX >= 1)
			{
				myRot = FMath::Lerp(myRot, FRotator(0, 0, 0), 20 * GetWorld()->DeltaTimeSeconds);
				SetActorRotation(myRot);
				player->playerMove->d = false;
				if (myRotX == 1)
				{
					myRot = FRotator(0.f, 0.f, 0.f);
					myRotX = 0;
					SetActorRotation(myRot);
					player->playerMove->a = false;
				}
			}

			else if (240 >= myRotX && myRotX >= 121)
			{
				myRot = FMath::Lerp(myRot, FRotator(0, 0, 120.f), 20 * GetWorld()->DeltaTimeSeconds);
				SetActorRotation(myRot);
				player->playerMove->d = false;
				if (myRotX == 121)
				{
					myRot = FRotator(0.f, 0.f, 120.f);
					myRotX = 120.f;
					SetActorRotation(myRot);
					player->playerMove->a = false;
				}
			}

			else if (360 >= myRotX && myRotX >= 241)
			{
				myRot = FMath::Lerp(myRot, FRotator(0, 0, 240.f), 20 * GetWorld()->DeltaTimeSeconds);
				SetActorRotation(myRot);
				player->playerMove->d = false;
				if (myRotX == 241)
				{
					myRot = FRotator(0.f, 0.f, 240.f);
					myRotX = 0.f;
					SetActorRotation(myRot);
					player->playerMove->a = false;
				}
			}
		}

		/// <summary>
		/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// </summary> 


		if (player->playerMove->d == true)
		{
			if (0 <= myRotX && myRotX <= 119)
			{
				myRot = FMath::Lerp(myRot, FRotator(0.f, 0.f, 120.f), 20 * GetWorld()->DeltaTimeSeconds);
				SetActorRotation(myRot);
				player->playerMove->a = false;
				if (myRotX == 119)
				{
					myRot = FRotator(0.f, 0.f, 120.f);
					SetActorRotation(myRot);
					myRotX = 120.f;
					player->playerMove->d = false;
				}

			}

			else if (120 <= myRotX && myRotX <= 239)
			{
				myRot = FMath::Lerp(myRot, FRotator(0.f, 0.f, 240.f), 20 * GetWorld()->DeltaTimeSeconds);
				SetActorRotation(myRot);
				player->playerMove->a = false;
				if (myRotX == 239)
				{
					myRot = FRotator(0.f, 0.f, 240.f);
					SetActorRotation(myRot);
					myRotX = 240.f;
					player->playerMove->d = false;
				}

			}

			else if (240 <= myRotX && myRotX <= 359)
			{
				myRot = FMath::Lerp(myRot, FRotator(0.f, 0.f, 0.f), 20 * GetWorld()->DeltaTimeSeconds);
				SetActorRotation(myRot);
				player->playerMove->a = false;
				if (myRotX == 359)
				{
					myRot = FRotator(0.f, 0.f, 0.f);
					myRotX = 0.f;
					SetActorRotation(myRot);
					player->playerMove->d = false;
				}
			}

			else if (-120 <= myRotX && myRotX <= -1)
			{
				myRot = FMath::Lerp(myRot, FRotator(0, 0, 0), 20 * GetWorld()->DeltaTimeSeconds);
				SetActorRotation(myRot);
				player->playerMove->a = false;
				if (myRotX == -1)
				{
					myRot = FRotator(0.f, 0.f, 0.f);
					myRotX = 0;
					SetActorRotation(myRot);
					player->playerMove->d = false;
				}
			}

			else if (-240 <= myRotX && myRotX <= -121)
			{
				myRot = FMath::Lerp(myRot, FRotator(0, 0, -120), 20 * GetWorld()->DeltaTimeSeconds);
				SetActorRotation(myRot);
				player->playerMove->a = false;
				if (myRotX == -121)
				{
					myRot = FRotator(0.f, 0.f, -120.f);
					myRotX = -120.f;
					SetActorRotation(myRot);
					player->playerMove->d = false;
				}
			}

			else if (-360 <= myRotX && myRotX <= -241)
			{
				myRot = FMath::Lerp(myRot, FRotator(0, 0, -240.f), 20 * GetWorld()->DeltaTimeSeconds);
				SetActorRotation(myRot);
				player->playerMove->a = false;
				if (myRotX == -241)
				{
					myRot = FRotator(0.f, 0.f, -240.f);
					myRotX = 0.f;
					SetActorRotation(myRot);
					player->playerMove->d = false;
				}
			}
		}

	}
}


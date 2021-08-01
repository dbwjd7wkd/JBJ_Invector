// Fill out your copyright notice in the Description page of Project Settings.


#include "RotTriangle.h"
#include "JBJPlayer.h"
#include "PlayerMove.h"
#include "JBJ_Invector.h"
#include <Kismet/GameplayStatics.h>
#include <Components/BoxComponent.h>
#include "TimerManager.h"

// Sets default values
ARotTriangle::ARotTriangle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	rotTest = CreateDefaultSubobject<UBoxComponent>(TEXT("RotTest"));
	RootComponent = rotTest;

	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	meshComp->SetupAttachment(rotTest);

	/*rotateMovement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("ROTATEMOVEMENT"));*/

	plusRot = myRot + desRot;
	minusRot = myRot - desRot;

}

// Called when the game starts or when spawned
void ARotTriangle::BeginPlay()
{
	Super::BeginPlay();
	/*rotateMovement->RotationRate = FRotator(0.0f, 0.0f, rotSpeed);*/

	player = Cast<AJBJPlayer>(UGameplayStatics::GetActorOfClass(GetWorld(), AJBJPlayer::StaticClass()));

	myRot = GetActorRotation();
	
}

// Called every frame
void ARotTriangle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Rot();
}

void ARotTriangle::Rot()
{
	// »ï°¢ÇüÀ» È¸Àü ½ÃÅ°°í ½Í´Ù.
	// ÇÊ¿ä¼Ó¼º : È¸Àü ¼Óµµ, ÇÃ·¹ÀÌ¾î Å° ÀÔ·Â, È¸Àü ¹æÇâ

	// myRot(³ªÀÇ Rotation °ª) ÀÇ x °ª (int°¡ °¡Àå Á¤È®ÇÏ´Ï int ·Î Ã¼Å©)
	int32 myRotX = myRot.Roll;
	
	//if ( myRotX <= -359 || myRotX >= 360)
	//{
	//	//GetWorld()->GetTimerManager().SetTimer(createTimer, this, &ARotTriangle::RotXReset, 3.0f, true, 0);
	//	myRot == FRotator(0.f, 0.f, 0.f);
	//	myRotX = 0;
	//	
	//}

	/*if (myRot == FRotator(-120.f, 0.f, 0.f) || myRot == FRotator(240.f, 0.f, 0.f))
	{
		myRot == FRotator(240.f, 0.f, 0.f);
	}

	if (myRot == FRotator(-240.f, 0.f, 0.f) || myRot == FRotator(120.f, 0.f, 0.f))
	{
		myRot == FRotator(120.f, 0.f, 0.f);
	}*/

	if (player)
	{
		
		if (player->playerMove->a == true)
		{
			
			
			// 0 º¸´Ù ÀÛ°í -119 º¸´Ù Å¬¶§, ¶Ç´Â 240º¸´Ù Å©°í 360 º¸´Ù ÀÛÀ»¶§
			if (0 >= myRotX && myRotX >= -119 )
			{
				PRINTLOG(TEXT("vvvvvvvvvvvvvv"));
				myRot = FMath::Lerp(myRot, FRotator(0, 0, -120), 10 * GetWorld()->DeltaTimeSeconds);
				SetActorRotation(myRot);

				if (myRotX == -119 || myRotX == 119)
				{
					// µü -120 ÀÌ µÊ
					myRot = FRotator(0.f, 0.f, -120.f);
					myRotX = -120;
					SetActorRotation(myRot);
					minusRot = myRot - desRot;
					PRINTLOG(TEXT("%d"), myRotX);
					player->playerMove->a = false;
					
				}
				
			}
			
			else if (-120 >= myRotX && myRotX >= -239)
			{
				myRot = FMath::Lerp(myRot, minusRot, 10 * GetWorld()->DeltaTimeSeconds);
				SetActorRotation(myRot);

				if (myRotX == -239 || myRotX == 239)
				{
					// µü -120 ÀÌ µÊ
					myRot = FRotator(0.f, 0.f, -240.f);
					SetActorRotation(myRot);
					myRotX = -240;
					minusRot = myRot - desRot;
					PRINTLOG(TEXT("%d"), myRotX);
					player->playerMove->a = false;

				}

			}

			else if (-240 >= myRotX && myRotX >= -359)
			{
				myRot = FMath::Lerp(myRot, minusRot, 10 * GetWorld()->DeltaTimeSeconds);
				SetActorRotation(myRot);

				if (myRotX == -359 || myRotX == 359)
				{
					// µü -120 ÀÌ µÊ
					myRot = FRotator(0.f, 0.f, 0.f);
					myRotX = 0.f;
					SetActorRotation(myRot);
					minusRot = myRot - desRot;
					PRINTLOG(TEXT("muyaho"));
					PRINTLOG(TEXT("%d"), myRotX);
					player->playerMove->a = false;

				}
			}

			else if (120 >= myRotX && myRotX >= 1)
			{
				myRot = FMath::Lerp(myRot, FRotator(0, 0, 0), 10 * GetWorld()->DeltaTimeSeconds);
				SetActorRotation(myRot);
				PRINTLOG(TEXT("ttttttttttttttttt"));
				PRINTLOG(TEXT("%d"), myRotX);
				if (myRotX == 1 || myRotX == 359)
				{
					// µü -120 ÀÌ µÊ
					myRot = FRotator(0.f, 0.f, 0.f);
					myRotX = 0;
					SetActorRotation(myRot);
					
					PRINTLOG(TEXT("%d"), myRotX);
					player->playerMove->a = false;

				}
			}

			else if (240 >= myRotX && myRotX >= 121)
			{
				myRot = FMath::Lerp(myRot, FRotator(0, 0, 120), 10 * GetWorld()->DeltaTimeSeconds);
				SetActorRotation(myRot);
				PRINTLOG(TEXT("%d"), myRotX);
				if (myRotX == 121 || myRotX == 359)
				{
					// µü -120 ÀÌ µÊ
					myRot = FRotator(0.f, 0.f, 120.f);
					myRotX = 120.f;
					SetActorRotation(myRot);
					plusRot = myRot + desRot;
					PRINTLOG(TEXT("%d"), myRotX);
					player->playerMove->a = false;

				}
			}

			else if (360 >= myRotX && myRotX >= 241)
			{
				myRot = FMath::Lerp(myRot, FRotator(0, 0, 240.f), 10 * GetWorld()->DeltaTimeSeconds);
				SetActorRotation(myRot);
				PRINTLOG(TEXT("%d"), myRotX);
				if (myRotX == 240)
				{
					// µü -120 ÀÌ µÊ
					myRot = FRotator(0.f, 0.f, 240.f);
					myRotX = 0.f;
					SetActorRotation(myRot);
					plusRot = myRot + desRot;
					PRINTLOG(TEXT("%d"), myRotX);
					player->playerMove->a = false;

				}
			}
		}

		/// <summary>
		/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// </summary> 


		if (player->playerMove->d == true)
		{
			// 360 º¸´Ù ÀÛ°í -119 º¸´Ù Å¬¶§, ¶Ç´Â 240º¸´Ù Å©°í 360 º¸´Ù ÀÛÀ»¶§
			if (0 <= myRotX && myRotX <= 119 )
			{
				myRot = FMath::Lerp(myRot, FRotator(0.f, 0.f, 120.f), 10 * GetWorld()->DeltaTimeSeconds);
				SetActorRotation(myRot);

				if (myRotX == -119 || myRotX == 119)
				{
					// µü 120 ÀÌ µÊ
					myRot = FRotator(0.f, 0.f, 120.f);
					SetActorRotation(myRot);
					myRotX = 120.f;
					plusRot = myRot + desRot;
					PRINTLOG(TEXT("%d"), myRotX);
					player->playerMove->d = false;

				}

			}

			else if (120 <= myRotX && myRotX <= 239)
			{
				myRot = FMath::Lerp(myRot, plusRot, 10 * GetWorld()->DeltaTimeSeconds);
				SetActorRotation(myRot);
				
				if (myRotX == -239 || myRotX == 239)
				{
					// µü -120 ÀÌ µÊ
					myRot = FRotator(0.f, 0.f, 240.f);
					SetActorRotation(myRot);
					myRotX = 240.f;
					plusRot = myRot + desRot;
					PRINTLOG(TEXT("%d"), myRotX);
					player->playerMove->d = false;

				}

			}

			else if (240 <= myRotX && myRotX <= 359)
			{
				myRot = FMath::Lerp(myRot, plusRot, 10 * GetWorld()->DeltaTimeSeconds);
				SetActorRotation(myRot);
				PRINTLOG(TEXT("%d"), myRotX);
				if (myRotX == -1 || myRotX == 359)
				{
					// µü -120 ÀÌ µÊ
					myRot = FRotator(0.f, 0.f, 0.f);
					myRotX = 0.f;
					SetActorRotation(myRot);
					plusRot = myRot + desRot;
					PRINTLOG(TEXT("%d"), myRotX);
					player->playerMove->d = false;

				}
			}

			else if (-120 <= myRotX && myRotX <= -1)
			{
				myRot = FMath::Lerp(myRot, FRotator(0,0,0), 10 * GetWorld()->DeltaTimeSeconds);
				SetActorRotation(myRot);
				
				PRINTLOG(TEXT("%d"), myRotX);
				if (myRotX == -1)
				{
					// µü -120 ÀÌ µÊ
					myRot = FRotator(0.f, 0.f, 0.f);
					myRotX = 0;
					SetActorRotation(myRot);
					plusRot = myRot + desRot;
					PRINTLOG(TEXT("%d"), myRotX);
					player->playerMove->d = false;

				}
			}

			else if (-240 <= myRotX && myRotX <= -121)
			{
				myRot = FMath::Lerp(myRot, FRotator(0, 0, -120), 10 * GetWorld()->DeltaTimeSeconds);
				SetActorRotation(myRot);
				PRINTLOG(TEXT("%d"), myRotX);
				if (myRotX == -121)
				{
					// µü -120 ÀÌ µÊ
					myRot = FRotator(0.f, 0.f, -120.f);
					myRotX = -120.f;
					SetActorRotation(myRot);
					plusRot = myRot + desRot;
					PRINTLOG(TEXT("%d"), myRotX);
					player->playerMove->d = false;

				}
			}

			else if (-360 <= myRotX && myRotX <= -241)
			{
				myRot = FMath::Lerp(myRot, FRotator(0, 0, -240.f), 10 * GetWorld()->DeltaTimeSeconds);
				SetActorRotation(myRot);
				PRINTLOG(TEXT("%d"), myRotX);
				if (myRotX == -241)
				{
					// µü -120 ÀÌ µÊ
					myRot = FRotator(0.f, 0.f, -240.f);
					myRotX = 0.f;
					SetActorRotation(myRot);
					plusRot = myRot + desRot;
					PRINTLOG(TEXT("%d"), myRotX);
					player->playerMove->d = false;

				}
			}
		}
		
	}
}

void ARotTriangle::RotXReset()
{
	PRINTLOG(TEXT("muyaho"));
	GetWorld()->GetTimerManager().ClearTimer(createTimer);
}


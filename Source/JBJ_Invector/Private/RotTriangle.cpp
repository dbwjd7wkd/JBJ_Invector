// Fill out your copyright notice in the Description page of Project Settings.


#include "RotTriangle.h"
#include "JBJPlayer.h"
#include "PlayerMove.h"
#include "JBJ_Invector.h"
#include <Kismet/GameplayStatics.h>
#include "TimerManager.h"

// Sets default values
ARotTriangle::ARotTriangle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARotTriangle::BeginPlay()
{
	Super::BeginPlay();

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
	// 삼각형을 회전 시키고 싶다.
	// 필요속성 : 회전 속도, 플레이어 키 입력, 회전 방향

	// myRot(나의 Rotation 값) 의 x 값 (int가 가장 정확하니 int 로 체크)
	int32 myRotX = myRot.Roll;

	if (player)
	{
		
		if (player->playerMove->a == true)
		{
			
			
			if (0 >= myRotX && myRotX >= -119 )
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
			if (0 <= myRotX && myRotX <= 119 )
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
				myRot = FMath::Lerp(myRot, FRotator(0,0,0), 20 * GetWorld()->DeltaTimeSeconds);
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

void ARotTriangle::RotXReset()
{
	PRINTLOG(TEXT("muyaho"));
	GetWorld()->GetTimerManager().ClearTimer(createTimer);
}


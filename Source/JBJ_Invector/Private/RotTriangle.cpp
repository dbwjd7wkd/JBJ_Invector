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
	// �ﰢ���� ȸ�� ��Ű�� �ʹ�.
	// �ʿ�Ӽ� : ȸ�� �ӵ�, �÷��̾� Ű �Է�, ȸ�� ����

	// myRot(���� Rotation ��) �� x �� (int�� ���� ��Ȯ�ϴ� int �� üũ)
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
			//PRINTLOG(TEXT("mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"));
			PRINTLOG(TEXT("Progressing %d"), myRotX);
			// 0 ���� �۰� -119 ���� Ŭ��, �Ǵ� 240���� ũ�� 360 ���� ������
			if (0 >= myRotX && myRotX >= -119 ||  240 <= myRotX && myRotX <= 360)
			{
				myRot = FMath::Lerp(myRot, minusRot, 10 * GetWorld()->DeltaTimeSeconds);
				SetActorRotation(myRot);

				if (myRotX == -119 || myRotX == 239)
				{
					// �� -120 �� ��
					myRot = FRotator(0.f, 0.f, -120.f);
					SetActorRotation(myRot);
					minusRot = myRot - desRot;
					PRINTLOG(TEXT("%d"), myRotX);
					player->playerMove->a = false;
					
				}
				
			}
			
			else if (-120 >= myRotX && myRotX >= -239/* || 240 >= myRotX && myRotX >= 120*/)
			{
				myRot = FMath::Lerp(myRot, minusRot, 10 * GetWorld()->DeltaTimeSeconds);
				SetActorRotation(myRot);

				if (myRotX == -239 || myRotX == 120)
				{
					// �� -120 �� ��
					myRot = FRotator(0.f, 0.f, -240.f);
					SetActorRotation(myRot);
					minusRot = myRot - desRot;
					PRINTLOG(TEXT("%d"), myRotX);
					player->playerMove->a = false;

				}

			}

			else if (-240 >= myRotX && myRotX >= -359)
			{
				myRot = FMath::Lerp(myRot, minusRot, 10 * GetWorld()->DeltaTimeSeconds);
				SetActorRotation(myRot);

				if (myRotX == -359)
				{
					// �� -120 �� ��
					myRot = FRotator(0.f, 0.f, 0.f);
					myRotX = 0.f;
					SetActorRotation(myRot);
					minusRot = myRot - desRot;
					PRINTLOG(TEXT("muyaho"));
					PRINTLOG(TEXT("%d"), myRotX);
					player->playerMove->a = false;

				}

			}
		}

		/// <summary>
		/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// </summary> 

		
	}
}

void ARotTriangle::RotXReset()
{
	PRINTLOG(TEXT("muyaho"));
	GetWorld()->GetTimerManager().ClearTimer(createTimer);
}


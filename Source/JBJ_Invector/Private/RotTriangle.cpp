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

	// myRot(���� Rotation ��) �� x ��
	float myRotX = myRot.Roll;
	// desRot(��ǥ Rotation ��) �� x ��
	

	if (player)
	{
		if (player->playerMove->a == true)
		{
			
			myRot = FMath::Lerp(myRot, minusRot, 10 * GetWorld()->DeltaTimeSeconds);
			SetActorRotation(myRot);
			GetWorld()->GetTimerManager().SetTimer(createTimer, this, &ARotTriangle::RotStop, 1.0f, true, 0);
			
				if (myRotX <= -119.5f && myRotX >= -120.5f)
				{
				// �� -120 �� ��
				myRot = FRotator(0.f, 0.f, -120.0f);
				
				player->playerMove->a = false;
				PRINTLOG(TEXT("%f"), myRotX);
				}
		}
	}
}

void ARotTriangle::RotStop()
{
	GetWorld()->GetTimerManager().ClearTimer(createTimer);
}



//// ���� �ﰢ���� Rotation.X �� 120 ���� �۴ٸ� 120 ���� ȸ��
			//if (myRotX < 119.999992f)
			//{
			//	myRot = FMath::Lerp(myRot, desRot1, 30 * GetWorld()->DeltaTimeSeconds);
			//	SetActorRotation(myRot);
			//	PRINTLOG(TEXT("%f"), myRotX);
			//}
			//// ���� �ﰢ���� Rotation.X �� 120 ���ٴ� ũ�� 240 ���� �۴ٸ� 240 ���� ȸ��
			//if (myRotX >= 119.999992f && myRotX < 239.999985f)
			//{
			//	myRot = FMath::Lerp(myRot, desRot2, 25 * GetWorld()->DeltaTimeSeconds);
			//	SetActorRotation(myRot);
			//	PRINTLOG(TEXT("%f"), myRotX);
			//}
			//// ���� �ﰢ���� Rotation.X �� 240 ���ٴ� ũ�� 360 ���� �۴ٸ� 360 ���� ȸ��
			//if (myRotX >= 239.999985f)
			//{
			//	myRot = FMath::Lerp(myRot, desRot3, 25 * GetWorld()->DeltaTimeSeconds);
			//	SetActorRotation(myRot);
			//	PRINTLOG(TEXT("%f"), myRotX);
			//	return;
			//}
			//// ���� �ﰢ���� Rotation.X �� 240 ���ٴ� ũ�� 360 ���� �۴ٸ� 120 ���� ȸ��
			//if (myRotX >= 359.999969)
			//{
			//	myRot = FMath::Lerp(myRot, desRot1, 30 * GetWorld()->DeltaTimeSeconds);
			//	SetActorRotation(myRot);
			//	PRINTLOG(TEXT("%f"), myRotX);
			//}



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
	// 삼각형을 회전 시키고 싶다.
	// 필요속성 : 회전 속도, 플레이어 키 입력, 회전 방향

	// myRot(나의 Rotation 값) 의 x 값
	float myRotX = myRot.Roll;
	// desRot(목표 Rotation 값) 의 x 값
	

	if (player)
	{
		if (player->playerMove->a == true)
		{
			
			myRot = FMath::Lerp(myRot, minusRot, 10 * GetWorld()->DeltaTimeSeconds);
			SetActorRotation(myRot);
			GetWorld()->GetTimerManager().SetTimer(createTimer, this, &ARotTriangle::RotStop, 1.0f, true, 0);
			
				if (myRotX <= -119.5f && myRotX >= -120.5f)
				{
				// 딱 -120 이 됨
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



//// 만약 삼각형의 Rotation.X 가 120 보다 작다면 120 까지 회전
			//if (myRotX < 119.999992f)
			//{
			//	myRot = FMath::Lerp(myRot, desRot1, 30 * GetWorld()->DeltaTimeSeconds);
			//	SetActorRotation(myRot);
			//	PRINTLOG(TEXT("%f"), myRotX);
			//}
			//// 만약 삼각형의 Rotation.X 가 120 보다는 크고 240 보다 작다면 240 까지 회전
			//if (myRotX >= 119.999992f && myRotX < 239.999985f)
			//{
			//	myRot = FMath::Lerp(myRot, desRot2, 25 * GetWorld()->DeltaTimeSeconds);
			//	SetActorRotation(myRot);
			//	PRINTLOG(TEXT("%f"), myRotX);
			//}
			//// 만약 삼각형의 Rotation.X 가 240 보다는 크고 360 보다 작다면 360 까지 회전
			//if (myRotX >= 239.999985f)
			//{
			//	myRot = FMath::Lerp(myRot, desRot3, 25 * GetWorld()->DeltaTimeSeconds);
			//	SetActorRotation(myRot);
			//	PRINTLOG(TEXT("%f"), myRotX);
			//	return;
			//}
			//// 만약 삼각형의 Rotation.X 가 240 보다는 크고 360 보다 작다면 120 까지 회전
			//if (myRotX >= 359.999969)
			//{
			//	myRot = FMath::Lerp(myRot, desRot1, 30 * GetWorld()->DeltaTimeSeconds);
			//	SetActorRotation(myRot);
			//	PRINTLOG(TEXT("%f"), myRotX);
			//}



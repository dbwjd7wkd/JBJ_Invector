// Fill out your copyright notice in the Description page of Project Settings.


#include "JBJPlayer.h"
#include "PlayerMove.h"
#include <Camera/CameraComponent.h>
#include <Components/CapsuleComponent.h>
#include <Components/BoxComponent.h>
#include <Components/StaticMeshComponent.h>
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AJBJPlayer::AJBJPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 태어나면 자동으로 Controller를 갖도록 하자
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// 카메라 컴포넌트 등록
	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	camera->SetupAttachment(GetCapsuleComponent());
	camera->SetRelativeLocation(FVector(-560, 0, 270));
	camera->SetRelativeRotation(FRotator(-20, 0, 0));

	// 메시 컴포넌트 등록
	bodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
	bodyMesh->SetupAttachment(camera);
	bodyMesh->SetRelativeLocation(FVector(647.443542, 0.000000, -122.214050));
	bodyMesh->SetRelativeRotation(FRotator(19.999989, 0.000000, 0.000000));

	// Actor 를 이루는 컴포넌트를 붙이도록 한다.
	playerMove = CreateDefaultSubobject<UPlayerMove>(TEXT("PlayerMove"));

	// 동적으로 파일(애셋) 을 로드하여 할당하기
	ConstructorHelpers::FObjectFinder<UStaticMesh> tempMesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO'"));
	
	// 데이터로드가 성공했다면
	if (tempMesh.Succeeded())
	{
		// bodyMesh 에 할당해주기
		bodyMesh->SetStaticMesh(tempMesh.Object);
	}

	GetCharacterMovement()->GravityScale = 1.7f;
}

// Called when the game starts or when spawned
void AJBJPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJBJPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AJBJPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// PlayerMove 컴포넌트의 SetupPlayer 함수를 호출하고 싶다. 
	//playerMove->SetupPlayerInputComponent(PlayerInputComponent);
	
	// 등록된 델리게이트 함수 모조리 실행해 주기
	OnInputDelegate.Broadcast(PlayerInputComponent);
}
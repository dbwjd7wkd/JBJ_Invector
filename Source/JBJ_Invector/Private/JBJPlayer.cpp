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

	// �¾�� �ڵ����� Controller�� ������ ����
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// ī�޶� ������Ʈ ���
	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	camera->SetupAttachment(GetCapsuleComponent());
	camera->SetRelativeLocation(FVector(-560, 0, 270));
	camera->SetRelativeRotation(FRotator(-20, 0, 0));

	// �޽� ������Ʈ ���
	bodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
	bodyMesh->SetupAttachment(camera);
	bodyMesh->SetRelativeLocation(FVector(647.443542, 0.000000, -122.214050));
	bodyMesh->SetRelativeRotation(FRotator(19.999989, 0.000000, 0.000000));

	// Actor �� �̷�� ������Ʈ�� ���̵��� �Ѵ�.
	playerMove = CreateDefaultSubobject<UPlayerMove>(TEXT("PlayerMove"));

	// �������� ����(�ּ�) �� �ε��Ͽ� �Ҵ��ϱ�
	ConstructorHelpers::FObjectFinder<UStaticMesh> tempMesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO'"));
	
	// �����ͷε尡 �����ߴٸ�
	if (tempMesh.Succeeded())
	{
		// bodyMesh �� �Ҵ����ֱ�
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

	// PlayerMove ������Ʈ�� SetupPlayer �Լ��� ȣ���ϰ� �ʹ�. 
	//playerMove->SetupPlayerInputComponent(PlayerInputComponent);
	
	// ��ϵ� ��������Ʈ �Լ� ������ ������ �ֱ�
	OnInputDelegate.Broadcast(PlayerInputComponent);
}
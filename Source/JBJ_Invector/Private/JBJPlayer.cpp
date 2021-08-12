// Fill out your copyright notice in the Description page of Project Settings.


#include "JBJPlayer.h"
#include "PlayerMove.h"
#include "JumpManager.h"
#include <Camera/CameraComponent.h>
#include <Components/CapsuleComponent.h>
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
	//camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	//camera->SetupAttachment(GetCapsuleComponent());
	//camera->SetRelativeLocation(FVector(-665.000000, 0.000000, 270.000000));
	//camera->SetRelativeRotation(FRotator(-20, 0, 0));

	//GetMesh()->SetRelativeLocation(FVector(-42.000000, 0.000000, -66.000000));
	//GetMesh()->SetRelativeRotation(FRotator(0, 0, 0));
	//GetMesh()->SetRelativeScale3D(FVector(0.15, 0.15, 0.15));

	// �޽� ������Ʈ ���
	bodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
	bodyMesh->SetupAttachment(GetCapsuleComponent());
	bodyMesh->SetRelativeLocation(FVector(-42.000000, 0.000000, -66.000000));
	bodyMesh->SetRelativeRotation(FRotator(0.000000, 0, 0.000000));
	bodyMesh->SetRelativeScale3D(FVector(0.15, 0.15, 0.15));

	// cube1, cube2 ������Ʈ ���
	cube1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube1"));
	cube1->SetupAttachment(GetCapsuleComponent());
	cube1->SetRelativeLocation(FVector(100.000000, -150.000000, 40.000000));
	cube1->SetRelativeScale3D(FVector(0.300000, 0.300000, 0.300000));
	cube1->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	cube2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube2"));
	cube2->SetupAttachment(GetCapsuleComponent());
	cube2->SetRelativeLocation(FVector(100.000000, 150.000000, 40.000000));
	cube2->SetRelativeScale3D(FVector(0.300000, 0.300000, 0.300000));
	cube2->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// Actor �� �̷�� ������Ʈ�� ���̵��� �Ѵ�.
	playerMove = CreateDefaultSubobject<UPlayerMove>(TEXT("PlayerMove"));

	jumpManager = CreateDefaultSubobject<UJumpManager>(TEXT("UJumpManager"));

	// �������� ����(�ּ�) �� �ε��Ͽ� �Ҵ��ϱ�
	ConstructorHelpers::FObjectFinder<UStaticMesh> tempMesh(TEXT("StaticMesh'/Game/YJ/Mesh/JBJPlayerStaticMesh.JBJPlayerStaticMesh'"));
	
	// �����ͷε尡 �����ߴٸ�
	if (tempMesh.Succeeded())
	{
		// bodyMesh �� �Ҵ����ֱ�
		bodyMesh->SetStaticMesh(tempMesh.Object);
	}

	ConstructorHelpers::FObjectFinder<UStaticMesh> tempMesh2(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

	if (tempMesh2.Succeeded())
	{
		cube1->SetStaticMesh(tempMesh2.Object);
		cube2->SetStaticMesh(tempMesh2.Object);
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
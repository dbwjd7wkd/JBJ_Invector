// Fill out your copyright notice in the Description page of Project Settings.


#include "JBJPlayer.h"
#include "PlayerMove.h"
#include "JumpManager.h"
#include <Camera/CameraComponent.h>
#include <Components/CapsuleComponent.h>
#include <Components/StaticMeshComponent.h>
#include "GameFramework/CharacterMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"

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

	// ��ƼŬ ������Ʈ ���
	// �翷
	particle1 = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle1"));
	particle1->SetupAttachment(bodyMesh);
	particle1->SetRelativeLocation(FVector(-800.000000, -40.000000, 193.000000));
	particle1->SetRelativeRotation(FRotator(0.000000, 180.000000, 0.000000));
	particle1->SetRelativeScale3D(FVector(2.000000, 1.000000, 1.000000));
	// �翷
	particle2 = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle2"));
	particle2->SetupAttachment(bodyMesh);
	particle2->SetRelativeLocation(FVector(-800.000000, 40.000000, 193.000000));
	particle2->SetRelativeRotation(FRotator(0.000000, 180.000000, 0.000000));
	particle2->SetRelativeScale3D(FVector(2.000000, 1.000000, 1.000000));
	// �ι�° �ٱ���
	particle3 = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle3"));
	particle3->SetupAttachment(bodyMesh);
	particle3->SetRelativeLocation(FVector(-800.000000, -80.000000, 193.000000));
	particle3->SetRelativeRotation(FRotator(0.000000, 180.000000, 0.000000));
	particle3->SetRelativeScale3D(FVector(5.000000, 1.000000, 1.000000));
	// �ι�° �ٱ���
	particle4 = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle4"));
	particle4->SetupAttachment(bodyMesh);
	particle4->SetRelativeLocation(FVector(-800.000000, 80.000000, 193.000000));
	particle4->SetRelativeRotation(FRotator(0.000000, 180.000000, 0.000000));
	particle4->SetRelativeScale3D(FVector(5.000000, 1.000000, 1.000000));
	// ���
	particle5 = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle5"));
	particle5->SetupAttachment(bodyMesh);
	particle5->SetRelativeLocation(FVector(-800.000000, 00.000000, 193.000000));
	particle5->SetRelativeRotation(FRotator(0.000000, 180.000000, 0.000000));
	particle5->SetRelativeScale3D(FVector(4.000000, 2.000000, 2.000000));
	// ���� �ٱ���
	particle6 = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle6"));
	particle6->SetupAttachment(bodyMesh);
	particle6->SetRelativeLocation(FVector(-800.000000, -250.000000, 193.000000));
	particle6->SetRelativeRotation(FRotator(0.000000, 180.000000, 0.000000));
	particle6->SetRelativeScale3D(FVector(8.000000, 0.5, 0.5));
	// ���� �ٱ���
	particle7 = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle7"));
	particle7->SetupAttachment(bodyMesh);
	particle7->SetRelativeLocation(FVector(-800.000000, 250.000000, 193.000000));
	particle7->SetRelativeRotation(FRotator(0.000000, 180.000000, 0.000000));
	particle7->SetRelativeScale3D(FVector(8.000000, 0.5, 0.5));

	particle3->SetAutoActivate(false);
	particle4->SetAutoActivate(false);
	particle5->SetAutoActivate(false);
	particle6->SetAutoActivate(false);
	particle7->SetAutoActivate(false);

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

	ConstructorHelpers::FObjectFinder<UParticleSystem> tempMesh3(TEXT("ParticleSystem'/Game/VigilanteContent/Vehicles/West_Fighter_F18C/FX/FX_Engine_01_F18C.FX_Engine_01_F18C'"));
	if (tempMesh.Succeeded())
	{
		particle1->SetTemplate(tempMesh3.Object);
		particle2->SetTemplate(tempMesh3.Object);
		particle3->SetTemplate(tempMesh3.Object);
		particle4->SetTemplate(tempMesh3.Object);
		particle5->SetTemplate(tempMesh3.Object);
		particle6->SetTemplate(tempMesh3.Object);
		particle7->SetTemplate(tempMesh3.Object);
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
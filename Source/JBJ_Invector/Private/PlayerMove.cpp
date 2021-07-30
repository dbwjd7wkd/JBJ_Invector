// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMove.h"
#include "JBJPlayer.h"
#include "JBJ_Invector.h"
#include "RotTriangle.h"
#include "A_Pad.h"
#include <Kismet/GameplayStatics.h>
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values for this component's properties
UPlayerMove::UPlayerMove()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	bWantsInitializeComponent = true; //InitializeComponent �Լ� ����ϱ�

	me->GetCharacterMovement()->bOrientRotationToMovement = true;
}

// Called when the game starts
void UPlayerMove::BeginPlay()
{
	Super::BeginPlay();
	
	
}

void UPlayerMove::InitializeComponent()
{
	Super::InitializeComponent();

	// �� ������Ʈ�� �����ϰ� �ִ� ���͸� ��ȯ
	me = Cast<AJBJPlayer>(GetOwner());
	if (me)
	{
		// ��������Ʈ�� �� �Լ��� ����ϰ� �ʹ�.
		me->OnInputDelegate.AddUObject(this, &UPlayerMove::SetupPlayerInputComponent);
		// ������ �� ����
		me->JumpMaxCount = 1;
		//me->GetCharacterMovement()->MaxWalkSpeed = 2000;
	}

	//m_triangle = Cast<ARotTriangle>(UGameplayStatics::GetActorOfClass(GetWorld(), ARotTriangle::StaticClass()));
	aPad = Cast<AA_Pad>(UGameplayStatics::GetActorOfClass(GetWorld(), AA_Pad::StaticClass()));

}

// Called every frame
void UPlayerMove::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ��� ������ �̵�
	if (me)
	{
		// P = P0 + vt
		FVector P0 = me->GetActorLocation();
		FVector dir = FVector::ForwardVector;
		FVector P = P0 + dir * speed * DeltaTime;
		me->SetActorLocation(P, true);
	}

	if (section == 1)
	{
		if (a == true)
		{
			UPlayerMove::MoveToTarget();
		}
	}

}

void UPlayerMove::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// ó���� �Է��Լ� ���ε�
	// Action Input: �����, spacebar, a, d
	// Ű �Է� �� �� �Ӽ����� true�� ����
	PlayerInputComponent->BindAction(TEXT("UpArrowKey"), IE_Pressed, this, &UPlayerMove::UpArrowKey);
	PlayerInputComponent->BindAction(TEXT("DownArrowKey"), IE_Pressed, this, &UPlayerMove::DownArrowKey);
	PlayerInputComponent->BindAction(TEXT("LeftArrowKey"), IE_Pressed, this, &UPlayerMove::LeftArrowKey);
	PlayerInputComponent->BindAction(TEXT("RightArrowKey"), IE_Pressed, this, &UPlayerMove::RightArrowKey);
	PlayerInputComponent->BindAction(TEXT("SpaceBar"), IE_Pressed, this, &UPlayerMove::SpaceBar);
	PlayerInputComponent->BindAction(TEXT("AKey"), IE_Pressed, this, &UPlayerMove::AKey);
	PlayerInputComponent->BindAction(TEXT("DKey"), IE_Pressed, this, &UPlayerMove::DKey);
	// Ű���� �� �� �� �Ӽ����� false�� ����
	PlayerInputComponent->BindAction(TEXT("UpArrowKey"), IE_Released, this, &UPlayerMove::ReleaseUpArrowKey);
	PlayerInputComponent->BindAction(TEXT("DownArrowKey"), IE_Released, this, &UPlayerMove::ReleaseDownArrowKey);
	PlayerInputComponent->BindAction(TEXT("LeftArrowKey"), IE_Released, this, &UPlayerMove::ReleaseLeftArrowKey);
	PlayerInputComponent->BindAction(TEXT("RightArrowKey"), IE_Released, this, &UPlayerMove::ReleaseRightArrowKey);
	PlayerInputComponent->BindAction(TEXT("SpaceBar"), IE_Released, this, &UPlayerMove::ReleaseSpaceBar);
	PlayerInputComponent->BindAction(TEXT("AKey"), IE_Released, this, &UPlayerMove::ReleaseAKey);
	PlayerInputComponent->BindAction(TEXT("DKey"), IE_Released, this, &UPlayerMove::ReleaseDKey);

	//PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &UPlayerMove::Horizontal);
	//PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &UPlayerMove::Vertical);
	//PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &UPlayerMove::Jump);
}

void UPlayerMove::UpArrowKey()
{
	// �� : ����Ŭ��, ���ڸ�����
	up = true;
	PRINTLOG(TEXT("up"));
}

void UPlayerMove::DownArrowKey()
{
	// �� : ����Ŭ��, ���ڸ�����
	down = true;
	PRINTLOG(TEXT("down"));
}

void UPlayerMove::LeftArrowKey()
{
	// �� : ����Ŭ��, ���ڸ�����
	left = true;
	PRINTLOG(TEXT("left"));
}

void UPlayerMove::RightArrowKey()
{
	// �� : ����Ŭ��, ���ڸ�����
	right = true;
	PRINTLOG(TEXT("down"));
}

void UPlayerMove::SpaceBar()
{
	// space bar : ª�� �Ǵ� ��� �� ������
	spaceBar = true;
	PRINTLOG(TEXT("space bar"));
}

void UPlayerMove::AKey()
{
	// a : �������� ����, �������� ����
	a = true;
	PRINTLOG(TEXT("A"));
	me->Jump();
}

void UPlayerMove::DKey()
{
	// d : ���������� ����, ���������� ����
	d = true;
	PRINTLOG(TEXT("D"));
}



void UPlayerMove::ReleaseUpArrowKey()
{
	// �� : ����Ŭ��, ���ڸ�����
	up = false;
	PRINTLOG(TEXT("Release up"));
}

void UPlayerMove::ReleaseDownArrowKey()
{
	// �� : ����Ŭ��, ���ڸ�����
	down = false;
	PRINTLOG(TEXT("Release down"));
}

void UPlayerMove::ReleaseLeftArrowKey()
{
	// �� : ����Ŭ��, ���ڸ�����
	left = false;
	PRINTLOG(TEXT("Release left"));
}

void UPlayerMove::ReleaseRightArrowKey()
{
	// �� : ����Ŭ��, ���ڸ�����
	right = false;
	PRINTLOG(TEXT("Release down"));
}

void UPlayerMove::ReleaseSpaceBar()
{
	// space bar : ª�� �Ǵ� ��� �� ������
	spaceBar = false;
	PRINTLOG(TEXT("Release space bar"));
}

void UPlayerMove::ReleaseAKey()
{
	// a : �������� ����, �������� ����
	a = false;
	PRINTLOG(TEXT("Release A"));
}

void UPlayerMove::ReleaseDKey()
{
	// d : ���������� ����, ���������� ����
	//d = false;
	PRINTLOG(TEXT("Release D"));
}

void UPlayerMove::PlayerRot()
{
	// �÷��̾ ȸ�� ��Ű�� �ʹ�.
	// 
	// myRot(���� Rotation ��) �� x ��
	float myRotX = myRot.Roll;

	myRot = me->bodyMesh->GetRelativeRotation();
	plusRot = myRot + desRot;
	minusRot = myRot - desRot;

	if (me)
	{
		myRot = FMath::Lerp(myRot, plusRot, 10 * GetWorld()->DeltaTimeSeconds);
		me->bodyMesh->SetRelativeRotation(myRot);
		PRINTLOG(TEXT("%f"), myRotX);
	}
}



void UPlayerMove::Horizontal(float value)
{
	horizontal = value;
	PRINTLOG(TEXT("%s %f"), TEXT("horizontal: "), horizontal);

	// CharacterMovement
	// ������ ���� (�¿�)
	FVector dir = me->GetControlRotation().Quaternion().GetRightVector();
	me->AddMovementInput(dir, value);
}

void UPlayerMove::Vertical(float value)
{
	vertical = value;
	PRINTLOG(TEXT("%s %f"), TEXT("vertical: "), vertical);

	// ������ ���� (����)
	FVector dir = me->GetControlRotation().Quaternion().GetUpVector();
	me->AddMovementInput(dir, value);
}

void UPlayerMove::Jump()
{
	me->Jump();
	PRINTLOG(TEXT("Jump"));
}

void UPlayerMove::MoveToTarget()
{
	// �÷��̾ �������� ������Ű�� �ʹ�.
	// 1. ������ �ʿ� direction = target - me
	FVector dir = aPad->GetActorLocation() - me->GetActorLocation();
	// 2. �̵��ϰ� �ʹ�.
	me->GetCharacterMovement()->AddImpulse(dir * 30);

	// 3. �̵��ϴ� �������� ���� ����̰� �ʹ�.
	dir.Normalize();
	// me->GetCharacterMovement()->bOrientRotationToMovement = true; // �����ڷ�

	// �ٶ󺸰� ���� ����
	FRotator targetRot = dir.ToOrientationRotator();
	myRot = me->GetActorRotation();

	// lerp �߿� (linear interpolation)
	myRot = FMath::Lerp(myRot, FRotator(0, 0, targetRot.Roll), 5 * GetWorld()->DeltaTimeSeconds);
	
	// -> �ε巴�� ȸ���ϰ� �ʹ�.
	me->bodyMesh->SetWorldRotation(myRot);
}

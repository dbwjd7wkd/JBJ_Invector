// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMove.h"
#include "JBJPlayer.h"
#include "JBJ_Invector.h"

// Sets default values for this component's properties
UPlayerMove::UPlayerMove()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	bWantsInitializeComponent = true; //InitializeComponent �Լ� ����ϱ�
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
	}
}

// Called every frame
void UPlayerMove::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ��� ������ �̵�
	FVector dir = FVector::ForwardVector;
	if (me)
	{
		// P = P0 + vt
		FVector P0 = me->GetActorLocation();
		FVector P = P0 + dir * speed * DeltaTime;
		me->SetActorLocation(P, true);
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
	d = false;
	PRINTLOG(TEXT("Release D"));
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

// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMove.h"
#include "JBJPlayer.h"

// Sets default values for this component's properties
UPlayerMove::UPlayerMove()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	bWantsInitializeComponent = true;
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

	// ����� �Է¿� ���� �����¿�� �̵��ϰ� �ʹ�.
	// 1. ������ �ʿ�
	FVector dir = FVector::ForwardVector;
	// 2. �̵��ϰ� �ʹ�.
	// P = P0 + vt
	if (me)
	{
		FVector P0 = me->GetActorLocation();
		FVector P = P0 + dir * speed * DeltaTime;
		me->SetActorLocation(P, true);
	}
}

void UPlayerMove::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// ó���� �Է��Լ� ���ε�
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &UPlayerMove::Vertical);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &UPlayerMove::Horizontal);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &UPlayerMove::Jump);
}

void UPlayerMove::Horizontal(float value)
{
	// CharacterMovement
	// ������ ���� (�¿�)
	FVector dir = me->GetControlRotation().Quaternion().GetRightVector();

	me->AddMovementInput(dir, value);
}

void UPlayerMove::Vertical(float value)
{
	// ������ ���� (�յ�)
	//FVector dir = FRotationMatrix(me->GetControlRotation()).GetScaledAxis(EAxis::X);
	//FVector dir = FTransform(me->GetControlRotation()).GetRotation().GetForwardVector();
	FVector dir = me->GetControlRotation().Quaternion().GetForwardVector();

	me->AddMovementInput(dir, value);
}

void UPlayerMove::Jump()
{
	me->Jump();
}

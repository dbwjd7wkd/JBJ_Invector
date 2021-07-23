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

	// 이 컴포넌트를 소유하고 있는 액터를 반환
	me = Cast<AJBJPlayer>(GetOwner());
	if (me)
	{
		// 델리게이트에 내 함수를 등록하고 싶다.
		me->OnInputDelegate.AddUObject(this, &UPlayerMove::SetupPlayerInputComponent);
		// 점프를 수 조절
		me->JumpMaxCount = 1;
	}
}

// Called every frame
void UPlayerMove::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// 사용자 입력에 따라 상하좌우로 이동하고 싶다.
	// 1. 방향이 필요
	FVector dir = FVector::ForwardVector;
	// 2. 이동하고 싶다.
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
	// 처리할 입력함수 바인딩
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &UPlayerMove::Vertical);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &UPlayerMove::Horizontal);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &UPlayerMove::Jump);
}

void UPlayerMove::Horizontal(float value)
{
	// CharacterMovement
	// 움직일 방향 (좌우)
	FVector dir = me->GetControlRotation().Quaternion().GetRightVector();

	me->AddMovementInput(dir, value);
}

void UPlayerMove::Vertical(float value)
{
	// 움직일 방향 (앞뒤)
	//FVector dir = FRotationMatrix(me->GetControlRotation()).GetScaledAxis(EAxis::X);
	//FVector dir = FTransform(me->GetControlRotation()).GetRotation().GetForwardVector();
	FVector dir = me->GetControlRotation().Quaternion().GetForwardVector();

	me->AddMovementInput(dir, value);
}

void UPlayerMove::Jump()
{
	me->Jump();
}

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
	bWantsInitializeComponent = true; //InitializeComponent 함수 사용하기
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

	// 계속 앞으로 이동
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
	// 처리할 입력함수 바인딩
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &UPlayerMove::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &UPlayerMove::MoveRight);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &UPlayerMove::Jump);
}

void UPlayerMove::MoveForward(float value)
{
	forward = value;
	PRINTLOG(TEXT("%s %f"), TEXT("Forward: "), forward);

	// CharacterMovement
	// 움직일 방향 (앞뒤)
	FVector dir = me->GetControlRotation().Quaternion().GetForwardVector();
	me->AddMovementInput(dir, value);
}

void UPlayerMove::MoveRight(float value)
{
	right = value;
	PRINTLOG(TEXT("%s %f"), TEXT("Right: "), right);

	// 움직일 방향 (좌우)
	FVector dir = me->GetControlRotation().Quaternion().GetRightVector();
	me->AddMovementInput(dir, value);
}

void UPlayerMove::Jump()
{
	me->Jump();
}

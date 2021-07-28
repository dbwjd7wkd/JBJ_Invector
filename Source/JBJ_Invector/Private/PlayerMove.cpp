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
	// Action Input: →←↑↓, spacebar, a, d
	// 키 입력 시 각 속성변수 true로 만듦
	PlayerInputComponent->BindAction(TEXT("UpArrowKey"), IE_Pressed, this, &UPlayerMove::UpArrowKey);
	PlayerInputComponent->BindAction(TEXT("DownArrowKey"), IE_Pressed, this, &UPlayerMove::DownArrowKey);
	PlayerInputComponent->BindAction(TEXT("LeftArrowKey"), IE_Pressed, this, &UPlayerMove::LeftArrowKey);
	PlayerInputComponent->BindAction(TEXT("RightArrowKey"), IE_Pressed, this, &UPlayerMove::RightArrowKey);
	PlayerInputComponent->BindAction(TEXT("SpaceBar"), IE_Pressed, this, &UPlayerMove::SpaceBar);
	PlayerInputComponent->BindAction(TEXT("AKey"), IE_Pressed, this, &UPlayerMove::AKey);
	PlayerInputComponent->BindAction(TEXT("DKey"), IE_Pressed, this, &UPlayerMove::DKey);
	// 키에서 뗄 시 각 속성변수 false로 만듦
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
	// ↑ : 발판클릭, 제자리점프
	up = true;
	PRINTLOG(TEXT("up"));
}

void UPlayerMove::DownArrowKey()
{
	// ↓ : 발판클릭, 제자리점프
	down = true;
	PRINTLOG(TEXT("down"));
}

void UPlayerMove::LeftArrowKey()
{
	// ← : 발판클릭, 제자리점프
	left = true;
	PRINTLOG(TEXT("left"));
}

void UPlayerMove::RightArrowKey()
{
	// → : 발판클릭, 제자리점프
	right = true;
	PRINTLOG(TEXT("down"));
}

void UPlayerMove::SpaceBar()
{
	// space bar : 짧게 또는 길게 빛 나오기
	spaceBar = true;
	PRINTLOG(TEXT("space bar"));
}

void UPlayerMove::AKey()
{
	// a : 왼쪽으로 돌기, 왼쪽으로 점프
	a = true;
	PRINTLOG(TEXT("A"));
}

void UPlayerMove::DKey()
{
	// d : 오른쪽으로 돌기, 오른쪽으로 점프
	d = true;
	PRINTLOG(TEXT("D"));
}



void UPlayerMove::ReleaseUpArrowKey()
{
	// ↑ : 발판클릭, 제자리점프
	up = false;
	PRINTLOG(TEXT("Release up"));
}

void UPlayerMove::ReleaseDownArrowKey()
{
	// ↓ : 발판클릭, 제자리점프
	down = false;
	PRINTLOG(TEXT("Release down"));
}

void UPlayerMove::ReleaseLeftArrowKey()
{
	// ← : 발판클릭, 제자리점프
	left = false;
	PRINTLOG(TEXT("Release left"));
}

void UPlayerMove::ReleaseRightArrowKey()
{
	// → : 발판클릭, 제자리점프
	right = false;
	PRINTLOG(TEXT("Release down"));
}

void UPlayerMove::ReleaseSpaceBar()
{
	// space bar : 짧게 또는 길게 빛 나오기
	spaceBar = false;
	PRINTLOG(TEXT("Release space bar"));
}

void UPlayerMove::ReleaseAKey()
{
	// a : 왼쪽으로 돌기, 왼쪽으로 점프
	a = false;
	PRINTLOG(TEXT("Release A"));
}

void UPlayerMove::ReleaseDKey()
{
	// d : 오른쪽으로 돌기, 오른쪽으로 점프
	d = false;
	PRINTLOG(TEXT("Release D"));
}



void UPlayerMove::Horizontal(float value)
{
	horizontal = value;
	PRINTLOG(TEXT("%s %f"), TEXT("horizontal: "), horizontal);

	// CharacterMovement
	// 움직일 방향 (좌우)
	FVector dir = me->GetControlRotation().Quaternion().GetRightVector();
	me->AddMovementInput(dir, value);
}

void UPlayerMove::Vertical(float value)
{
	vertical = value;
	PRINTLOG(TEXT("%s %f"), TEXT("vertical: "), vertical);

	// 움직일 방향 (상하)
	FVector dir = me->GetControlRotation().Quaternion().GetUpVector();
	me->AddMovementInput(dir, value);
}

void UPlayerMove::Jump()
{
	me->Jump();
	PRINTLOG(TEXT("Jump"));
}

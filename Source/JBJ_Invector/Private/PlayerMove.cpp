// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMove.h"
#include "JBJPlayer.h"
#include "JBJ_Invector.h"
//#include "RotTriangle.h"
//#include "A_Pad.h"
#include <Kismet/GameplayStatics.h>
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

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
		//me->GetCharacterMovement()->MaxWalkSpeed = 2000;
	}

	//m_triangle = Cast<ARotTriangle>(UGameplayStatics::GetActorOfClass(GetWorld(), ARotTriangle::StaticClass()));
	//aPad = Cast<AA_Pad>(UGameplayStatics::GetActorOfClass(GetWorld(), AA_Pad::StaticClass()));

}

// Called every frame
void UPlayerMove::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	PRINTLOG(TEXT("time: %f"), currentTime);
	PRINTLOG(TEXT("speed: %f"), speed);
	currentTime += DeltaTime;
	//if (currentTime >= 274.390015)
	//{
	//	speed = 3000;
	//}
	//else if (currentTime >= 278)
	//{
	//	UGameplayStatics::OpenLevel(GetWorld(), TEXT("Outro"));
	//}
	// 계속 앞으로 이동
	if (me)
	{
		// P = P0 + vt
		FVector P0 = me->GetActorLocation();
		FVector dir = me->GetActorForwardVector();
		FVector P = P0 + dir * speed * DeltaTime;
		me->SetActorLocation(P, true);
	}

	if (section == 1) // 점프구간
	{
		//speed = 3000;
		speed2 = 10; // 가속스피드

		if (myA == true || myD == true)
		{
			/*UPlayerMove::MoveToTarget();*/
			UPlayerMove::AccelerateHorizontally();
		}

	}
	else if (section == 0) // 알반구간
	{
		//speed = 1500;

		if (myA == true || myD == true)
		{
			UPlayerMove::PlayerRot();
		}
	}

	if(myA == false && myD == false) UPlayerMove::RotateToTarget();
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
	//PRINTLOG(TEXT("%f"), currentTime);
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
	//PRINTLOG(TEXT("Jump: %f"), frame);
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
	//float check = me->GetActorLocation().X;
	//PRINTLOG(TEXT("%f"), check);
}

void UPlayerMove::AKey()
{
	// a : 왼쪽으로 돌기, 왼쪽으로 점프
	a = true;
	aa = true;
	myA = true;
	PRINTLOG(TEXT("A"));
	UGameplayStatics::PlaySound2D(GetWorld(), adSound);
	if (section == 1)
	{
		if (boundary <= -1)
		{
			myA = false;
			return;
		}
		boundary--;

		targetTransform = me->cube1->GetComponentTransform();
		targetLocation = me->cube1->GetComponentLocation();
		targetRotator = FRotator(-45, 0, -45);

	}
	else if (section == 0)
	{
		desRot = FRotator(0, 0, -1);
	}

}

void UPlayerMove::DKey()
{
	// d : 오른쪽으로 돌기, 오른쪽으로 점프

	d = true;
	dd = true;
	myD = true;
	PRINTLOG(TEXT("D"));
	UGameplayStatics::PlaySound2D(GetWorld(), adSound);
	if (section == 1)
	{
		if (boundary >= 1)
		{
			myD = false;
			return;
		}
		boundary++;

		targetTransform = me->cube2->GetComponentTransform();
		targetLocation = me->cube2->GetComponentLocation();
		targetRotator = FRotator(-45, 0, 45);

	}
	else if (section == 0)
	{
		desRot = FRotator(0, 0, 1);
	}
}




void UPlayerMove::PlayerRot()
{
	// 플레이어를 회전 시키고 싶다.
	// 
	// myRot(나의 Rotation 값) 의 x 값

	myRot = me->bodyMesh->GetRelativeRotation();
	FRotator plusRot = myRot + desRot;

	float myRotX = myRot.Roll;

	if (me)
	{
		myRot = FMath::Lerp(myRot, plusRot, 1000 * GetWorld()->DeltaTimeSeconds);
		me->bodyMesh->SetRelativeRotation(myRot);
	}

	if (myA == true && (1 <= myRot.Roll && myRot.Roll <= 12))
	{
		myA = false;
	}
	else if (myD == true && (-12 < myRot.Roll && myRot.Roll <= -1))
	{
		myD = false;
	}

}

void UPlayerMove::MoveToTarget()
{
	//me->GetCharacterMovement()->SetJumpAllowed(false);
	/*UPlayerMove::Jump();*/
	//mul1 = 50;
	//mul2 = 900;
	//mul3 = 1000;
	// 플레이어를 왼쪽으로 점프시키고 싶다.
	// 1. 방향이 필요 direction = target - me
	FVector myLocation = me->GetActorLocation();

	float y = me->GetTransform().GetRelativeTransform(targetTransform).GetLocation().Y; // targetTransform 은 a 키를 누르면 갱신됨
	float x = me->GetTransform().GetRelativeTransform(targetTransform).GetLocation().X;
	float z = me->GetTransform().GetRelativeTransform(targetTransform).GetLocation().Z;
	PRINTLOG(TEXT("dirX: %f dirY: %f dirZ: %f"), x, y, z);

	direction = targetLocation - myLocation;

	// 2. 이동하고 싶다.
	//me->GetCharacterMovement()->AddImpulse(direction * 8);
	//me->GetCharacterMovement()->AddImpulse(FVector(direction.X, direction.Y, 0) * 8);
	me->GetCharacterMovement()->AddImpulse(FVector(0, direction.Y, 0) * 200);

	// 3. 이동하는 방향으로 몸체를 회전하고싶다.
	UPlayerMove::RotateToTarget();

	if (-200 <= y && y <= 200) //500
	//if(!me->GetCharacterMovement()->IsFalling())
	{
		targetRotator = FRotator(0, 0, 0);
		// 몸체 방향 원래대로 놓기
		//me->bodyMesh->SetRelativeRotation(FRotator(0, 0, 0));
		// (점프 끝내기 위해) 아래 방향으로 힘 가하기 700 250
		me->GetCharacterMovement()->AddImpulse(FVector(0, -direction.Y*700, direction.Z*250));//700
		//me->GetCharacterMovement()->AddForce(FVector(0, 0, 300));
		//me->GetCharacterMovement()->AddImpulse(FVector(-direction.X, -direction.Y, direction.Z) * 1);

		//if (JBJCameraShake != NULL)
		//{
		//	GetWorld()->GetFirstPlayerController()->PlayerCameraManager->PlayCameraShake(JBJCameraShake, 1.0f);
		//}

		myA = false;
		myD = false;

		return;
	}


	//if (-30 <= dir.Y && dir.Y <= 0)
	//{
	//	me->GetCharacterMovement()->AddImpulse(FVector(0, dir.Y, dir.Z) * 100);
	//}
	//else
	//{
	//me->GetCharacterMovement()->AddImpulse(FVector(0, dir.Y, 0) * 100);
	//}

}

void UPlayerMove::RotateToTarget()
{
	//// 몸체 점프하는 방향으로 회전하기
	//FVector dir = aPad->GetActorLocation() - me->GetActorLocation();
	//dir.Normalize();
	//FRotator targetRot = dir.ToOrientationRotator();

	myRot = me->bodyMesh->GetRelativeRotation();

	myRot = FMath::Lerp(myRot, targetRotator, 10 * GetWorld()->DeltaTimeSeconds);
	me->bodyMesh->SetRelativeRotation(myRot);

	//// a 키를 눌렀으면 왼쪽으로 회전
	//if (a == true)
	//{
	//	me->bodyMesh->SetRelativeRotation(FRotator(0, 0, -20));
	//	//me->bodyMesh->SetRelativeRotation(targetRotator);
	//}
	//// d 키를 눌렀으면 오른쪽으로 회전
	//else if (d == true)
	//{
	//	me->bodyMesh->SetRelativeRotation(FRotator(0, 0, 20));
	//}

}

void UPlayerMove::AccelerateHorizontally()
{
	// player 의 로컬좌표계로 바꾸기
	//FTransform dTransform = me->GetTransform();
	//dTransform.SetLocation(direction);
	//float dy = me->GetTransform().GetRelativeTransform(dTransform).GetLocation().Y;
	//direction = FVector(0, dy, 0);
	//PRINTLOG(TEXT("x:%d y:%d z:%d"), direction.X, direction.Y, direction.Z);

	// 앞으로도 가속하는 것처럼 보이게 카메라 줌아웃 해주자
	if (csInstance)
	{
		GetWorld()->GetFirstPlayerController()->PlayerCameraManager->StopCameraShake(csInstance, true);
		csInstance = nullptr;
	}
	csInstance = GetWorld()->GetFirstPlayerController()->PlayerCameraManager->StartCameraShake(cameraShake);

	// 움직이는 방향으로 몸체 방향 돌리기
	UPlayerMove::RotateToTarget();

	// 등속도로 왼쪽이나 오른쪽으로 이동
	FVector myLocation = me->GetActorLocation();
	direction = targetLocation - myLocation; // 목표 방향벡터
	direction = FVector(0, direction.Y, 0); // 좌우로 움직이기위해 y좌표만 빼기

	// speed2 = 점점빨라짐
	speed2 += speed2 * 4;

	// p = p0 + vt;
	FVector P = myLocation + direction * speed2 * GetWorld()->DeltaTimeSeconds;
	me->SetActorLocation(P, true);

	// 목표 지점에 가까워지면 멈추기
	float y = targetLocation.Y - myLocation.Y;
	if ((-1 < y && y < 1))
	{
		// 방향 원래대로 놓기
		targetRotator = FRotator(0, 0, 0);

		// 움직이기 끝
		myA = false;
		myD = false;

		return;
	}

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
	jumpCount++;

	if (jumpSection <= 2) // 점프구간 첫번째 또는 두번째 일 때
	{
		if (1 <= jumpCount && jumpCount <= 2)
		{
			me->GetCharacterMovement()->GravityScale = 1.7f;
		}
		else if (3 <= jumpCount && jumpCount <= 5)
		{
			me->GetCharacterMovement()->GravityScale = 2.3f;
		}

		if (jumpCount >= 5)
		{
			jumpCount = 0;
		}
	}
	else if (jumpSection >= 3) // 점프구간 세번째 일 때
	{
		me->GetCharacterMovement()->GravityScale = 2.3f;
	}

	me->Jump();
	PRINTLOG(TEXT("Jump"));
}




void UPlayerMove::ReleaseUpArrowKey()
{
	// ↑ : 발판클릭, 제자리점프
	//up = false;
	//PRINTLOG(TEXT("Release up"));
}

void UPlayerMove::ReleaseDownArrowKey()
{
	// ↓ : 발판클릭, 제자리점프
	//down = false;
	PRINTLOG(TEXT("Release down"));
}

void UPlayerMove::ReleaseLeftArrowKey()
{
	// ← : 발판클릭, 제자리점프
	//left = false;
	//PRINTLOG(TEXT("Release left"));
}

void UPlayerMove::ReleaseRightArrowKey()
{
	// → : 발판클릭, 제자리점프
	//right = false;
	PRINTLOG(TEXT("Release down"));
}

void UPlayerMove::ReleaseSpaceBar()
{
	// space bar : 짧게 또는 길게 빛 나오기
	spaceBar = false;
	//PRINTLOG(TEXT("Release space bar"));
}

void UPlayerMove::ReleaseAKey()
{
	// a : 왼쪽으로 돌기, 왼쪽으로 점프
	//a = false;
	PRINTLOG(TEXT("Release A"));
}

void UPlayerMove::ReleaseDKey()
{
	// d : 오른쪽으로 돌기, 오른쪽으로 점프
	//d = false;
	PRINTLOG(TEXT("Release D"));
}

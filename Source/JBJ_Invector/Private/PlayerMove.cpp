// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMove.h"
#include "JBJPlayer.h"
#include "JBJ_Invector.h"
//#include "RotTriangle.h"
//#include "A_Pad.h"
#include <Kismet/GameplayStatics.h>
#include "GameFramework/CharacterMovementComponent.h"

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
		//me->GetCharacterMovement()->MaxWalkSpeed = 2000;
	}

	//m_triangle = Cast<ARotTriangle>(UGameplayStatics::GetActorOfClass(GetWorld(), ARotTriangle::StaticClass()));
	//aPad = Cast<AA_Pad>(UGameplayStatics::GetActorOfClass(GetWorld(), AA_Pad::StaticClass()));

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
		FVector dir = me->GetActorForwardVector();
		FVector P = P0 + dir * speed * DeltaTime;
		me->SetActorLocation(P, true);
	}

	if (section == 1) // ��������
	{
		if (a == true)
		{
			UPlayerMove::MoveToTarget();
		}
		else if (d == true)
		{
			UPlayerMove::MoveToTarget();
		}

	}
	else if (section == 0) // �˹ݱ���
	{
		if (a == true || d == true)
		{
			UPlayerMove::PlayerRot();
		}
	}

	if(a == false && d == false) UPlayerMove::RotateToTarget();
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

	if (section == 1)
	{
		if (me->GetCharacterMovement()->IsFalling()) return;

		me->Jump();
		targetTransform = me->cube1->GetComponentTransform();
		targetLocation = me->cube1->GetComponentLocation();
		targetRotator = FRotator(0, 0, -20);
	}
	else if (section == 0)
	{
		desRot = FRotator(0, 0, -1);
	}

}

void UPlayerMove::DKey()
{
	// d : ���������� ����, ���������� ����

	d = true;
	PRINTLOG(TEXT("D"));

	if (section == 1)
	{
		if (me->GetCharacterMovement()->IsFalling()) return;

		me->Jump();
		targetTransform = me->cube2->GetComponentTransform();
		targetLocation = me->cube2->GetComponentLocation();
		targetRotator = FRotator(0, 0, 20);
	}
	else if (section == 0)
	{
		desRot = FRotator(0, 0, 1);
	}
}




void UPlayerMove::PlayerRot()
{
	// �÷��̾ ȸ�� ��Ű�� �ʹ�.
	// 
	// myRot(���� Rotation ��) �� x ��

	myRot = me->bodyMesh->GetRelativeRotation();
	FRotator plusRot = myRot + desRot;

	float myRotX = myRot.Roll;
	PRINTLOG(TEXT("Rot.Roll: %f"), myRotX);

	if (me)
	{
		myRot = FMath::Lerp(myRot, plusRot, 1000 * GetWorld()->DeltaTimeSeconds);
		me->bodyMesh->SetRelativeRotation(myRot);
	}

	if (a == true && (1 <= myRot.Roll && myRot.Roll <= 12))
	{
		a = false;
	}
	else if (d == true && (-12 < myRot.Roll && myRot.Roll <= -1))
	{
		d = false;
	}

}

void UPlayerMove::MoveToTarget()
{
	// �÷��̾ �������� ������Ű�� �ʹ�.
	// 1. ������ �ʿ� direction = target - me
	FVector myLocation = me->GetActorLocation();

	//if (a == true)
	//{
	//	targetLocation = me->cube1->GetComponentLocation();
	//}
	//else if (d == true)
	//{
	//	targetLocation = me->cube2->GetComponentLocation();
	//}
	float y = me->GetTransform().GetRelativeTransform(targetTransform).GetLocation().Y; // targetTransform �� a Ű�� ������ ���ŵ�
	float x = me->GetTransform().GetRelativeTransform(targetTransform).GetLocation().X;
	float z = me->GetTransform().GetRelativeTransform(targetTransform).GetLocation().Z;
	PRINTLOG(TEXT("dirX: %f dirY: %f dirZ: %f"), x, y, z);


	direction = targetLocation - myLocation;

	// 2. �̵��ϰ� �ʹ�.
	//me->GetCharacterMovement()->AddImpulse(direction * 8);
	//me->GetCharacterMovement()->AddImpulse(FVector(direction.X, direction.Y, 0) * 8);
	me->GetCharacterMovement()->AddImpulse(FVector(direction.X, direction.Y, 0) * 60);

	// 3. �̵��ϴ� �������� ��ü�� ȸ���ϰ�ʹ�.
	UPlayerMove::RotateToTarget();

	if (-200 <= y && y <= 200) //500
	//if(!me->GetCharacterMovement()->IsFalling())
	{
		targetRotator = FRotator(0, 0, 0);
		// ��ü ���� ������� ����
		//me->bodyMesh->SetRelativeRotation(FRotator(0, 0, 0));
		// (���� ������ ����) �Ʒ� �������� �� ���ϱ�
		me->GetCharacterMovement()->AddImpulse(FVector(-direction.X*5, -direction.Y*5, direction.Z) * 700);//400
		//me->GetCharacterMovement()->AddForce(FVector(0, 0, 300));
		//me->GetCharacterMovement()->AddImpulse(FVector(-direction.X, -direction.Y, direction.Z) * 1);

		a = false;
		d = false;

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
	//// ��ü �����ϴ� �������� ȸ���ϱ�
	//FVector dir = aPad->GetActorLocation() - me->GetActorLocation();
	//dir.Normalize();
	//FRotator targetRot = dir.ToOrientationRotator();

	myRot = me->bodyMesh->GetRelativeRotation();

	myRot = FMath::Lerp(myRot, targetRotator, 10 * GetWorld()->DeltaTimeSeconds);
	me->bodyMesh->SetRelativeRotation(myRot);

	//// a Ű�� �������� �������� ȸ��
	//if (a == true)
	//{
	//	me->bodyMesh->SetRelativeRotation(FRotator(0, 0, -20));
	//	//me->bodyMesh->SetRelativeRotation(targetRotator);
	//}
	//// d Ű�� �������� ���������� ȸ��
	//else if (d == true)
	//{
	//	me->bodyMesh->SetRelativeRotation(FRotator(0, 0, 20));
	//}

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




void UPlayerMove::ReleaseUpArrowKey()
{
	// �� : ����Ŭ��, ���ڸ�����
	//up = false;
	PRINTLOG(TEXT("Release up"));
}

void UPlayerMove::ReleaseDownArrowKey()
{
	// �� : ����Ŭ��, ���ڸ�����
	//down = false;
	PRINTLOG(TEXT("Release down"));
}

void UPlayerMove::ReleaseLeftArrowKey()
{
	// �� : ����Ŭ��, ���ڸ�����
	//left = false;
	PRINTLOG(TEXT("Release left"));
}

void UPlayerMove::ReleaseRightArrowKey()
{
	// �� : ����Ŭ��, ���ڸ�����
	//right = false;
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
	//a = false;
	PRINTLOG(TEXT("Release A"));
}

void UPlayerMove::ReleaseDKey()
{
	// d : ���������� ����, ���������� ����
	//d = false;
	PRINTLOG(TEXT("Release D"));
}

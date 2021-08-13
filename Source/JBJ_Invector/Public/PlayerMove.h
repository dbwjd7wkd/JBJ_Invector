// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerMove.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class JBJ_INVECTOR_API UPlayerMove : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerMove();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void InitializeComponent() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

// �Է�Ű ó�� �Լ���
public:
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);

	// <Action Input>
	// ����� : ����Ŭ��, ���ڸ�����
	// space bar : ª�� �Ǵ� ��� �� ������
	// a, d : ���� �Ǵ� ���������� ����, ���� �Ǵ� ���������� ����
	void UpArrowKey();
	void DownArrowKey();
	void LeftArrowKey();
	void RightArrowKey();
	void SpaceBar();
	void AKey();
	void DKey();

	void PlayerRot();
	void MoveToTarget();
	void RotateToTarget();
	void AccelerateHorizontally();

	void ReleaseUpArrowKey();
	void ReleaseDownArrowKey();
	void ReleaseLeftArrowKey();
	void ReleaseRightArrowKey();
	void ReleaseSpaceBar();
	void ReleaseAKey();
	void ReleaseDKey();

	// <Axis Input>
	// ��� ���ϴ� �Լ���
	void Horizontal(float value);
	void Vertical(float value);
	void Jump();

public:
	// ���� ��(seconds)
	UPROPERTY(EditAnywhere, Category = "Setting", BlueprintReadWrite)
		float currentTime = 0;

	// �ʿ�Ӽ� : �̵��ӵ�
	UPROPERTY(EditAnywhere, Category = "Setting", BlueprintReadWrite)
	float speed = 500;
	float speed2 = 10;

	// ����Ű �Է� ����� ���� �Ӽ�
	// ���ǿ��� ���
	bool up = false, down = false, left = false, right = false, spaceBar = false, a = false, d = false, aa = false, dd = false;
	// �÷��̾�� ���
	bool myA = false;
	bool myD = false;
	int32 boundary = 0;
	float horizontal, vertical; // ��� ����

	int32 jumpCount = 0;
	int32 jumpSection = 0;
	//float frame = 0;

	// ���� ����� ���� �Ӽ�
	UPROPERTY(EditAnywhere, Category = "Setting", BlueprintReadWrite)
		float section = 0; // �Ϲݱ���: 0, ��������: 1

	// �Ϲݱ������� a, dŰ ������ ȸ���� �� �ʿ��� �Ӽ�
	UPROPERTY()
		FRotator myRot;

	UPROPERTY()
		FRotator desRot;

	// ������������ a, dŰ ������ ������ �и� �� �ʿ��� �Ӽ�
	UPROPERTY()
		FVector targetLocation;

	UPROPERTY()
		FTransform targetTransform;

	UPROPERTY()
		FRotator targetRotator;

	UPROPERTY()
		FVector direction;


	// ������ �� ī�޶� �ܾƿ� ���� �ּ¼���
	UPROPERTY(EditAnywhere, Category = CameraShake)
		TSubclassOf<class UCameraShakeBase> cameraShake;

	UPROPERTY()
		class UCameraShakeBase* csInstance;

	// camera shake
	//UPROPERTY(EditAnywhere, Category = "JBJCameraShake", BlueprintReadWrite)
	//	TSubclassOf<class UMatineeCameraShake> JBJCameraShake;

private:
	UPROPERTY()
	class AJBJPlayer* me;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
		class USoundBase* adSound;

	//UPROPERTY(VisibleAnywhere, Category = RotTriangle)
	//	class ARotTriangle* m_triangle;

	//UPROPERTY(VisibleAnywhere, Category = APad)
	//	class AA_Pad* aPad;
};

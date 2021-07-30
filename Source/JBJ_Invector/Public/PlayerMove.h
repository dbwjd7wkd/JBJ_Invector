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

	void ReleaseUpArrowKey();
	void ReleaseDownArrowKey();
	void ReleaseLeftArrowKey();
	void ReleaseRightArrowKey();
	void ReleaseSpaceBar();
	void ReleaseAKey();
	void ReleaseDKey();

	void PlayerRot();

	// <Axis Input>
	// ��� ���ϴ� �Լ���
	void Horizontal(float value);
	void Vertical(float value);
	void Jump();

public:
	// �ʿ�Ӽ� : �̵��ӵ�
	UPROPERTY(EditAnywhere, Category = "Setting", BlueprintReadOnly)
	float speed = 500;

	// ����Ű �Է� ����� ���� �Ӽ�
	bool up = false, down = false, left = false, right = false, spaceBar = false, a = false, d = false;
	float horizontal, vertical; // ��� ����

	// ���� ����� ���� �Ӽ�
	float section = 0; // �Ϲݱ���: 0, ��������: 1

	UPROPERTY()
		float currentTime;

	UPROPERTY()
		FRotator myRot;

	UPROPERTY()
		FRotator plusRot;

	UPROPERTY()
		FRotator minusRot;

	UPROPERTY()
		FRotator desRot = FRotator(0.f, 0.f, 120.f);

private:
	UPROPERTY()
	class AJBJPlayer* me;
};

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

// 입력키 처리 함수들
public:
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);

	// <Action Input>
	// ↑↓→← : 발판클릭, 제자리점프
	// space bar : 짧게 또는 길게 빛 나오기
	// a, d : 왼쪽 또는 오른쪽으로 돌기, 왼쪽 또는 오른쪽으로 점프
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
	// 사용 안하는 함수들
	void Horizontal(float value);
	void Vertical(float value);
	void Jump();

public:
	// 필요속성 : 이동속도
	UPROPERTY(EditAnywhere, Category = "Setting", BlueprintReadOnly)
	float speed = 500;

	// 방향키 입력 기억을 위한 속성
	bool up = false, down = false, left = false, right = false, spaceBar = false, a = false, d = false;
	float horizontal, vertical; // 사용 안함

	// 구간 기억을 위한 속성
	float section = 0; // 일반구간: 0, 점프구간: 1

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

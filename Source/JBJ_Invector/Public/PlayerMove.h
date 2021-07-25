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

	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);

	void MoveForward(float value);
	void MoveRight(float value);
	// 점프
	void Jump();

public:
	// 필요속성 : 이동속도
	UPROPERTY(EditAnywhere, Category = "Setting", BlueprintReadOnly)
		float speed = 500;

private:
	UPROPERTY()
		class AJBJPlayer* me;

	// 방향키 입력 기억을 위한 속성
	float forward;
	float right;
};

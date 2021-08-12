// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "JBJPlayer.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FPlayerInputDelegate, class UInputComponent*)

UCLASS()
class JBJ_INVECTOR_API AJBJPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AJBJPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	//PlayerMove 컴포넌트 추가
	UPROPERTY(EditAnywhere, Category = "PlayerMove", BlueprintReadWrite)
		class UPlayerMove* playerMove;

	UPROPERTY(EditAnywhere, Category = "JumpManager", BlueprintReadWrite)
		class UJumpManager* jumpManager;

	// Camera
	//UPROPERTY(EditAnywhere, Category = FPSCamera, BlueprintReadWrite)
	//	class UCameraComponent* camera;

	// StaticMesh
	UPROPERTY(EditAnywhere, Category = "BodyMesh", BlueprintReadWrite)
		class UStaticMeshComponent* bodyMesh;

	// 파티클시스템컴포넌트
	UPROPERTY(EditAnywhere, Category = "Particle1", BlueprintReadWrite)
		class UParticleSystemComponent* particle1;
	UPROPERTY(EditAnywhere, Category = "Particle2", BlueprintReadWrite)
		class UParticleSystemComponent* particle2;
	UPROPERTY(EditAnywhere, Category = "Particle3", BlueprintReadWrite)
		class UParticleSystemComponent* particle3;
	UPROPERTY(EditAnywhere, Category = "Particle4", BlueprintReadWrite)
		class UParticleSystemComponent* particle4;
	UPROPERTY(EditAnywhere, Category = "Particle5", BlueprintReadWrite)
		class UParticleSystemComponent* particle5;
	UPROPERTY(EditAnywhere, Category = "Particle6", BlueprintReadWrite)
		class UParticleSystemComponent* particle6;
	UPROPERTY(EditAnywhere, Category = "Particle7", BlueprintReadWrite)
		class UParticleSystemComponent* particle7;

	// cube1
	UPROPERTY(EditAnywhere, Category = "Cube1", BlueprintReadWrite)
		class UStaticMeshComponent* cube1;
	// cube2
	UPROPERTY(EditAnywhere, Category = "Cube2", BlueprintReadWrite)
		class UStaticMeshComponent* cube2;

	// 사용자 입력처리를 담당할 델리게이트
	FPlayerInputDelegate OnInputDelegate;

};

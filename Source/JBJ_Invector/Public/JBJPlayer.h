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

	//PlayerMove ������Ʈ �߰�
	UPROPERTY(VisibleAnywhere, Category = "PlayerMove")
		class UPlayerMove* playerMove;

	// Camera
	UPROPERTY(VisibleAnywhere, Category = FPSCamera)
		class UCameraComponent* camera;

	// Box Collision
	UPROPERTY(VisibleAnywhere, Category = "Collision")
		class UBoxComponent* collision;
	// StaticMesh
	UPROPERTY(VisibleAnywhere, Category = "BodyMesh")
		class UStaticMeshComponent* bodyMesh;

	// ����� �Է�ó���� ����� ��������Ʈ
	FPlayerInputDelegate OnInputDelegate;

};

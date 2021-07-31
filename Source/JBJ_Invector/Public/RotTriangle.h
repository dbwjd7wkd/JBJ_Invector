// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotTriangle.generated.h"

UCLASS()
class JBJ_INVECTOR_API ARotTriangle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARotTriangle();

	UPROPERTY(VisibleAnywhere, Category = "Component")
		class UBoxComponent* rotTest;

	UPROPERTY(VisibleAnywhere, Category = "Component")
		class UStaticMeshComponent* meshComp;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
		class AJBJPlayer* player;

	void Rot();

	void RotStop();

public:

	UPROPERTY()
		float currentTime;

	UPROPERTY()
		FRotator myRot;

	UPROPERTY()
		FRotator plusRot;

	UPROPERTY()
		FRotator minusRot;
	
public:
	UPROPERTY()
		FRotator desRot = FRotator(0.f, 0.f, 120.f);

	UPROPERTY()
		FTimerHandle createTimer;

	UPROPERTY()
		float idleTime = 1.f;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Left_Pad.generated.h"

UCLASS()
class JBJ_INVECTOR_API ALeft_Pad : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALeft_Pad();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
		class AJBJ_InvectorGameMode* myGameMode;

	UPROPERTY(VisibleAnywhere, Category = "Component")
		class UBoxComponent* boxComp;

	UPROPERTY(VisibleAnywhere, Category = "Component")
		class UBoxComponent* boxCompPerfect;

	UPROPERTY(VisibleAnywhere, Category = "Component")
		class UBoxComponent* boxCompPerfect2;

	UPROPERTY(VisibleAnywhere, Category = "Component")
		class UBoxComponent* boxCompGreat;

	UPROPERTY(VisibleAnywhere, Category = "Component")
		class UBoxComponent* boxCompGreat2;

	UPROPERTY(VisibleAnywhere, Category = "Component")
		class UBoxComponent* boxCompBad;

	UPROPERTY(VisibleAnywhere, Category = "Component")
		class UBoxComponent* boxCompBad2;

	UPROPERTY(VisibleAnywhere, Category = "Component")
		class UStaticMeshComponent* meshComp;

	UFUNCTION()
		void OnCollisionPerfect(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnCollisionGreat(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnCollisionBad(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY()
		bool overlapCheck = false;

public:
	UPROPERTY(EditAnywhere, Category = "Setting")
		float speed = 1500;

public:
	UPROPERTY(EditAnywhere, Category = "Explosion")
		class UParticleSystem* explosionFactory;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
		class USoundBase* playSound;

	UPROPERTY()
		class AActor* target;

	FVector v;

public:
	UPROPERTY()
		class AJBJPlayer* player;

	UPROPERTY()
		FRotator myRot;

	UPROPERTY()
		FRotator plusRot;

	UPROPERTY()
		FRotator minusRot;

	UPROPERTY()
		FRotator desRot = FRotator(0.f, 0.f, 120);

	UPROPERTY()
		FTimerHandle createTimer;

	UPROPERTY()
		float idleTime = 1.f;

	void Rot();

	UPROPERTY()
	bool checkROt = true;

	UPROPERTY()
	int32 myRotX = myRot.Roll;
};

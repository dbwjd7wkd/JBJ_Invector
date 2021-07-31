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

	UPROPERTY(VisibleAnywhere, Category = "Component")
		class UBoxComponent* boxCompPerfect;

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
		void OnCollisionPerfect(class UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UFUNCTION()
		void OnCollisionGreat(class UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UFUNCTION()
		void OnCollisionBad(class UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY()
		bool overlapCheck = false;
};

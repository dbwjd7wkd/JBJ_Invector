// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayMusic.generated.h"

UCLASS()
class JBJ_INVECTOR_API APlayMusic : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayMusic();

	UPROPERTY(VisibleAnywhere, Category = "Component")
		class UBoxComponent* boxComp;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnCollisionEnter(class UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY()
		bool overlapCheck = false;

	UPROPERTY()
		class AJBJ_InvectorGameMode* gameModeBase;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
		class USoundBase* playMusic;
};

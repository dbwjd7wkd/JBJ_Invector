// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PadManager_Right.generated.h"

UCLASS()
class JBJ_INVECTOR_API APadManager_Right : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APadManager_Right();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, Category = "EnemyFactory")
		TSubclassOf<class AA_Pad> aPadFactory;
	UPROPERTY(EditDefaultsOnly, Category = "EnemyFactory")
		TSubclassOf<class ALeft_Pad> leftPadFactory;

public:
	UPROPERTY()
		float currentTime = 0;
	UPROPERTY()
		int32 check = 0;


	UPROPERTY(EditAnywhere, Category = "Setting")
		float speed = 0;

	UPROPERTY()
		class AActor* target;

	FVector v;
};

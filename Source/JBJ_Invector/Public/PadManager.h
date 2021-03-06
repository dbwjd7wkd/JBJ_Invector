// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PadManager.generated.h"

UCLASS()
class JBJ_INVECTOR_API APadManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APadManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// 필요속성 : 적 공장, 생성시간(일정시간), 경과시간
	UPROPERTY(EditDefaultsOnly, Category = "EnemyFactory")
		TSubclassOf<class AA_Pad> aPadFactory;
	UPROPERTY(EditDefaultsOnly, Category = "EnemyFactory")
		TSubclassOf<class AD_Pad> dPadFactory;
	UPROPERTY(EditDefaultsOnly, Category = "EnemyFactory")
		TSubclassOf<class ALeft_Pad> leftPadFactory;
	UPROPERTY(EditDefaultsOnly, Category = "EnemyFactory")
		TSubclassOf<class ADown_Pad> downPadFactory;
	UPROPERTY(EditDefaultsOnly, Category = "EnemyFactory")
		TSubclassOf<class ASpaceBar_Pad> spacePadFactory;

public:
	UPROPERTY()
		float currentTime = 0;
	UPROPERTY()
	int32 check = 0;


	UPROPERTY(EditAnywhere, Category = "Setting")
		float speed = 500;

	UPROPERTY()
		class AActor* target;

	FVector v;
};

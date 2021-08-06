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
	
	// �ʿ�Ӽ� : �� ����, �����ð�(�����ð�), ����ð�
	UPROPERTY(EditDefaultsOnly, Category = "EnemyFactory")
		TSubclassOf<class AA_Pad> aPadFactory;
	UPROPERTY(EditDefaultsOnly, Category = "EnemyFactory")
		TSubclassOf<class AD_Pad> dPadFactory;
	UPROPERTY(EditDefaultsOnly, Category = "EnemyFactory")
		TSubclassOf<class ALeft_Pad> leftPadFactory;
	UPROPERTY(EditDefaultsOnly, Category = "EnemyFactory")
		TSubclassOf<class ARight_Pad> rightPadFactory;
	UPROPERTY(EditDefaultsOnly, Category = "EnemyFactory")
		TSubclassOf<class AUp_Pad> upPadFactory;
	UPROPERTY(EditDefaultsOnly, Category = "EnemyFactory")
		TSubclassOf<class ADown_Pad> downPadFactory;
	UPROPERTY(EditDefaultsOnly, Category = "EnemyFactory")
		TSubclassOf<class ASpaceBar_Pad> spacePadFactory;

	UPROPERTY(EditAnywhere, Category = "CreateTime")
		float createTime = 1.47f;

	UPROPERTY()
		float currentTime = 0;
};

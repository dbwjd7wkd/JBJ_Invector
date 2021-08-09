// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "JBJ_InvectorGameMode.generated.h"

UCLASS(MinimalAPI)
class AJBJ_InvectorGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AJBJ_InvectorGameMode();

	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION(Category = Score, BlueprintCallable)
	void AddScore(int32 value);

	UFUNCTION(Category = Score, BlueprintCallable)
	int32 GetScore();

	UFUNCTION(Category = Score, BlueprintCallable)
	void MinusPercent(int32 value);

	UFUNCTION(Category = Score, BlueprintCallable)
	int32 GetPercent();

	UFUNCTION(Category = Score, BlueprintCallable)
	void AddCombo(int32 value);

	UFUNCTION(Category = Score, BlueprintCallable)
	int32 GetCombo();

	UFUNCTION(Category = Score, BlueprintCallable)
	void SetIsGoodStr(FString value);

	UFUNCTION(Category = Score, BlueprintCallable)
	FString GetIsGoodStr();

public:
	void SetScorePerfect();
	void SetScoreGreat();
	void SetScoreBad();

public:
	UPROPERTY(EditAnywhere, Category = Score, BlueprintReadWrite)
	int32 score;

	UPROPERTY(EditAnywhere, Category = Score, BlueprintReadWrite)
	int32 percent;

	UPROPERTY(EditAnywhere, Category = Score, BlueprintReadWrite)
	int32 combo;

	UPROPERTY(EditAnywhere, Category = Score, BlueprintReadWrite)
	int32 multiply;

	UPROPERTY(EditAnywhere, Category = Score, BlueprintReadWrite)
	FString isGoodStr;

	UPROPERTY(EditAnywhere, Category = Score, BlueprintReadWrite)
	float currentTime = 0;

	UPROPERTY(EditAnywhere, Category = Score, BlueprintReadWrite)
	bool view = false;

	//UPROPERTY(EditAnywhere, Category = Score, BlueprintReadWrite)
	//int32 viewisGoodStr = 0;

	//UPROPERTY(EditAnywhere, Category = Score, BlueprintReadWrite)
	//int32 preViewisGoodStr = 0;

	//UPROPERTY(EditAnywhere, Category = Score)
	//class UUserWidget* wbp_play;

	//UPROPERTY(EditAnywhere, Category = Score)
	//	TSubclassOf<class UUserWidget> WidgetClass;
};




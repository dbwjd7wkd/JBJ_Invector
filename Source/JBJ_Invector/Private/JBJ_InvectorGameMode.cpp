// Copyright Epic Games, Inc. All Rights Reserved.

#include "JBJ_InvectorGameMode.h"
#include "JBJPlayer.h"
#include "Blueprint/UserWidget.h"

AJBJ_InvectorGameMode::AJBJ_InvectorGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AJBJPlayer::StaticClass();
	PrimaryActorTick.bCanEverTick = true;

	score = 0;
	percent = 100;
	combo = 0;
	multiply = 1;
	isGoodStr = TEXT("Great!");

	//if (wbp_play != nullptr)
	//{
	//	wbp_play->AddToViewport();
	//}
}

void AJBJ_InvectorGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	currentTime++;
	if (currentTime >= 120)
	{
		view = false;
	}
}

void AJBJ_InvectorGameMode::AddScore(int32 value)
{
	// perfect, great �̸� ���� +8
	score += value;
}

int32 AJBJ_InvectorGameMode::GetScore()
{
	return score;
}

void AJBJ_InvectorGameMode::MinusPercent(int32 value)
{
	// bad �� percent--
	percent -= value;
}

int32 AJBJ_InvectorGameMode::GetPercent()
{
	return percent;
}

void AJBJ_InvectorGameMode::AddCombo(int32 value)
{
	// perfect, great �̸� combo++
	if (value >= 1)
	{
		combo++;
	}
	// bad �̸� combo = 0
	else if (value == 0)
	{
		combo = 0;
	}

	// ���� �޺��� 5 �Ѿ�� ������ ���ϴ� multiply++
	if (combo % 5 == 0)
	{
		multiply++;
		if (multiply > 5)
		{
			multiply = 1;
		}
	}

}

int32 AJBJ_InvectorGameMode::GetCombo()
{
	return combo;
}

void AJBJ_InvectorGameMode::SetIsGoodStr(FString value)
{
	// perfect�̸� perfect, great�̸� great,  bad�̸� bad ���
	isGoodStr = value;
}

FString AJBJ_InvectorGameMode::GetIsGoodStr()
{
	return isGoodStr;
}

void AJBJ_InvectorGameMode::SetScorePerfect()
{
	AJBJ_InvectorGameMode::AddScore(8 * multiply);
	AJBJ_InvectorGameMode::AddCombo(1);
	AJBJ_InvectorGameMode::SetIsGoodStr(TEXT("Perfect!"));
	currentTime = 0;
	view = true;
}

void AJBJ_InvectorGameMode::SetScoreGreat()
{
	AJBJ_InvectorGameMode::AddScore(8 * multiply);
	AJBJ_InvectorGameMode::AddCombo(1);
	AJBJ_InvectorGameMode::SetIsGoodStr(TEXT("Great!"));
	currentTime = 0;
	view = true;
}

void AJBJ_InvectorGameMode::SetScoreBad()
{
	AJBJ_InvectorGameMode::MinusPercent(1);
	AJBJ_InvectorGameMode::AddCombo(0);
	AJBJ_InvectorGameMode::SetIsGoodStr(TEXT("Bad!"));
	currentTime = 0;
	view = true;
}

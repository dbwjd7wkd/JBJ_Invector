// Copyright Epic Games, Inc. All Rights Reserved.

#include "JBJ_InvectorGameMode.h"
#include "JBJPlayer.h"

AJBJ_InvectorGameMode::AJBJ_InvectorGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AJBJPlayer::StaticClass();

	score = 0;
	percent = 100;
	combo = 0;
	isGoodStr = TEXT("Great!");
}

void AJBJ_InvectorGameMode::AddScore(int32 value)
{
	// perfect, great 이면 점수 +8

}

int32 AJBJ_InvectorGameMode::GetScore()
{
	return score;
}

void AJBJ_InvectorGameMode::MinusPercent(int32 value)
{
	// bad 면 percent--

}

int32 AJBJ_InvectorGameMode::GetPercent()
{
	return percent;
}

void AJBJ_InvectorGameMode::AddCombo(int32 value)
{
	// perfect, great 이면 combo++
	// bad 이면 combo = 1

}

int32 AJBJ_InvectorGameMode::GetCombo()
{
	return combo;
}

void AJBJ_InvectorGameMode::SetIsGoodStr(FString value)
{
	// perfect이면 perfect, great이면 great,  bad이면 bad 출력

}

FString AJBJ_InvectorGameMode::GetIsGoodStr()
{
	return isGoodStr;
}

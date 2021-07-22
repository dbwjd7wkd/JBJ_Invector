// Copyright Epic Games, Inc. All Rights Reserved.

#include "JBJ_InvectorGameMode.h"
#include "JBJ_InvectorPawn.h"

AJBJ_InvectorGameMode::AJBJ_InvectorGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AJBJ_InvectorPawn::StaticClass();
}


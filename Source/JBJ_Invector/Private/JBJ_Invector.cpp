// Copyright Epic Games, Inc. All Rights Reserved.

#include "JBJ_Invector.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, JBJ_Invector, "JBJ_Invector" );

DEFINE_LOG_CATEGORY(JBJ)

#define APPINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))
#define CALLINFO() UE_LOG(JBJ, Warning, TEXT("%s"), *APPINFO)
#define PRINTLOG(fmt, ...) UE_LOG(JBJ, Warning, TEXT("%s %s"), *APPINFO, *FString::Printf(fmt, ##__VA_ARGS__) )
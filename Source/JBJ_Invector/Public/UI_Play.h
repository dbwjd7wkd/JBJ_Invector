// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_Play.generated.h"

/**
 * 
 */
UCLASS()
class JBJ_INVECTOR_API UUI_Play : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct();
	
public:
	UPROPERTY(Meta = (BindWigetAnim), Meta = (AllowPrivateAccess = true))
	class UWidgetAnimation* ViewIsGood;
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_Play.h"
#include "Blueprint/UserWidget.h"

void UUI_Play::NativeConstruct()
{
	Super::NativeConstruct();

	PlayAnimation(ViewIsGood); // ���� �ִϸ��̼� ����
}
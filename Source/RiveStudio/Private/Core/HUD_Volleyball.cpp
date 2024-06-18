// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/HUD_Volleyball.h"

#include "Blueprint/UserWidget.h"

AHUD_Volleyball::AHUD_Volleyball()
{
	static ConstructorHelpers::FClassFinder<UUserWidget>
	Widget_GameLayer(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Game_Volleyball/Core/HUD/Layers/UW_GameLayersVolleyball.UW_GameLayersVolleyball_C'"));
						 
	check(Widget_GameLayer.Class);

	if(Widget_GameLayer.Succeeded()){Class_Layer_Game = Widget_GameLayer.Class;}

}

void AHUD_Volleyball::BeginPlay()
{
	Super::BeginPlay();

	Layer_Game =  CreateWidget(GetOwningPlayerController(),Class_Layer_Game.Get());
	Layer_Game->AddToViewport();
}



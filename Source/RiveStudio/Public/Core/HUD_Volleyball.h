// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "HUD_Volleyball.generated.h"


UCLASS()
class RIVESTUDIO_API AHUD_Volleyball : public AHUD
{
	GENERATED_BODY()

	AHUD_Volleyball();

	virtual void BeginPlay() override;

	TSubclassOf<UUserWidget> Class_Layer_Game;
	TObjectPtr<UUserWidget> Layer_Game;

};

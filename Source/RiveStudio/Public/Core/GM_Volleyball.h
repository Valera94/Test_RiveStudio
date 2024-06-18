// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GM_Volleyball.generated.h"


UCLASS()
class RIVESTUDIO_API AGM_Volleyball : public AGameModeBase
{
	GENERATED_BODY()

	AGM_Volleyball(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Default|ScoreGame",meta=(AllowPrivateAccess))int MaxScoreFailHitBall = 5;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Default|ScoreGame",meta=(AllowPrivateAccess))int MaxScoreHitBall = 5;
																	
	virtual void InitGameState() override;

};

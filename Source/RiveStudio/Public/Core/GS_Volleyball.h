// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "GS_Volleyball.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegate_GotMaximumScore, bool, isDefeat);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateStateMatch, int, CurrentState);

UCLASS()
class RIVESTUDIO_API AGS_Volleyball : public AGameStateBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable) FDelegate_GotMaximumScore OnDelegate_GotMaximumScore;

	//0 - SpawmAnd Wait To Ready Start Match/Pause
	//1 - Player Get ball
	//2 - We are waiting for the ball to be served
	//3 - We are in the game
	//4 - Goal
	//5 - EndGame
	UPROPERTY(BlueprintCallable,BlueprintAssignable) FDelegateStateMatch	OnDelegateStateMatch;

	 virtual void BeginPlay() override;


	void CalculateResultHitByBallPawn(const bool isMissingHitByBall, const int CurrentResultFromPawn);

public:

	UPROPERTY(BlueprintReadOnly, Category = "Default|ScoreGame") int MaxScoreFailHitBall = 5;
	UPROPERTY(BlueprintReadOnly, Category = "Default|ScoreGame") int MaxScoreHitBall = 5;


};

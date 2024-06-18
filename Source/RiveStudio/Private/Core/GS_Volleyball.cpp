// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/GS_Volleyball.h"

void AGS_Volleyball::BeginPlay()
{
	Super::BeginPlay();


	//Activate Game after 2 second
	FTimerHandle TimerHandle;
	FTimerDelegate TimerDelegate;
	TimerDelegate.BindLambda([this]()
		{
			OnDelegateStateMatch.Broadcast(0);
		});
	GetWorldTimerManager().SetTimer(TimerHandle, TimerDelegate, 1, false, 1);
}

void AGS_Volleyball::CalculateResultHitByBallPawn(const bool isMissingHitByBall, const int CurrentResultFromPawn)
{
	if (isMissingHitByBall)
	{
		if (MaxScoreFailHitBall - CurrentResultFromPawn <= 0)
		{
			OnDelegateStateMatch.Broadcast(5);
			OnDelegate_GotMaximumScore.Broadcast(true);
		}
		else
		{
			OnDelegateStateMatch.Broadcast(4);
		}
	}
	else
	{
		if (MaxScoreHitBall - CurrentResultFromPawn <= 0)
		{
			OnDelegateStateMatch.Broadcast(5);
			OnDelegate_GotMaximumScore.Broadcast(false);
		}
	}
}

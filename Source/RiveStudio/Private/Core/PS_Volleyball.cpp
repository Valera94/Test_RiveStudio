// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/PS_Volleyball.h"
#include "Core/GS_Volleyball.h"

void APS_Volleyball::HitBallResult(const bool isMissingHitByBall)
{
	isMissingHitByBall ? CurrentScoreFailHitBall++ : CurrentScoreHitBall++;

	OnDelegate_HitBall.Broadcast(
		(isMissingHitByBall ? ESignalResultHitBall::ESRWB_DidntHitTheBall : ESignalResultHitBall::ESRWB_HitTheBall),
		(isMissingHitByBall ? CurrentScoreFailHitBall : CurrentScoreHitBall));

	GetWorld()->GetGameState<AGS_Volleyball>()->CalculateResultHitByBallPawn(
		isMissingHitByBall,
		isMissingHitByBall ? CurrentScoreFailHitBall : CurrentScoreHitBall);
}

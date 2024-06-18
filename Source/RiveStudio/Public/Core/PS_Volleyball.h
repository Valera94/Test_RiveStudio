// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "PS_Volleyball.generated.h"


UENUM(BlueprintType)
enum class ESignalResultHitBall : uint8
{
	ESRWB_HitTheBall		UMETA(DisplayName = "Hit The Ball"),
	ESRWB_DidntHitTheBall	UMETA(DisplayName = "Didnt Hit The Ball"),
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegate_HitBall, const ESignalResultHitBall, OnSignalResultHitBall, const int&, CurrentScore);


UCLASS()
class RIVESTUDIO_API APS_Volleyball : public APlayerState
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable) FDelegate_HitBall OnDelegate_HitBall;

	UPROPERTY(BlueprintReadOnly, Category = "Default|ScorePlayer") int CurrentScoreFailHitBall = 0;
	UPROPERTY(BlueprintReadOnly, Category = "Default|ScorePlayer") int CurrentScoreHitBall = 0;

	UFUNCTION(BlueprintCallable) void HitBallResult(const bool isMissingHitByBall);
};

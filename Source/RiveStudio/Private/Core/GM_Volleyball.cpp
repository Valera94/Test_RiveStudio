// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/GM_Volleyball.h"
#include "Core/GS_Volleyball.h"
#include "Core/HUD_Volleyball.h"
#include "Core/PC_Volleyball.h"
#include "Core/PS_Volleyball.h"
#include "Pawn/Pawn_Volleyball.h"

AGM_Volleyball::AGM_Volleyball(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	static ConstructorHelpers::FClassFinder<APawn_Volleyball> PawnGame(TEXT("/Script/Engine.Blueprint'/Game/Game_Volleyball/Core/Pawn_Character_Valleyball.Pawn_Character_Valleyball_C'"));
	check(PawnGame.Class.Get());
	if(PawnGame.Succeeded())
	{
		DefaultPawnClass = PawnGame.Class;
	}

	GameStateClass = AGS_Volleyball::StaticClass();
	PlayerStateClass = APS_Volleyball::StaticClass();
	PlayerControllerClass = APC_Volleyball::StaticClass();
	HUDClass = AHUD_Volleyball::StaticClass();
}

void AGM_Volleyball::InitGameState()
{
	Super::InitGameState();

	if (AGS_Volleyball* L_AGS_Volleyball = GetGameState<AGS_Volleyball>())
	{
		L_AGS_Volleyball->MaxScoreFailHitBall = MaxScoreFailHitBall;
		L_AGS_Volleyball->MaxScoreHitBall = MaxScoreHitBall;
	}
}

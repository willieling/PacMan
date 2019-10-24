// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "PacManGameMode.h"
#include "PacManHUD.h"
#include "PacManCharacter.h"
#include "UObject/ConstructorHelpers.h"

APacManGameMode::APacManGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Blueprints/Pacman"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = APacManHUD::StaticClass();
}

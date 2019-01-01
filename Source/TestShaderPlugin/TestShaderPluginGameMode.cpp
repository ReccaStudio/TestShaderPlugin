// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "TestShaderPluginGameMode.h"
#include "TestShaderPluginPlayerController.h"
#include "TestShaderPluginCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATestShaderPluginGameMode::ATestShaderPluginGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ATestShaderPluginPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
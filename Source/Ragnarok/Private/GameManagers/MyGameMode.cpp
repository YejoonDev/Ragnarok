// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManagers/MyGameMode.h"

#include "Characters/Knight.h"
#include "GameManagers/MyPlayerController.h"

AMyGameMode::AMyGameMode()
{
	DefaultPawnClass = AKnight::StaticClass();
	PlayerControllerClass = AMyPlayerController::StaticClass();
}

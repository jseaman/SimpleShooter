// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void AShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();

	HudScreen = CreateWidget(this, HUDScreenClass);

	if (HudScreen)
		HudScreen->AddToViewport();
}

void AShooterPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	UE_LOG(LogTemp, Error, TEXT("THE GAME HAS ENDED!!!!"));

	HudScreen->RemoveFromViewport();

	if (bIsWinner)
	{
		auto WinScreen = CreateWidget(this, WinScreenClass);

		if (WinScreen)
			WinScreen->AddToViewport();
	}
	else
	{
		auto LoseScreen = CreateWidget(this, LoseScreenClass);

		if (LoseScreen)
			LoseScreen->AddToViewport();
	}
	
	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}
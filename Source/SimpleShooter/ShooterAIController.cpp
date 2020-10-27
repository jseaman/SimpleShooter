// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ShooterCharacter.h"

void AShooterAIController::BeginPlay()
{
	Super::BeginPlay();

	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if (AIBehavior)
	{
		RunBehaviorTree(AIBehavior);

		GetBlackboardComponent()->SetValueAsVector(TEXT("Start Location"), GetPawn()->GetActorLocation());
		GetBlackboardComponent()->SetValueAsVector(TEXT("Player Location"), PlayerPawn->GetActorLocation());
	}
}

void AShooterAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	/*if (LineOfSightTo(PlayerPawn))
	{
		auto PlayerLocation = PlayerPawn->GetActorLocation();

		GetBlackboardComponent()->SetValueAsVector(TEXT("Player Location"), PlayerLocation);
		GetBlackboardComponent()->SetValueAsVector(TEXT("Last Known Player Location"), PlayerLocation);
	}
	else
	{
		GetBlackboardComponent()->ClearValue(TEXT("Player Location"));
	}*/

	/*if (LineOfSightTo(PlayerPawn))
	{
		SetFocus(PlayerPawn); 
		MoveToActor(PlayerPawn, AcceptanceRadius);
	}
	else
	{ 
		ClearFocus(EAIFocusPriority::Gameplay);
		StopMovement();
	}*/
}

bool AShooterAIController::IsDead() const
{
	auto ControlledCharacter = Cast<AShooterCharacter>(GetPawn());

	if (ControlledCharacter)
		return ControlledCharacter->IsDead();

	return true;
}


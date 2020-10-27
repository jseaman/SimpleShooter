// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerLocationIsSeen.h"
#include "Kismet/GameplayStatics.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_PlayerLocationIsSeen::UBTService_PlayerLocationIsSeen()
{
	NodeName = "Update Player Location Is Seen";
}

void UBTService_PlayerLocationIsSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	auto PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if (!PlayerPawn)
		return;

	auto AIController = OwnerComp.GetAIOwner();

	if (!AIController)
		return;

	if (AIController->LineOfSightTo(PlayerPawn))
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), PlayerPawn);
	}
	else
	{
		OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
	}
}

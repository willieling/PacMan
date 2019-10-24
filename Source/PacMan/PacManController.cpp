// Fill out your copyright notice in the Description page of Project Settings.


#include "PacManController.h"
#include "Components/InputComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
APacManController::APacManController()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APacManController::BeginPlay()
{
	Super::BeginPlay();
	UCapsuleComponent* capsuleCollider = GetCapsuleComponent();
	capsuleCollider->OnComponentBeginOverlap.AddDynamic(this, &APacManController::Overlap);

	UE_LOG(LogTemp, Display, TEXT("[PacmanController] Pacman started"));
}

// Called every frame
void APacManController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APacManController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &APacManController::VerticalInput);
	PlayerInputComponent->BindAxis("MoveRight", this, &APacManController::HorizonalInput);

	//todo add "Press R to reset"

	UE_LOG(LogTemp, Display, TEXT("[PacManController] Input registered"));
}

void APacManController::HorizonalInput(float axisValue)
{
	if (axisValue != 0 && Controller != nullptr)
	{
		FRotator const ControlSpaceRot = Controller->GetControlRotation();

		AddMovementInput(FRotationMatrix(ControlSpaceRot).GetScaledAxis(EAxis::X), axisValue * Speed);
	}
}

void APacManController::VerticalInput(float axisValue)
{
	if (axisValue != 0 && Controller != nullptr)
	{
		FRotator const ControlSpaceRot = Controller->GetControlRotation();

		AddMovementInput(FRotationMatrix(ControlSpaceRot).GetScaledAxis(EAxis::Y), axisValue * -Speed);
	}
}

void APacManController::Overlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	FString label = OtherActor->GetActorLabel();
	UE_LOG(LogTemp, Display, TEXT("[PacmanController] Hit %s"), *label);
}


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PacManController.generated.h"

class AController;

UCLASS()
class PACMAN_API APacManController : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APacManController();

	UPROPERTY(EditAnywhere)
		int Speed = 1;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


public:
	void HorizonalInput(float axis);
	void VerticalInput(float axis);
private:
	void Overlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

};

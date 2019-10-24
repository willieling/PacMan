// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterSpawner.h"
#include "Engine/World.h"

// Sets default values
ACharacterSpawner::ACharacterSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACharacterSpawner::BeginPlay()
{
	Super::BeginPlay();
	SpawnCharacter();
}

// Called every frame
void ACharacterSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACharacterSpawner::SpawnCharacter()
{
	FVector position = GetActorLocation();
	FRotator* rotation = new FRotator();

	FActorSpawnParameters spawnParameters;
	spawnParameters.bAllowDuringConstructionScript = true;

	UWorld* world = GetWorld();
	AActor* actor = world->SpawnActor(actorToSpawn, &position, rotation, spawnParameters);
	actor->SetActorLabel(name);

	UE_LOG(LogTemp, Display, TEXT("Spawning character: %s"), *name);
}
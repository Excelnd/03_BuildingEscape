// copyright IHS 2017

#pragma once

#include "Engine.h"
#include "DrawDebugHelpers.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Grabber.generated.h"





UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	// How far ahead of the player can we reach in cm
	float Reach = 100.f;
	
	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UInputComponent* InputComponent = nullptr;

	// Ray=cast and grab what's in reach
	void Grab();

	// Called when grab is released
	void Release();

	// Find (assumed) attatched physics handle
	void FindPhysicsHandleComponent();

	// Setup (assumed) attatched input component
	void SetupInputComponent();

	// Return hit for first physics body in reach
	const FHitResult GetFirstPhysicsBodyInReach();

	// Returns Current start of reach line
	FVector GetReachLineStart();

	// Returns Current end of reach line
	FVector GetReachLineEnd();
};

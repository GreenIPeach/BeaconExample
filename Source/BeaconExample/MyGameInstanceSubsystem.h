// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SampleOnlineBeaconClient.h"
#include "SampleOnlineBeaconHostObject.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MyGameInstanceSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class BEACONEXAMPLE_API UMyGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	// Begin USubsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	// End USubsystem
	
	UFUNCTION(BlueprintCallable)
		bool StartHost();

	UFUNCTION(BlueprintCallable)
		void ConnectClient(FString IP);

private:
	ASampleOnlineBeaconHostObject* HostObject;
	ASampleOnlineBeaconClient* Client;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OnlineBeaconClient.h"
#include "SampleOnlineBeaconClient.generated.h"

/**
 * 
 */
UCLASS()
class BEACONEXAMPLE_API ASampleOnlineBeaconClient : public AOnlineBeaconClient
{
	GENERATED_BODY()
public:
	ASampleOnlineBeaconClient();

	bool ConnectToServer(const FString& IP);



protected:
	virtual void OnFailure() override;
	virtual void OnConnected() override;

	UFUNCTION(Server, Reliable)
	void Server_RequestAccess(const FString& Name);
};

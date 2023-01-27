// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OnlineBeaconHostObject.h"
#include "SampleOnlineBeaconHostObject.generated.h"

/**
 * 
 */
UCLASS()
class BEACONEXAMPLE_API ASampleOnlineBeaconHostObject : public AOnlineBeaconHostObject
{
	GENERATED_BODY()

public:
	ASampleOnlineBeaconHostObject();

protected:
	virtual void OnClientConnected(AOnlineBeaconClient* NewClientActor, UNetConnection* ClientConnection) override;
};

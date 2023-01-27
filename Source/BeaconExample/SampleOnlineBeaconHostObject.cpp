// Fill out your copyright notice in the Description page of Project Settings.


#include "SampleOnlineBeaconHostObject.h"
#include "SampleOnlineBeaconClient.h"

ASampleOnlineBeaconHostObject::ASampleOnlineBeaconHostObject()
{
	ClientBeaconActorClass = ASampleOnlineBeaconClient::StaticClass();
	BeaconTypeName = ClientBeaconActorClass->GetName();
}

void ASampleOnlineBeaconHostObject::OnClientConnected(AOnlineBeaconClient* NewClientActor,
	UNetConnection* ClientConnection)
{
	Super::OnClientConnected(NewClientActor, ClientConnection);

	if(NewClientActor)
	{
		if(GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("Client connected valid"));	
	}else
	{
		if(GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("Client connected invalid"));
	}
}

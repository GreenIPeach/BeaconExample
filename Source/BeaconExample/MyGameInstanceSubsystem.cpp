// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstanceSubsystem.h"
#include "OnlineBeaconHost.h"
#include "SampleOnlineBeaconClient.h"



void UMyGameInstanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	HostObject = nullptr;
	Client = nullptr;
}

void UMyGameInstanceSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

bool UMyGameInstanceSubsystem::StartHost()
{
	UE_LOG(LogTemp,Warning,TEXT("Host started"));
	if(AOnlineBeaconHost* Host = GetWorld()->SpawnActor<AOnlineBeaconHost>(AOnlineBeaconHost::StaticClass()))
	{
		if(Host->InitHost()){
			Host->PauseBeaconRequests(false);
			HostObject = GetWorld()->SpawnActor<ASampleOnlineBeaconHostObject>(ASampleOnlineBeaconHostObject::StaticClass());
			if(HostObject)
			{
				Host->RegisterHost(HostObject);
				return true;
			}
		}
	}
	return false;
}

bool UMyGameInstanceSubsystem::ConnectClient(FString IP)
{
	UE_LOG(LogTemp,Warning,TEXT("Client Connect called"));
	Client = GetWorld()->SpawnActor<ASampleOnlineBeaconClient>(ASampleOnlineBeaconClient::StaticClass());
	if(Client)
	{
		return Client->ConnectToServer(IP);
	}
	return false;
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "SampleOnlineBeaconClient.h"

ASampleOnlineBeaconClient::ASampleOnlineBeaconClient()
{
}

bool ASampleOnlineBeaconClient::ConnectToServer(const FString& IP)
{
	FURL Destincation = FURL(nullptr,*IP,TRAVEL_Absolute);
	return InitClient(Destincation);
}

void ASampleOnlineBeaconClient::OnFailure()
{
	Super::OnFailure();
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("Client failed to connectto host"));	
}

void ASampleOnlineBeaconClient::OnConnected()
{
	Super::OnConnected();
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("Client connected to host"));	
}

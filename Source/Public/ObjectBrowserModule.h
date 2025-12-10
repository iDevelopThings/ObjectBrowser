// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "IObjectBrowserModule.h"

static const FName ObjectBrowserTabName("ObjectBrowser");

/**
* Implements the ObjectBrowser module.
*/
class OBJECTBROWSER_API FObjectBrowserModule : public IObjectBrowserModule
{
public:

	//~ Begin IModuleInterface Interface

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	virtual bool SupportsDynamicReloading() override;

	//~ End IModuleInterface Interface

	static void ExecuteOpenObjectBrowser()
	{
		FGlobalTabmanager::Get()->TryInvokeTab(FTabId(ObjectBrowserTabName));
	}

private:
	// Handles creating the project settings tab.
	TSharedRef<SDockTab> HandleSpawnSettingsTab(const FSpawnTabArgs& SpawnTabArgs);
};
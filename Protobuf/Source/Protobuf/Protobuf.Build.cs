// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class Protobuf : ModuleRules
{
	public Protobuf(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        ShadowVariableWarningLevel = WarningLevel.Off;
        bEnableUndefinedIdentifierWarnings = false;
        bEnableExceptions = true;

        // Default: Disable RTTI!!! dynamic_cast/typeid
        // https://stackoverflow.com/questions/15101859/subclassing-class-from-shared-library-compiled-with-fno-rtti
        // Mac/IOS: https://udn.unrealengine.com/s/feed/0D52L00004lufEfSAI
        // Android: https://udn.unrealengine.com/s/feed/0D52L00004luvgjSAA
        //bUseRTTI = true;

        var PublicDir = Path.Combine(ModuleDirectory, "Public");
        var GoogleDir = Path.Combine(ModuleDirectory, "google");

        PublicIncludePaths.AddRange(new string[] { ModuleDirectory, PublicDir, GoogleDir });
        PrivateIncludePaths.AddRange(new string[] { "Protobuf/Private" });

        PublicDependencyModuleNames.AddRange(new string[] { "Core" });
        PrivateDependencyModuleNames.AddRange(new string[] { "CoreUObject" });

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
        PublicSystemIncludePaths.AddRange(new string[] { ModuleDirectory });

        /*if (Target.Platform == UnrealBuildTool.UnrealTargetPlatform.Win32 ||
            Target.Platform == UnrealBuildTool.UnrealTargetPlatform.Win64)*/
        {
            PublicDefinitions.Add("_CRT_SECURE_NO_WARNINGS");
        }
    }
}

// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE4Project : ModuleRules
{
	public UE4Project(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "AIModule" });
        //"NavigationSystem", "AIModule"Ãß°¡
    }
}

// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class WiTracingSim : ModuleRules
{
	public WiTracingSim(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore",
			// Network Modules
			"Sockets",
			"Networking",
			// Wi Tracing
			"Renderer",
			// Json
			"Json",
			"JsonUtilities",
		});
	}
}

// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class JBJ_Invector : ModuleRules
{
	public JBJ_Invector(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG"});
	}
}

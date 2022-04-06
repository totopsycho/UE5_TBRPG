// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class TBRPG : ModuleRules
{
	public TBRPG(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"HeadMountedDisplay",
			"NavigationSystem",
			"AIModule",
			"GameplayAbilities",
			"GameplayTasks",
			"GameplayTags"
			 });
	}
}

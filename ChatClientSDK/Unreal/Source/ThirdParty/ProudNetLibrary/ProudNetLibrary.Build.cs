// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class ProudNetLibrary : ModuleRules
{
	public ProudNetLibrary(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;
        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "include"));

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            PublicDefinitions.Add("UNICODE");
            PublicDefinitions.Add("_UNICODE");
            // Add the import library
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory,"lib", "x64", "v140", "Release", "ProudNetClient.lib"));
        }
        else if (Target.Platform == UnrealTargetPlatform.IOS)
        {
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "lib", "IOS", "LLVM", "arm64only", "Release", "libProudNetClient.a"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "lib", "IOS", "LLVM", "arm64only", "Release", "libiconv.2.tbd"));
        }
        else if(Target.Platform == UnrealTargetPlatform.Android)
        {
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "lib", "NDK", "r20", "cmake", "clangRelease", "arm64-v8a", "libProudNetClient.a"));
        }

    }
}

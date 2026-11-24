using UnrealBuildTool;
using System.Collections.Generic;

public class JoyBoxGamessTarget : TargetRules
{
    public JoyBoxGamessTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;
        DefaultBuildSettings = BuildSettingsVersion.V5;
        ExtraModuleNames.Add("JoyBoxGamess");
    }
}

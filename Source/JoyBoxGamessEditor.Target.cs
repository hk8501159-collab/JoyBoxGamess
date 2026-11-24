using UnrealBuildTool;
using System.Collections.Generic;

public class JoyBoxGamessEditorTarget : TargetRules
{
    public JoyBoxGamessEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.V5;
        ExtraModuleNames.Add("JoyBoxGamess");
    }
}

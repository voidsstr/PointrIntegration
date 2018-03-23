using ObjCRuntime;

[assembly: LinkWith("Pointr.a", LinkTarget.Simulator | LinkTarget.ArmV6 | LinkTarget.ArmV7, ForceLoad = true, IsCxx = false)]
workspace "Foxigen"
    architecture "x64"
    startproject "CodeDot"
    configurations {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}"

IncludeDir = {}
IncludeDir["GLFW"] = "ThirdParty/glfw/include"
IncludeDir["Glad"] =  "ThirdParty/glad/include"
IncludeDir["glm"] =  "ThirdParty/glm"
IncludeDir["spdlog"] ="ThirdParty/spdlog/include"


group "Dependencies"
	include "ThirdParty/Glfw"
    include "ThirdParty/Glad"
group ""

project "Foxigen"

    location "Foxigen"
    kind "ConsoleApp"
    language "c++"
    cppdialect "C++20"
    staticruntime "on"

	pchheader "dragoncore.h"
	pchsource "Foxigen/src/dragoncore.cpp"


    files{
        "Foxigen/src/**.h",
        "Foxigen/src/**.hpp",
        "Foxigen/src/**.cpp",
        "Foxigen/assets/**"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS"
    }

    includedirs
    {
        "%{prj.name}/assets/",
        "%{prj.name}/src/",
		"%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.spdlog}"
	}
    externalincludedirs{
        "%{IncludeDir.spdlog}"
    }
	links
    {
        "GLFW",
		"Glad",
		"opengl32.lib"
    }

    targetdir( outputdir .. "/Foxigen")
    objdir("bin-int/" .. outputdir .. "/Foxigen")

    filter "system:windows"
    systemversion "latest"

    filter "configurations:Debug"
        defines "DRG_Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "DRG_Release"
        runtime "Release"
        optimize "on"


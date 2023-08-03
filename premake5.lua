workspace "FoxiGen"
    architecture "x64"
    startproject "Engine"
    configurations {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}"


group "Dependencies"
group ""

project "Engine"

    location "Engine"
    kind "ConsoleApp"
    language "c++"
    cppdialect "C++20"
    staticruntime "on"

    files{
        "Engine/src/**.h",
        "Engine/src/**.hpp",
        "Engine/src/**.cpp"
    }


    includedirs
    {
        "%{prj.name}/src/"
	}

    links
    {
		"opengl32.lib"
    }
    targetdir( outputdir)
    objdir("bin-int/" .. outputdir)

    filter "configurations:Debug"
        defines "DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "RELEASE"
        runtime "Release"
        optimize "on"



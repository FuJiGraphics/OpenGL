workspace "OpenGL"
    architecture "x64"
    configurations { "Debug", "Release" }


IncludeDir = {}
IncludeDir["GLFW"] = "Dependencies/glfw/include"
IncludeDir["GLM"] = "Dependencies/glm/glm"
IncludeDir["NRLOG"] = "Dependencies/nrlog/include"
IncludeDir["GLEW"] = "Dependencies/glew/include"

project "OpenGL"
    location "Source"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    staticruntime "on"
    systemversion "latest"

    targetdir ("Build/bin/%{cfg.buildcfg}")
    objdir ("Build/bin-int/%{cfg.buildcfg}")

    pchheader("PCH.h")
    pchsource("Source/pch/PCH.cpp")

    files
    {
        "Source/pch/**.h",
        "Source/pch/**.cpp",
        "Source/src/**.h",
        "Source/src/**.cpp"
    }

    includedirs
    {
        "Source/pch",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.GLM}",
        "%{IncludeDir.NRLOG}",
        "%{IncludeDir.GLEW}"
    }

    links
    {
        "Dependencies/glfw/lib-vc2022/glfw3_mt.lib",
        "Dependencies/nrlog/nrlog_mt.lib",
        "Dependencies/glew/lib/Release/x64/glew32s.lib",
        "Opengl32.lib"
    }

    defines 
    { 
        "GLEW_STATIC" 
    }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        optimize "On"

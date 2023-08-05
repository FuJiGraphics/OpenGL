workspace "OpenGL"
    architecture "x64"
    configurations { "Debug", "Release" }


IncludeDir = {}
IncludeDir["GLFW"] = "Dependencies/glfw/include"
IncludeDir["GLM"] = "Dependencies/glm/glm"

project "OpenGL"
    location "Source"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    staticruntime "off"
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
        "%{IncludeDir.GLM}"
    }

    links
    {
        "Dependencies/glfw/lib-vc2022/glfw3.lib",
        "Opengl32.lib"
    }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        optimize "On"

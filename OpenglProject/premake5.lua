project "OpenglProject"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir("../bin/" .. outputdir .. "/%{prj.name}")
    objdir("../obj/" .. outputdir .. "/%{prj.name}")

    files{
        "src/**.cpp",
        "src/**.c",
        "include/**.h",
        "include/**.hpp",
        "vendor/include/**.hpp",
        "vendor/include/**.h",
        "vendor/include/**.inl",
        "vendor/include/**.cpp"
    }

    includedirs{
        "include",
        "vendor/include"
    }

    libdirs{
        "vendor/lib"
    }

    links{
        "glew32.lib",
        "glew32s.lib",
        "SDL2.lib",
        "SDL2main.lib",
        "SDL2test.lib",
        "opengl32.lib"
    }

    defines{
        "WINDOWNS"
    }

    filter{ "system:windowns", "configurations:Debug" }
        buildoptions "/MTd"
        runtime "Debug"
        symbols "on"

    filter{ "system:windowns", "configurations:Release" }
        buildoptions "/MT"
        runtime "Release"
        optimize "on"
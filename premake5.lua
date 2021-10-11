workspace "Workspace"
    architecture "x86"
    startproject "OpenglProject"

    configurations{
        "Debug",
        "Release"
    }

    

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "OpenglProject"

newaction{
    trigger = "clean",
    description = "Remove all binaries, intermediate binaries and vs files",
    execute = function()
        print("Removing binaries")
        os.rmdir("./bin")
        print("Removing int binaries")
        os.rmdir("./bin-int")
        print("Removing project files")
        os.rmdir("./.vs")
        os.remove("**.sln")
        os.remove("**.vcxproj")
        os.remove("**.vcxproj.filters")
        os.remove("**.vcxproj.users")
        print("Done!")
    end
}
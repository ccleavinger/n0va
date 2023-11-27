workspace "n0va"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release"
    }

output_directory = "%{cfg.buildcfg}/%{cfg.system}-${cfg.architecture}"

    project "Nova"
        location "Nova"
        
        location "C++"
        kind "ConsoleApp"

        targetdir("bin/" .. output_directory .. "/%{prj.name}")
        objdir("bin/" .. output_directory .. "/%{prj.name}")

        files
        {
            "%{prj.name}/**.h",
            "%{prj.name}/**.hpp",
            "%{prj.name}/**.cpp"
        }
        
        VULKAN_SDK = os.getenv("VULKAN_SDK")
        includedirs
        {
            "%{VULKAN_SDK}/Include"
        }
        if os.is("windows") then
            links
            {
                "%{VULKAN_SDK}/Lib/vulkan-1.lib"
            }
        elseif os.is("linux") then
            links
            {
                "%{VULKAN_SDK}/Lib/vulkan-1.so"
            }
        end

        filter "system:windows"
            systemversion "latest"
            cppdialect "C++20"

        filter "configurations:Debug"
            defines "DEBUG"
            symbols "On"
        filter "configurations:Release"
            defines "NDEBUG"
            optimize "On"


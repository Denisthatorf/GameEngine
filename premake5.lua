workspace "GameEngine"
	architecture "x64"

	configurations{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "GameEngine"
	location "GameEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}
	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "10.0.20348.0"

		defines
		{
			"EG_PLATFORM_WINDOWS",
			"ENGINE_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "EG_DEBUG"
		optimize "On"
	filter "configurations:Release"
		defines "EG_RELEASE"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	includedirs
	{
		"GameEngine/vendor/spdlog/include",
		"GameEngine/src"
	}
	
	links
	{
		"GameEngine"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "10.0.20348.0"

		defines
		{
			"EG_PLATFORM_WINDOWS",
			"ENGINE_BUILD_DLL"
		}

	filter "configurations:Debug"
		defines "EG_DEBUG"
		optimize "On"
	filter "configurations:Release"
		defines "EG_RELEASE"
		optimize "On"


 workspace "Minerva"
 architecture "x64"

 configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	
project "Minerva"
	location "Minerva"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "mvpch.h"
	pchsource "Minerva/src/mvpch.cpp"
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
	
	 defines
	 {
		"MV_PLATFORM_WINDOWS",
		"MV_BUILD_DLL"
	 }
	
	 postbuildcommands
	 {
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Test")
	 }
	
	filter "configurations:Debug"
		defines "MV_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "MV_RELEASE"
		optimize "On"
	
	filter "configurations:Dist"
		defines "MV_DIST"
		optimize "On"
	
project "Test"
	location "Test"
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
		"Minerva/vendor/spdlog/include",
		"Minerva/src"
	}
	
	links
	{
		"Minerva"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
	
		defines
		{
		 "MV_PLATFORM_WINDOWS"
		}
	
	filter "configurations:Debug"
		defines "MV_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "MV_RELEASE"
		optimize "On"
	
	filter "configurations:Dist"
		defines "MV_DIST"
		optimize "On"
workspace "project"
	architecture "x86_64"
	startproject "Source"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
		
	flags
	{
		"MultiProcessorCompile"
	}
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["glfw"]		= "%{wks.location}/Source/vendor/glfw/include"
IncludeDir["glad"]		= "%{wks.location}/Source/vendor/glad/include"
IncludeDir["glm"]		= "%{wks.location}/Source/vendor/glm"
IncludeDir["imgui"]		= "%{wks.location}/Source/vendor/imgui"
IncludeDir["stb_image"]	= "%{wks.location}/Source/vendor/stb_image"
-- IncludeDir["freeimage"]	= "%{wks.location}/Source/vendor/FreeImage/Dist/x64"

group "Dependencies"
		include "Source/vendor/glfw"
		include "Source/vendor/glad"
		include "Source/vendor/imgui"
group ""

		include "Source"

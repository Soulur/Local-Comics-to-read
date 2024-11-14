project "Source"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pch.h"
	pchsource "src/pch.cpp"

	files
	{
		"src/**.h",
		"src/**.cpp",

		"vendor/glm/glm/**.hpp",
		"vendor/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE",
		-- spdlog warning c4996
		"_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING",
		"_SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS",
		-- -----------------------------------------

		"FREEIMAGE_LIB",
	}

	includedirs
	{
		"src",
		"vendor/FreeImage/Dist/x64",

		"%{IncludeDir.glfw}",
		"%{IncludeDir.glad}",
		"%{IncludeDir.imgui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
	}

	links
	{
		"glfw",
		"glad",
		"imgui",
		"opengl32.lib",

		"vendor/FreeImage/Dist/x64/FreeImage.lib",
		"vendor/FreeImage/Dist/x64/FreeImage.dll",
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "SL_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		runtime "Release"
		optimize "on"
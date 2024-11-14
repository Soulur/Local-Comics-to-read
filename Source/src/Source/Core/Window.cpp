#include "pch.h"
#include "Window.h"

#ifdef PLATFORM_WINDOWS
#include "Platform/Windows/WindowsWindow.h"
#endif

namespace Source {

	Scope<Window> Window::Create(const WindowProps& props)
	{
#ifdef PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
#else
		return nullptr;
#endif
	}

}
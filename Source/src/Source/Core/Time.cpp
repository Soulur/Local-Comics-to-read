#include "pch.h"
#include "Time.h"

#include <GLFW/glfw3.h>

namespace Source {

	float Time::GetTime()
	{
		return glfwGetTime();
	}
}
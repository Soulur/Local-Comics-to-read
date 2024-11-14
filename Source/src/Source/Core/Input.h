#pragma once

#include "Source/Core/KeyCodes.h"
#include "Source/Core/MouseCodes.h"

#include <glm/glm.hpp>

namespace Source {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}
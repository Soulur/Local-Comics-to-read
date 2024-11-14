#include "pch.h"
#include "Source/Renderer/RenderCommand.h"

namespace Source {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();
}
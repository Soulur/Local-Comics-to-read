#include "pch.h"
#include "Source/Renderer/RendererAPI.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Source {

	RendererAPI::API RendererAPI::s_API = RendererAPI::API::OpenGL;

	Scope<RendererAPI> RendererAPI::Create()
	{
		switch (s_API)
		{
			case RendererAPI::API::None:    std::cout << "RendererAPI::None is currently not supported!" << std::endl; return nullptr;
			case RendererAPI::API::OpenGL:  return CreateScope<OpenGLRendererAPI>();
		}

		std::cout << "Unknown RendererAPI!" << std::endl;
		return nullptr;
	}

}
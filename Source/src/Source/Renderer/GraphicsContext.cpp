#include "pch.h"
#include "Source/Renderer/GraphicsContext.h"
		 
#include "Source/Renderer/RendererAPI.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace Source {

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (RendererAPI::GetAPI())
		{
			case RendererAPI::API::None:    std::cout << "RendererAPI::None is currently not supported!" << std::endl; return nullptr;
			case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}
		
		std::cout << "Unknown RendererAPI!" << std::endl;
		return nullptr;
	}

}
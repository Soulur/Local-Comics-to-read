#include "pch.h"
#include "VertexArray.h"

#include "Source/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h" 

namespace Source {

	Ref<VertexArray> VertexArray::Create()
	{
		
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    std::cout << "RendererAPI::None is currently not supported!" << std::endl; return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexArray>();
		}

		std::cout << "Unknown RendererAPI!" << std::endl;
		return nullptr;
	}

}
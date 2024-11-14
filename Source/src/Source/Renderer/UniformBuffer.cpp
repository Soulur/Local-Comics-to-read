#include "pch.h"
#include "UniformBuffer.h"

#include "Source/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLUniformBuffer.h"

namespace Source {

	Ref<UniformBuffer> UniformBuffer::Create(uint32_t size, uint32_t binding)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    std::cout << "RendererAPI::None is currently not supported!" << std::endl; return nullptr;
		case RendererAPI::API::OpenGL:  return CreateRef<OpenGLUniformBuffer>(size, binding);
		}

		std::cout << "Unknown RendererAPI!" << std::endl;
		return nullptr;
	}
}
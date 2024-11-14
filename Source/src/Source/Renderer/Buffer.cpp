#include "pch.h"
#include "Buffer.h"

#include "Source/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Source {

	Ref<VertexBuffer> VertexBuffer::Create(uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    std::cout << "RendererAPI::None is currently not supported!" << std::endl; return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexBuffer>(size);
		}

		std::cout << "Unknown RendererAPI!" << std::endl;
		return nullptr;
	}

	Ref<VertexBuffer> VertexBuffer::Create(float* verices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    std::cout << "RendererAPI::None is currently not supported!" << std::endl; return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexBuffer>(verices, size);
		}

		std::cout << "Unknown RendererAPI!" << std::endl;
		return nullptr;
	}

	Ref<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t count)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    std::cout << "RendererAPI::None is currently not supported!" << std::endl; return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLIndexBuffer>(indices, count);
		}

		std::cout << "Unknown RendererAPI!" << std::endl;
		return nullptr;
	}

}
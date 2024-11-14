#include "pch.h"
#include "Source/Renderer/Texture.h"

#include "Source/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLTexture.h"

namespace Source {

	Ref<Texture2D> Texture2D::Create(uint32_t width, uint32_t height)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    std::cout << "RendererAPI::None is currently not supported!" << std::endl; return nullptr;
		case RendererAPI::API::OpenGL:  return CreateRef<OpenGLTexture2D>(width, height);
		}

		std::cout << "Unknown RendererAPI!" << std::endl;
		return nullptr;
	}

	Ref<Texture2D> Texture2D::Create(const std::string& path)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    std::cout << "RendererAPI::None is currently not supported!" << std::endl; return nullptr;
		case RendererAPI::API::OpenGL:  return CreateRef<OpenGLTexture2D>(path);
		}

		std::cout << "Unknown RendererAPI!" << std::endl;
		return nullptr;
	}

}
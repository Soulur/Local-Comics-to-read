#include "pch.h"
#include "Shader.h"

#include "Source/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Source {

	Ref<Shader> Shader::Create(const std::string& filePath)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    std::cout << "RendererAPI::None is currently not supported!" << std::endl; return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef <OpenGLShader>(filePath);
		}

		std::cout << "Unknown RendererAPI!" << std::endl;
		return nullptr;
	}
	Ref<Shader> Shader::Create(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    std::cout << "RendererAPI::None is currently not supported!" << std::endl; return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef <OpenGLShader>(name, vertexSrc, fragmentSrc);
		}

		std::cout << "Unknown RendererAPI!" << std::endl;
		return nullptr;
	}

	// ============================  ShaderLibrary  ============================

	void ShaderLibrary::Add(const std::string& name, const Ref<Shader>& shader)
	{
		if (Exists(name)) return;
		m_Shaders[name] = shader;
	}

	void ShaderLibrary::Add(const Ref<Shader>& shader)
	{
		auto& name = shader->GetName();
		m_Shaders[name] = shader;
	}

	Ref<Shader> ShaderLibrary::Load(const std::string& filePath)
	{
		auto shader = Shader::Create(filePath);
		Add(shader);
		return shader;
	}

	Ref<Shader> ShaderLibrary::Load(const std::string& name, const std::string& filePath)
	{
		auto shader = Shader::Create(filePath);
		Add(name , shader);
		return shader;
	}

	Ref<Shader> ShaderLibrary::Get(const std::string& name)
	{
		if (!Exists(name)) return nullptr;
		return	m_Shaders[name];
	}

	bool ShaderLibrary::Exists(const std::string& name) const
	{
		return m_Shaders.find(name) != m_Shaders.end();
	}

}
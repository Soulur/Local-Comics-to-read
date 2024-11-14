#pragma once

#include "Source/Core/Application.h"
#include "Source/Core/Time.h"
#include "Source/Core/Layer.h"

#include "Source/Events/Event.h"

#include "Source/Core/KeyCodes.h"
#include "Source/Core/Input.h"

#include "Source/Renderer/Renderer.h"
#include "Source/Renderer/RenderCommand.h"
#include "Source/Renderer/Camera/OrthographicCameraController.h"
#include "Source/Renderer/Texture.h"


#include "Player/Core/Book.h"

#include "gian/Utils.h"

namespace Source {

	class ExampleLayer : public Layer
	{
	public:
		ExampleLayer();
		virtual ~ExampleLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		virtual void OnUpdate(Timestep ts) override;
		virtual void OnImGuiRender() override;
		virtual void OnEvent(Event& e) override;
	private:
		void CreateCamera(uint32_t width, uint32_t height);
	private:
		Scope<OrthographicCamera> m_Camera;

		Book m_Book;
		std::filesystem::path m_CurrentDirectory;
	};

}
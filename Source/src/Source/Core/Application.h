#pragma once

#include "Source/Core/Window.h"
#include "Source/Core/Layer.h"
#include "Source/Core/LayerStack.h"

#include "Source/Events/Event.h"
#include "Source/Events/ApplicationEvent.h"

#include "Source/ImGui/ImGuiLayer.h"

#include <GLFW/glfw3.h>

namespace Source {

	class Application
	{
	public:
		Application();
		~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverLay(Layer* layer);

		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }
		Window& GetWindow() { return *m_Window; }

		static Application& Get() { return *s_Instance; }

		void Run();
		void Close();
	private:
		bool OnWindowClose(WindowCloseEvent& e);
	private:
		Scope<Window> m_Window;
		LayerStack m_LayerStack;
		ImGuiLayer* m_ImGuiLayer;

		bool m_Running = true;
		bool m_Minimized = false;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
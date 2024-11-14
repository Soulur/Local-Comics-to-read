#include "pch.h"
#include "ExampleLayer.h"

#include "Renderer/Renderer2D.h"

#include <glad/glad.h>
#include <imgui.h>

extern const std::filesystem::path g_Assets = "res/assets";

namespace Source {

	ExampleLayer::ExampleLayer()
		: Layer("LocalComics")
	{
		auto& window = Application::Get().GetWindow();
		CreateCamera(window.GetWidth(), window.GetHeight());

		m_Book.AddBook("res/assets/a");
	}

	void ExampleLayer::OnAttach()
	{
	}

	void ExampleLayer::OnDetach()
	{
	}

	void ExampleLayer::OnUpdate(Timestep ts)
	{
		RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f , 1.0f });
		RenderCommand::Clear();

		if (Input::IsKeyPressed(Key::S))
		{
			auto position = m_Camera->GetPosition();
			position.x -= 0.5f;
			m_Camera->SetPosition(position);
			
		}


		if (Input::IsKeyPressed(Key::LeftControl))
		{
			if (Input::IsKeyPressed(Key::N))
			{
				std::string file = Source::Utils::PlatformUtils::OpenFile(g_Assets);
				
				m_Book.AddBook(file);

			}
		}

	}

	void ExampleLayer::OnImGuiRender()
	{


		// Note: Switch this to true to enable dockspace
		static bool dockspaceOpen = true;
		static bool opt_fullscreen_persistant = true;
		bool opt_fullscreen = opt_fullscreen_persistant;
		static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

		// We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
		// because it would be confusing to have two docking targets within each others.
		ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
		if (opt_fullscreen)
		{
			ImGuiViewport* viewport = ImGui::GetMainViewport();
			ImGui::SetNextWindowPos(viewport->Pos);
			ImGui::SetNextWindowSize(viewport->Size);
			ImGui::SetNextWindowViewport(viewport->ID);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
			window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
			window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
		}

		// When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background and handle the pass-thru hole, so we ask Begin() to not render a background.
		if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
			window_flags |= ImGuiWindowFlags_NoBackground;

		// Important: note that we proceed even if Begin() returns false (aka window is collapsed).
		// This is because we want to keep our DockSpace() active. If a DockSpace() is inactive, 
		// all active windows docked into it will lose their parent and become undocked.
		// We cannot preserve the docking relationship between an active window and an inactive docking, otherwise 
		// any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
		ImGui::Begin("DockSpace Demo", &dockspaceOpen, window_flags);
		ImGui::PopStyleVar();

		if (opt_fullscreen)
			ImGui::PopStyleVar(2);

		// DockSpace
		ImGuiIO& io = ImGui::GetIO();
		if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
		{
			ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
			ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
		}




		{
			ImGui::Begin("Viewport");

			m_Book.ImGuiBook(m_CurrentDirectory);

			ImGui::End();
		}

		{

			ImGui::Begin("Book");
			// ImGui::PushID(filenameString.c_str());
			

			float height = 200.0f;
			float width = height / 1.6f;

			
			static float padding = 16.0f;
			static float thumbnailSize = width;
			float cellSize = thumbnailSize + padding;

			float panelWidth = ImGui::GetContentRegionAvail().x;
			int columnCount = (int)(panelWidth / cellSize);
			if (columnCount < 1)
				columnCount = 1;
			ImGui::Columns(columnCount, 0, false);

			for (const auto& [file, book] : m_Book.Get())
			{
				if (m_Book.Get().find(file) != m_Book.Get().end())
				{
					auto& bd = m_Book.Get().find(file)->second;

					ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0));
					ImGui::ImageButton((ImTextureID)bd.BookCover->GetRendererID(), { thumbnailSize, height }, { 0,1 }, { 1,0 });
					
					ImGui::PopStyleColor();

					if (ImGui::IsItemHovered() && ImGui::IsMouseClicked(ImGuiMouseButton_Left))
					{
						m_CurrentDirectory = file;
					}

					ImGui::TextWrapped(bd.Name.c_str());
					ImGui::NextColumn();
				}
	
			}

			ImGui::Columns(1);


			// ImGui::PopID();

			ImGui::End();
		}





		ImGui::End();









	}

	void ExampleLayer::OnEvent(Event& e)
	{

	}

	void ExampleLayer::CreateCamera(uint32_t width, uint32_t height)
	{
		float aspectRatio = (float)width / (float)height;

		float camWidth = 8.0f;
		float bottom = -camWidth;
		float top = camWidth;
		float left = bottom * aspectRatio;
		float right = top * aspectRatio;

		m_Camera = CreateScope<OrthographicCamera>(left, right, bottom, top);
	}

}
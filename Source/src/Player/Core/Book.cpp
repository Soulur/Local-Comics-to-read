#include "pch.h"
#include "Book.h"

#include "Source/Core/Application.h"

#include "Player/Renderer/Renderer2D.h"

#include <imgui.h>

namespace Source {

	Book::Book()
		: m_Offset(0.1f)
	{
	}

	void Book::AddBook(const std::filesystem::path& path)
	{
		if (!std::filesystem::exists(path))
		{
			std::cout << "not file" << std::endl;
			return;
		}

		BookData bd;
		bd.Name = path.filename().string().c_str();


		bool checkBookCover = false;

		for (auto& dir : std::filesystem::directory_iterator(path))
		{
			const auto& filenameString = dir.path().filename().string();
			// std::cout << filenameString << std::endl;

			std::string imagelocation = path.string() + '/' + filenameString;

			ImageData image;
			if (!checkBookCover)
			{
				bd.BookCover = Texture2D::Create(imagelocation);
				checkBookCover = true;
			}
			image.image = Texture2D::Create(imagelocation);
			image.aspectRatio =  (float)image.image->GetWidth() / (float)image.image->GetHeight();


			bd.ImageAssets.push_back(image);
		}

		m_Data[path] = bd;
	}

	void Book::RenderBook(const std::filesystem::path& path)
	{

	}

	void Book::ImGuiBook(const std::filesystem::path& path)
	{

		if (m_Data.find(path) == m_Data.end())
		{
			std::cout << "RenderBook not file_location" << std::endl;
			return;
		}

		auto& bd = m_Data.find(path)->second;

		auto width = ImGui::GetWindowWidth();
		auto height = ImGui::GetWindowHeight();

		for (auto& data : bd.ImageAssets)
		{

			ImGui::Image((ImTextureID)data.image->GetRendererID(), { width, width / data.aspectRatio }, ImVec2{ 0, 1 }, ImVec2{ 1, 0 });
		}


	}

}
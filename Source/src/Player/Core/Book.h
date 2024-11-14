#pragma once

#include "Source/Renderer/Texture.h"

#include <string>
#include <filesystem>
#include <unordered_map>

namespace Source {

	struct ImageData
	{
		Ref<Texture2D> image;
		float aspectRatio;
	};

	struct BookData
	{
		std::string Name;
		std::filesystem::path Location;
		Ref<Texture2D> BookCover;

		std::vector<ImageData> ImageAssets;
	};

	class Book
	{
	public:
		Book();
		~Book() = default;

		void AddBook(const std::filesystem::path& path);

		void RenderBook(const std::filesystem::path& path);
		
		void ImGuiBook(const std::filesystem::path& path);

		std::unordered_map<std::filesystem::path, BookData>& Get() { return m_Data; }
	private:
		uint32_t m_Offset;
		std::unordered_map<std::filesystem::path, BookData> m_Data;
	};

}
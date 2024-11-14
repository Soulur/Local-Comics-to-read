#pragma once

#include <string>
#include <filesystem>

namespace Source { 
    namespace Utils {

        class PlatformUtils
        {
        public:
            // These return empty strings if cancelled
            static std::string OpenFile(const std::filesystem::path& filter);
        };
    
    }
}
#include "pch.h"
#include "Utils.h"

#include <commdlg.h>
#include <shlobj.h>
#include <locale>
#include <codecvt>


namespace Source {
    namespace Utils {

        PCWSTR StringToPCWSTR(const std::string& str)
        {
            int wideCharCount = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, nullptr, 0);
            wchar_t* wideString = new wchar_t[wideCharCount];
            MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, wideString, wideCharCount);
            return wideString;
        }

        std::string wstringToString(const std::wstring& wstr) {
            std::string str(wstr.begin(), wstr.end());
            return str;
        }

        std::string PlatformUtils::OpenFile(const std::filesystem::path& filter)
        {
            auto path = std::filesystem::canonical(filter);

            BROWSEINFO bi = { 0 };


            ZeroMemory(&bi, sizeof(BROWSEINFO));
            bi.hwndOwner = nullptr;
            bi.pidlRoot = ILCreateFromPath(StringToPCWSTR(path.string().c_str()));
            bi.pszDisplayName = new wchar_t[MAX_PATH];
            bi.lpszTitle = L"Open folder";
            bi.ulFlags = BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE | BIF_NONEWFOLDERBUTTON | BIF_STATUSTEXT;
            bi.lpfn = NULL;
            bi.lParam = 0;
            bi.iImage = -1;

            LPITEMIDLIST idl = SHBrowseForFolder(&bi);

            if (idl != NULL)
            {
                wchar_t szBuffer[MAX_PATH];
                if (SHGetPathFromIDList(idl, szBuffer))
                {
                    CoTaskMemFree(idl);
                    return wstringToString(szBuffer);
                }
            }

            return std::string();
        }
    }
}
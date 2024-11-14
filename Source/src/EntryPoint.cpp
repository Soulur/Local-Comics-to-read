#include "pch.h"
#include "Player/Sandbox.h"

#ifdef PLATFORM_WINDOWS

int main()
{
    auto app = Source::CreateApplication();
    app->Run();
    delete app;


    return 0;
}

#endif

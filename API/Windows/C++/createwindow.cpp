#include <windows.h>
#include <shlobj.h>
#include <stdio.h>

int WINAPI  WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // Learning C++ windows api
    // Message Box
    MessageBoxA(NULL, "Testing testing 123", "Test", MB_OK | MB_ICONINFORMATION);
    
    MessageBoxA(NULL, "The after test", "Test", MB_OKCANCEL | MB_ICONEXCLAMATION);

    return 0;

}

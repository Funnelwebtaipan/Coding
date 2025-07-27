#include <windows.h>
#include <shlobj.h>
#include <stdio.h>

int WINAPI  WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{   
    // Creating a file and writing to it
    const char* log_path = "C:\\Users\\black\\OneDrive\\Desktop\\tada.txt";

    HANDLE hFile = CreateFileA(log_path, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_NEW,FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile != INVALID_HANDLE_VALUE)
    {
        const char* data = "This is a test\n\nThis is a test\n\nThis is a test";
        DWORD bytesWritten;
         if(!WriteFile(hFile, data, strlen(data), &bytesWritten, NULL))
         {
            DWORD errorcode = GetLastError();
            char errorMsg[256];
            wsprintfA(errorMsg, "Write failed with error code %lu", errorcode);
            MessageBoxA(NULL, errorMsg, "Error", MB_OK | MB_ICONERROR);
         }
         CloseHandle(hFile);
    }
    else
    {
        MessageBoxA(NULL, "Failed to Crate .txt document\n", "Error", MB_OK | MB_ICONERROR);
    }

    return 0;
}
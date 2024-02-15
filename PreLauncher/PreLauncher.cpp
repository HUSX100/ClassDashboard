#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    LPWSTR* szArgList;
    int argCount;

    szArgList = CommandLineToArgvW(GetCommandLineW(), &argCount);
    if (szArgList == NULL) 
    {
        MessageBox(NULL, L"Unable to parse command line", L"Error", MB_OK);
        return -1;
    }
	ShellExecute(NULL, L"runas", szArgList[1], NULL, NULL, SW_SHOWNORMAL);
    LocalFree(szArgList);
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <tlhelp32.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include <thread>
#include <tchar.h>
#include <shlobj.h>
using namespace std;

string user_dir;

void fx_get_user_dir()
{
    TCHAR path[MAX_PATH];
    if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_PROFILE, NULL, 0, path)))
    {
        wstring wstrPath(path);
        string strPath(wstrPath.begin(), wstrPath.end());
        user_dir = strPath;
    }
}

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
    fx_get_user_dir();

    wstring ws(szArgList[1]);
    string str(ws.begin(), ws.end());

    if (str == "normal")
    {
        ShellExecute(NULL, L"runas", L"C:\\Class_Dashboard\\MainLauncher.exe", NULL, NULL, SW_SHOWNORMAL);
    }
    if (str == "clock")
    {
        string DEL_filePath = user_dir + "\\AppData\\Roaming\\Rainmeter\\Rainmeter.ini";
        remove(DEL_filePath.c_str());
        string COPY_sourcePath;
        COPY_sourcePath = "C:\\Class_Dashboard\\Rainmeter_cfg\\clock.ini";
        string COPY_destinationPath = user_dir + "\\AppData\\Roaming\\Rainmeter\\Rainmeter.ini";
        filesystem::copy(COPY_sourcePath, COPY_destinationPath);
        SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, (PVOID)"C:\\Class_Dashboard\\Wallpaper\\none.png", SPIF_UPDATEINIFILE);
        ShellExecute(NULL, L"runas", L"C:\\Class_Dashboard\\Rainmeter\\RestartRainmeter.exe", NULL, NULL, SW_SHOWNORMAL);
    }
   
    LocalFree(szArgList);
    return 0;
}

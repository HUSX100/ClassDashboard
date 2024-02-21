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

int toUnicode(const char* str)
{
    return str[0] + (str[1] ? toUnicode(str + 1) : 0);
}

constexpr inline int U(const char* str)
{
    return str[0] + (str[1] ? U(str + 1) : 0);
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

    string config[20]{};
    string Subjects[9]{};

    FILE* n_cfg = freopen("C:\\Class_Dashboard\\n_config.ini", "r", stdin);
    if (n_cfg != 0) fseek(n_cfg, 0, SEEK_SET);
    for (int i = 0; i <= 19; i++) cin >> config[i];
    if (n_cfg != 0) fclose(n_cfg);
    cin.clear();
    
    FILE* subject = freopen("C:\\Class_Dashboard\\Week\\Subject.ini", "r", stdin);
    if (subject != 0) fseek(subject, 0, SEEK_SET);
    for (int i = 0; i <= 7; i++) cin >> Subjects[i];
    if (subject != 0) fclose(subject);
    cin.clear();

    switch (toUnicode(str.c_str()))
    {
    case U("Normal"):
    {
        ShellExecute(NULL, L"runas", L"C:\\Class_Dashboard\\MainLauncher.exe", NULL, NULL, SW_SHOWNORMAL);
    }
    case U("Clock"):
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
    case U("Chinese"):
        config[19] = Subjects[0];
        ShellExecute(NULL, L"runas", L"C:\\Class_Dashboard\\Rainmeter\\RestartRainmeter.exe", NULL, NULL, SW_SHOWNORMAL);
        break;
    case U("Math"):
        config[19] = Subjects[1];
        ShellExecute(NULL, L"runas", L"C:\\Class_Dashboard\\Rainmeter\\RestartRainmeter.exe", NULL, NULL, SW_SHOWNORMAL);
        break;
    case U("English"):
        config[19] = Subjects[2];
        ShellExecute(NULL, L"runas", L"C:\\Class_Dashboard\\Rainmeter\\RestartRainmeter.exe", NULL, NULL, SW_SHOWNORMAL);
        break;
    case U("Physics"):
        config[19] = Subjects[3];
        ShellExecute(NULL, L"runas", L"C:\\Class_Dashboard\\Rainmeter\\RestartRainmeter.exe", NULL, NULL, SW_SHOWNORMAL);
        break;
    case U("Chemistry"):
        config[19] = Subjects[4];
        ShellExecute(NULL, L"runas", L"C:\\Class_Dashboard\\Rainmeter\\RestartRainmeter.exe", NULL, NULL, SW_SHOWNORMAL);
        break;
    case U("Politics"):
        config[19] = Subjects[5];
        ShellExecute(NULL, L"runas", L"C:\\Class_Dashboard\\Rainmeter\\RestartRainmeter.exe", NULL, NULL, SW_SHOWNORMAL);
        break;
    case U("History"):
        config[19] = Subjects[6];
        ShellExecute(NULL, L"runas", L"C:\\Class_Dashboard\\Rainmeter\\RestartRainmeter.exe", NULL, NULL, SW_SHOWNORMAL);
        break;
    case U("None"):
        config[19] = Subjects[7];
        ShellExecute(NULL, L"runas", L"C:\\Class_Dashboard\\Rainmeter\\RestartRainmeter.exe", NULL, NULL, SW_SHOWNORMAL);
        break;
    default:
        MessageBox(NULL, L"The instruction is incorrect!", L"Error", MB_OK);
        break;
    }

    LocalFree(szArgList);
    n_cfg = freopen("C:\\Class_Dashboard\\n_config.ini", "w", stdout);
    if (n_cfg != 0) fseek(n_cfg, 0, SEEK_SET);
    cout << config[0] << " " << config[1] << " " << config[2] << endl;
    cout << config[3] << " " << config[4] << " " << config[5] << endl;
    cout << config[6] << " " << config[7] << " " << config[8] << endl;
    for (int i = 9; i <= 19; i++) cout << config[i] << endl;
    if (n_cfg != 0) fclose(n_cfg);
    cin.clear();

    return 0;
}

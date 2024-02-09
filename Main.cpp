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
using namespace std;

int t_year;
int t_month;
int t_day;



void fx_load_G_cfg()
{
    FILE* g_cfg;
    g_cfg = freopen("C:\\Class_Dashboard\\g_config.ini", "r", stdin);
    fseek(g_cfg, 0, SEEK_SET);
    scanf("[Target_Year] = %d", &t_year);
    scanf("[Target_Month] = %d", &t_month);
    scanf("[Target_day] = %d", &t_day);
    if (g_cfg != 0)fclose(g_cfg);
}

string fx_gettime() //获取当前日期
{
    auto now = chrono::system_clock::now();
    time_t now_c = chrono::system_clock::to_time_t(now);
    tm* now_tm = localtime(&now_c);

    ostringstream oss;
    oss << put_time(now_tm, "%Y%m%d");

    string n_time = oss.str();
    return n_time;
}

bool fx_change(const string t_tag) //判断是否更改
{
    if (t_tag == fx_gettime())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int fx_run() //运行壁纸
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // 替换为你要执行的命令
    TCHAR cmd[] = TEXT("\"C:\\Class_Dashboard\\Rainmeter\\Rainmeter.exe\"");


    // 创建子进程
    CreateProcess(NULL, cmd, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);

    // 关闭进程和线程句柄
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

string fx_getday() //获取星期
{
    time_t t = std::time(0);
    tm* now = std::localtime(&t);
    int day = now->tm_wday;
    ostringstream oss;
    oss << day;
    string day_str = oss.str();
    return day_str;
}

void fx_writefile(const string date, const int student_s, string wallpaper, string diffdays, string student, string lesson[]) //写文件
{
    FILE* nday = freopen("C:\\Class_Dashboard\\n_config.ini", "w",stdout);
    printf("[LastDay] = %s\n", date);
    printf("[Dute_Num] = %d\n", student_s);
    printf("[Wallpaper] = %s\n", wallpaper);
    printf("%s\n", diffdays);
    printf("%s\n", student);
    for (int i = 0; i <= 8; i++)
    {
        printf("%s\n", lesson[i]);
    }
    fclose(nday);
}

string fx_get_diffdays()
{
    //GetTime
    time_t now = time(0);
    tm* ltm = localtime(&now);

    tm future;
    future.tm_year = t_year - 1900;
    future.tm_mon = t_month - 1;
    future.tm_mday = t_day;
    future.tm_hour = 0;
    future.tm_min = 0;
    future.tm_sec = 0;

    time_t future_time = mktime(&future);
    double seconds = difftime(future_time, now);
    double days = seconds / (60 * 60 * 24);
    int diffdays = days + 1;

    ostringstream oss;
    oss << diffdays;
    string diffdays_str = oss.str();

    return diffdays_str;
}

void fx_changeBG(string day)
{
    if (day == "54")
    {
        HKEY hKey;
        LPCTSTR lpSubKey = TEXT("Control Panel\\Desktop");
        LPCTSTR lpValueName = TEXT("WallPaper");
        DWORD dwType = REG_SZ;
        LPCTSTR lpData = TEXT("C:\\ClassDashboard\\Wallpaper\\54.png");
        DWORD dwSize = (lstrlen(lpData) + 1) * sizeof(TCHAR);
        RegOpenKeyEx(HKEY_CURRENT_USER, lpSubKey, NULL, KEY_WRITE, &hKey);
        RegSetValueEx(hKey, lpValueName, 0, dwType, (LPBYTE)lpData, dwSize);
        RegCloseKey(hKey);
    }
    if (day == "441")
    {
        HKEY hKey;
        LPCTSTR lpSubKey = TEXT("Control Panel\\Desktop");
        LPCTSTR lpValueName = TEXT("WallPaper");
        DWORD dwType = REG_SZ;
        LPCTSTR lpData = TEXT("C:\\ClassDashboard\\Wallpaper\\441.png");
        DWORD dwSize = (lstrlen(lpData) + 1) * sizeof(TCHAR);
        RegOpenKeyEx(HKEY_CURRENT_USER, lpSubKey, NULL, KEY_WRITE, &hKey);
        RegSetValueEx(hKey, lpValueName, 0, dwType, (LPBYTE)lpData, dwSize);
        RegCloseKey(hKey);
    }
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // 替换为你要执行的命令
    TCHAR cmd[] = TEXT("\"RunDll32.exe USER32.DLL,UpdatePerUserSystemParameters\"");


    // 创建子进程
    CreateProcess(NULL, cmd, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);

    // 关闭进程和线程句柄
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

int main()
{
    string tmp;
    string main_day;
    string main_lessoname = "C:\\Class_Dashboard\\Week\\";
    string main_date;
    string main_diffday;
    string main_wallpaper_type;
    int main_dute_s = 0;
    string main_dute[55];
    string main_cnlessons[9];
    FILE *main_n_cfg;
    fx_load_G_cfg();
    main_n_cfg = freopen("C:\\Class_Dashboard\\n_config.ini", "r" ,stdin);
    fseek(main_n_cfg, 0, SEEK_SET);
    scanf("[Lastday] = %s", &main_date);
    scanf("[Date_Num] = %d", &main_dute_s);
    scanf("[Wallpaper] = %s", &main_wallpaper_type);
    scanf("%d", &main_diffday);
    scanf("%s", &tmp);
    for (int i = 0; i <= 8; i++)
    {
        scanf("%s", &main_cnlessons[i]);
    }
    if (main_n_cfg != 0) fclose(main_n_cfg);
    else return -1;

    if (fx_change(main_date))
    {
        fx_run();
        fx_changeBG(main_wallpaper_type);
    }
    else
    {
        main_day = fx_getday();
        main_lessoname += main_day;
        main_lessoname += ".ini";
        FILE *main_weeklesson = freopen(main_lessoname.c_str(), "r",stdin);
        fseek(main_weeklesson, 0, SEEK_SET);
        for (int i = 0; i <= 8; i++)
        {
            scanf("%s", &main_cnlessons[i]);
        }
        if (main_weeklesson != 0) fclose(main_weeklesson);
        else return -1;

        main_date = fx_gettime();
        main_diffday = fx_get_diffdays();
        main_dute_s += 1;
        if (main_dute_s == 55) main_dute_s = 1;
        FILE *main_student = freopen("C:\\Class_Dashboard\\students.ini", "r",stdin);
        fseek(main_student, 0, SEEK_SET);
        for (int i = 1; i <= 54; i++)
        {
            scanf("%s", main_dute[i]);
        }
        if (main_student != 0) fclose(main_student);
        else return -1;
        fx_writefile(main_date, main_dute_s, main_wallpaper_type, main_diffday, main_dute[main_dute_s], main_cnlessons);
        fx_run();
        fx_changeBG(main_wallpaper_type);
    }
    return 0;
}
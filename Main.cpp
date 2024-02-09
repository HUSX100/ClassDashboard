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

const int t_year = 2024;
const int t_month = 6;
const int t_day = 15;




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
    TCHAR cmd[] = TEXT("\"C:\\Program Files\\Rainmeter\\Rainmeter.exe\"");


    // 创建子进程
    if (!CreateProcess(NULL,   // 无模块名，使用命令行
        cmd,        // 命令行
        NULL,       // 进程安全属性
        NULL,       // 线程安全属性
        FALSE,      // 设置句柄继承选项
        0,          // 无创建标志
        NULL,       // 使用父进程的环境块
        NULL,       // 使用父进程的驱动器和目录
        &si,        // 指向STARTUPINFO或STARTUPINFOEX的指针
        &pi)        // 指向PROCESS_INFORMATION的指针
        )
    {
        printf("CreateProcess failed (%d).\n", GetLastError());
        return 1;
    }

    // 在这里，你可以立即调用exit(0)来结束你的C++程序
    exit(0);

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

void fx_writefile(const string date, const string diffday, const int index_student,const string student, const string lesson[]) //写文件
{
    FILE* nday = freopen("C:\\Class_Dashboard\\n_config.ini", "w",stdout);
    cout << date << endl;
    cout << diffday << endl;
    cout << index_student << endl;
    cout << student << endl;
    for (int i = 0; i <= 8; i++)
    {
        cout << lesson[i] << endl;
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

int main()
{
    string tmp;
    string main_day;
    string main_lessoname = "C:\\Class_Dashboard\\Week\\";
    string main_date;
    string main_diffday;
    int main_dute_s = 0;
    string main_dute[55];
    string main_cnlessons[9];
    FILE *main_n_cfg;
    main_n_cfg = freopen("C:\\Class_Dashboard\\n_config.ini", "r" ,stdin);
    cin >> main_date;
    cin >> main_diffday;
    cin >> main_dute_s;
    cin >> tmp;
    for (int i = 0; i <= 8; i++)
    {
        cin >> main_cnlessons[i];
    }
    fclose(main_n_cfg);
    cin.clear();

    if (fx_change(main_date))
    {
        fx_run();
    }
    else
    {
        main_day = fx_getday();
        main_lessoname += main_day;
        main_lessoname += ".ini";
        FILE *main_weeklesson = freopen(main_lessoname.c_str(), "r",stdin);
        string main_lesson_tmp;
        for (int i = 0; i <= 8; i++)
        {
            cin >> main_lesson_tmp;
            main_cnlessons[i] = main_lesson_tmp;
        }
        fclose(main_weeklesson);
        cin.clear();
        main_date = fx_gettime();
        main_diffday = fx_get_diffdays();
        main_dute_s += 1;
        if (main_dute_s == 55) main_dute_s = 1;
        FILE *main_student = freopen("C:\\Class_Dashboard\\students.ini", "r",stdin);
        for (int i = 1; i <= 54; i++)
        {
            cin >> main_dute[i];
        }
        fclose(main_student);
        cin.clear();
        fx_writefile(main_date, main_diffday, main_dute_s,main_dute[main_dute_s], main_cnlessons);
        fx_run();
    }
    return 0;
}
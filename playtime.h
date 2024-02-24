#ifndef PLAYTIME_H
#define PLAYTIME_H
#include <stdio.h>
#include <time.h>
#include <graphics.h>
#include <tchar.h>
#include <conio.h>
#include <windows.h>
void countdown(int seconds)
{
    time_t endTime = time(nullptr) + seconds;
    //time_t 是一个类型，用于表示从某个特定起点开始计算的时间值
    while (time(nullptr) < endTime)
    {
        settextcolor(YELLOW);
        settextstyle(20, 0, _T("Consolas"));

        // 清除原来的时间
        setfillcolor(BLACK); // 设置填充颜色为黑色
        solidrectangle(0, 140, 170, 160); // 清除一个矩形区域
        int remaining = endTime - time(nullptr);
        int minutes = remaining / 60;
        int seconds = remaining % 60;

        TCHAR timeString[8];
        _stprintf(timeString, _T("%02d:%02d"), minutes, seconds);
        //格式化输出函数，用于将格式化后的字符串写入到 timeString 数组中
        settextstyle(40, 0, _T("Arial"));  // 设置文本样式
        outtextxy(0, 140, timeString);  // 在指定位置绘制倒计时
        //_T 是一个宏，用于在跨平台编程中实现宽字符和窄字符的兼容性
        Sleep(1000);  // 暂停1秒
    }
}
void DisplayThread()
{
    while (1)
    {

        settextcolor(YELLOW);
        settextstyle(20, 0, _T("Consolas"));

        // 清除原来的时间
        setfillcolor(BLACK); // 设置填充颜色为黑色
        solidrectangle(0, 200, 170, 220); // 清除一个矩形区域
        // 获取当前日期和时间
        time_t now;
        time(&now);//获取当前时间的 time_t 值，并将其存储在 now 变量中。
        struct tm* timeInfo = localtime(&now);
        //通过 localtime(&now) 将 time_t 值转换为本地时间的结构体 struct tm，并将其指针存储在 timeInfo 变量中。
        // 格式化日期和时间
        TCHAR currentTime[20];
        _tcsftime(currentTime, sizeof(currentTime) / sizeof(TCHAR), _T("%Y-%m-%d %H:%M:%S"), timeInfo);
        //_tcsftime 函数将时间结构体 timeInfo 中的日期和时间格式化为字符串，并将结果存储在 currentTime 数组中。
        int weekday = timeInfo->tm_wday;
        //timeInfo->tm_wday 获取当前日期对应的星期几的值，并将结果存储在整型变量 weekday 中
        TCHAR weekdayStr[10];

        // 根据 weekday 值设置对应的星期几字符串
        switch (weekday)
        {
        case 0:
            _tcscpy(weekdayStr, _T("星期日"));
            break;
        case 1:
            _tcscpy(weekdayStr, _T("星期一"));
            break;
        case 2:
            _tcscpy(weekdayStr, _T("星期二"));
            break;
        case 3:
            _tcscpy(weekdayStr, _T("星期三"));
            break;
        case 4:
            _tcscpy(weekdayStr, _T("星期四"));
            break;
        case 5:
            _tcscpy(weekdayStr, _T("星期五"));
            break;
        case 6:
            _tcscpy(weekdayStr, _T("星期六"));
            break;
        default:
            _tcscpy(weekdayStr, _T("未知"));
            break;
        }
        // 在屏幕上绘制日期和时间
        setbkmode(TRANSPARENT);
        settextcolor(YELLOW); // 设置文本颜色
        settextstyle(20, 0, _T("Consolas")); // 设置文本样式
        // 绘制文本
        outtextxy(0, 200, currentTime);
        settextcolor(BLACK);
        outtextxy(0, 230, weekdayStr);
        FlushBatchDraw(); // 刷新绘图缓冲区
        Sleep(1000); // 暂停1秒
    }
}
#endif // !PLAYTIME_H


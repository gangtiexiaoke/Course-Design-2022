#ifndef OVERGAME_H
#define OVERGAME_H
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <windows.h>
#include"music_control.h"
void goodbye()
{
    cleardevice();
    initgraph(800, 600);
    IMAGE photo;
    loadimage(&photo, L"photo.jpg");
    putimage(0, 0, &photo);
    int color;
    srand((unsigned)time(NULL));//调用 srand 函数以当前时间为种子初始化随机数生成器。
    color = RGB(rand() % 256, rand() % 256, rand() % 256);
    //rand 函数生成三个随机数，分别通过取模运算 % 256 将其限定在 0 到 255 的范围内
    settextcolor(color);
    settextstyle(30, 0, _T("Arial Bold"));
    outtextxy(0, 0, L"congratulations on completing the challenge");
    while (!kbhit())
    {
        Sleep(100); // 适当延时，避免过于频繁的循环
    }
    getch(); // 清除按键缓冲区，获取用户按键
    closegraph(); // 关闭绘图窗口
    returnToMainMenu = true;
}
#endif // !OVERGAME_H

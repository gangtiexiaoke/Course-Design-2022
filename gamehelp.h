#ifndef GAMEHELP_H
#define GAMEHELP_H
#include <graphics.h>
#include <conio.h>
#include <windows.h>
#include"music_control.h"
void game_help()
{
    initgraph(800, 600);
    IMAGE picture;
    loadimage(&picture, L"game_help.jpg");
    while (!kbhit())
    {
        putimage(0, 0, &picture);
    }
    while (!kbhit())
    {
        Sleep(100); // 适当延时，避免过于频繁的循环
    }
    getch(); // 获取用户按键
    closegraph(); // 关闭绘图窗口
    returnToMainMenu = true; // 设置标志变量为true，表示返回主菜单
}
#endif // !GAMEHELP_H


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
        Sleep(100); // �ʵ���ʱ���������Ƶ����ѭ��
    }
    getch(); // ��ȡ�û�����
    closegraph(); // �رջ�ͼ����
    returnToMainMenu = true; // ���ñ�־����Ϊtrue����ʾ�������˵�
}
#endif // !GAMEHELP_H


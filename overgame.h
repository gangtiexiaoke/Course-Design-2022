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
    srand((unsigned)time(NULL));//���� srand �����Ե�ǰʱ��Ϊ���ӳ�ʼ���������������
    color = RGB(rand() % 256, rand() % 256, rand() % 256);
    //rand ��������������������ֱ�ͨ��ȡģ���� % 256 �����޶��� 0 �� 255 �ķ�Χ��
    settextcolor(color);
    settextstyle(30, 0, _T("Arial Bold"));
    outtextxy(0, 0, L"congratulations on completing the challenge");
    while (!kbhit())
    {
        Sleep(100); // �ʵ���ʱ���������Ƶ����ѭ��
    }
    getch(); // �����������������ȡ�û�����
    closegraph(); // �رջ�ͼ����
    returnToMainMenu = true;
}
#endif // !OVERGAME_H

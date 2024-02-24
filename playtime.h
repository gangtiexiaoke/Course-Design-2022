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
    //time_t ��һ�����ͣ����ڱ�ʾ��ĳ���ض���㿪ʼ�����ʱ��ֵ
    while (time(nullptr) < endTime)
    {
        settextcolor(YELLOW);
        settextstyle(20, 0, _T("Consolas"));

        // ���ԭ����ʱ��
        setfillcolor(BLACK); // ���������ɫΪ��ɫ
        solidrectangle(0, 140, 170, 160); // ���һ����������
        int remaining = endTime - time(nullptr);
        int minutes = remaining / 60;
        int seconds = remaining % 60;

        TCHAR timeString[8];
        _stprintf(timeString, _T("%02d:%02d"), minutes, seconds);
        //��ʽ��������������ڽ���ʽ������ַ���д�뵽 timeString ������
        settextstyle(40, 0, _T("Arial"));  // �����ı���ʽ
        outtextxy(0, 140, timeString);  // ��ָ��λ�û��Ƶ���ʱ
        //_T ��һ���꣬�����ڿ�ƽ̨�����ʵ�ֿ��ַ���խ�ַ��ļ�����
        Sleep(1000);  // ��ͣ1��
    }
}
void DisplayThread()
{
    while (1)
    {

        settextcolor(YELLOW);
        settextstyle(20, 0, _T("Consolas"));

        // ���ԭ����ʱ��
        setfillcolor(BLACK); // ���������ɫΪ��ɫ
        solidrectangle(0, 200, 170, 220); // ���һ����������
        // ��ȡ��ǰ���ں�ʱ��
        time_t now;
        time(&now);//��ȡ��ǰʱ��� time_t ֵ��������洢�� now �����С�
        struct tm* timeInfo = localtime(&now);
        //ͨ�� localtime(&now) �� time_t ֵת��Ϊ����ʱ��Ľṹ�� struct tm��������ָ��洢�� timeInfo �����С�
        // ��ʽ�����ں�ʱ��
        TCHAR currentTime[20];
        _tcsftime(currentTime, sizeof(currentTime) / sizeof(TCHAR), _T("%Y-%m-%d %H:%M:%S"), timeInfo);
        //_tcsftime ������ʱ��ṹ�� timeInfo �е����ں�ʱ���ʽ��Ϊ�ַ�������������洢�� currentTime �����С�
        int weekday = timeInfo->tm_wday;
        //timeInfo->tm_wday ��ȡ��ǰ���ڶ�Ӧ�����ڼ���ֵ����������洢�����ͱ��� weekday ��
        TCHAR weekdayStr[10];

        // ���� weekday ֵ���ö�Ӧ�����ڼ��ַ���
        switch (weekday)
        {
        case 0:
            _tcscpy(weekdayStr, _T("������"));
            break;
        case 1:
            _tcscpy(weekdayStr, _T("����һ"));
            break;
        case 2:
            _tcscpy(weekdayStr, _T("���ڶ�"));
            break;
        case 3:
            _tcscpy(weekdayStr, _T("������"));
            break;
        case 4:
            _tcscpy(weekdayStr, _T("������"));
            break;
        case 5:
            _tcscpy(weekdayStr, _T("������"));
            break;
        case 6:
            _tcscpy(weekdayStr, _T("������"));
            break;
        default:
            _tcscpy(weekdayStr, _T("δ֪"));
            break;
        }
        // ����Ļ�ϻ������ں�ʱ��
        setbkmode(TRANSPARENT);
        settextcolor(YELLOW); // �����ı���ɫ
        settextstyle(20, 0, _T("Consolas")); // �����ı���ʽ
        // �����ı�
        outtextxy(0, 200, currentTime);
        settextcolor(BLACK);
        outtextxy(0, 230, weekdayStr);
        FlushBatchDraw(); // ˢ�»�ͼ������
        Sleep(1000); // ��ͣ1��
    }
}
#endif // !PLAYTIME_H


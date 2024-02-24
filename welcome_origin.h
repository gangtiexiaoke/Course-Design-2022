#ifndef WELCOME_ORIGIN_H
#define WELCOME_ORIGIN_H
#include <graphics.h>
#include <Windows.h>
#include"student_rank.h"
void Loadimage()//����ͼƬ
{
    IMAGE photo;
    loadimage(&photo, L"photo.jpg");
    putimage(0, 0, &photo);
}
int welcome()//��ӭͼƬ
{
    initgraph(800, 600);
    Loadimage();
    output_students();
    settextstyle(50, 0, _T("����"));
    settextcolor(BLUE);
    setbkmode(TRANSPARENT);
    outtextxy(200, 0, _T("More pains"));
    outtextxy(280, 60, _T("More gains"));
    settextstyle(20, 0, _T("Grinched"));
    settextcolor(BLUE);
    setbkmode(TRANSPARENT);
    outtextxy(0, 500, _T("������Ա������С��"));
    outtextxy(0, 520, _T("������Ա������� ������"));
    outtextxy(0, 540, _T("���������������"));
    outtextxy(0, 560, _T("������Ա��֧��"));
    settextstyle(14, 0, _T("Grinched"));
    settextcolor(RED);
    setbkmode(TRANSPARENT);
    RECT rect = { 300, 200, 480, 250 };
    const int button_len = 180;
    const int button_high = 50;
    const int button_count = 7;
    int y = rect.top;
    int word_button = -1;
    for (int i = 0; i < button_count; i++)
    {
        RECT buttonRect = { rect.left, y, rect.right, y + button_high };
        const wchar_t* word_button_text = nullptr;//���ݰ�ť������ i �����ö�Ӧ�İ�ť�ı�
        switch (i)
        {
        case 0:
            word_button_text = L"��ʼ��Ϸ";
            break;
        case 1:
            word_button_text = L"������Ϸ";
            break;
        case 2:
            word_button_text = L"�ڶ����";
            break;
        case 3:
            word_button_text = L"��Ϸ˵��";
            break;
        case 4:
            word_button_text = L"ֹͣ����";
            break;
        case 5:
            word_button_text = L"��������";
            break;
        case 6:
            word_button_text = L"�л�����";
        }
        for (int j = 0; j < button_high; j++)
        {
            int r = 0, g = 0, b = 0;
            r = (i + 1) * 20;
            g = 0;
            b = 200 - i * 20;
            setlinecolor(RGB(r, g, b));
            setfillcolor(RGB(r, g, b));
            int top = buttonRect.top + j;
            int bottom = buttonRect.top + j + 1;
            solidrectangle(buttonRect.left + 1, top + 1, buttonRect.right - 1, bottom - 1);
        }
        /*
        �������������ͱ��� r��g��b�����ڱ�ʾ��ɫ�� RGB ����
        ͨ�� (i + 1) * 20 �����ɫ���� r ��ֵ��ͨ�� 200 - i * 20 ������ɫ���� b ��ֵ��
        ����ɫ���� g ���̶�Ϊ0���ڰ�ť���ƵĹ����У�����ݰ�ť������ i ��ͬ��
        ���㲢���ð�ť��������ɫ�������ɫ����ʵ��ÿ����ť��ɫ��ͬ��Ч����*/
        setbkmode(TRANSPARENT);//setbkmode �����ı�����ģʽΪ͸��
        settextstyle(35, 0, _T("Arial Bold"));
        settextcolor(RGB(255, 255, 255));
        rectangle(buttonRect.left, buttonRect.top, buttonRect.right, buttonRect.bottom);//solidrectangle ��������һ��ʵ�ľ���
        drawtext(word_button_text, &buttonRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        // word_button_text �����ڰ�ť�ڲ��� DT_CENTER | DT_VCENTER | DT_SINGLELINE �������ı����ж���
        y += 5 + button_high;
    }

    while (word_button == -1)
    {
        if (MouseHit())
        {
            MOUSEMSG msg = GetMouseMsg();
            if (msg.uMsg == WM_LBUTTONDOWN)
            {
                for (int i = 0; i < button_count; i++)
                {
                    RECT buttonRect = { rect.left, rect.top + (button_high + 5) * i, rect.right, rect.top + (button_high + 5) * i + button_high };
                    if (msg.x >= buttonRect.left && msg.x <= buttonRect.right && msg.y >= buttonRect.top && msg.y <= buttonRect.bottom)
                    {
                        word_button = i;
                        break;
                    }
                }
            }
        }
    }
    return word_button;
}
#endif // !WELCOME_ORIGIN_H


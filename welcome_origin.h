#ifndef WELCOME_ORIGIN_H
#define WELCOME_ORIGIN_H
#include <graphics.h>
#include <Windows.h>
#include"student_rank.h"
void Loadimage()//背景图片
{
    IMAGE photo;
    loadimage(&photo, L"photo.jpg");
    putimage(0, 0, &photo);
}
int welcome()//欢迎图片
{
    initgraph(800, 600);
    Loadimage();
    output_students();
    settextstyle(50, 0, _T("楷体"));
    settextcolor(BLUE);
    setbkmode(TRANSPARENT);
    outtextxy(200, 0, _T("More pains"));
    outtextxy(280, 60, _T("More gains"));
    settextstyle(20, 0, _T("Grinched"));
    settextcolor(BLUE);
    setbkmode(TRANSPARENT);
    outtextxy(0, 500, _T("开发人员：钢铁小科"));
    outtextxy(0, 520, _T("测试人员：尹宇飞 刘嘉琪"));
    outtextxy(0, 540, _T("创意帮助：王雨欣"));
    outtextxy(0, 560, _T("音乐人员：支书"));
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
        const wchar_t* word_button_text = nullptr;//根据按钮的索引 i 来设置对应的按钮文本
        switch (i)
        {
        case 0:
            word_button_text = L"开始游戏";
            break;
        case 1:
            word_button_text = L"结束游戏";
            break;
        case 2:
            word_button_text = L"第二软件";
            break;
        case 3:
            word_button_text = L"游戏说明";
            break;
        case 4:
            word_button_text = L"停止音乐";
            break;
        case 5:
            word_button_text = L"继续音乐";
            break;
        case 6:
            word_button_text = L"切换音乐";
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
        定义了三个整型变量 r、g、b，用于表示颜色的 RGB 分量
        通过 (i + 1) * 20 计算红色分量 r 的值，通过 200 - i * 20 计算蓝色分量 b 的值，
        而绿色分量 g 被固定为0。在按钮绘制的过程中，会根据按钮的索引 i 不同，
        计算并设置按钮的线条颜色和填充颜色，来实现每个按钮颜色不同的效果。*/
        setbkmode(TRANSPARENT);//setbkmode 设置文本背景模式为透明
        settextstyle(35, 0, _T("Arial Bold"));
        settextcolor(RGB(255, 255, 255));
        rectangle(buttonRect.left, buttonRect.top, buttonRect.right, buttonRect.bottom);//solidrectangle 函数绘制一个实心矩形
        drawtext(word_button_text, &buttonRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        // word_button_text 绘制在按钮内部， DT_CENTER | DT_VCENTER | DT_SINGLELINE 参数将文本居中对齐
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


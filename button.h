#ifndef BUTTON_H
#define BUTTON_H
#include <stdlib.h>
#include <string.h>
#include <graphics.h>
#pragma comment(lib,"winmm.lib")//提供了一些与多媒体处理相关的函数和类型。
#pragma warning (disable:4996)//编译器禁用特定的警告编号
#undef UNICODE
#undef _UNICODE//表示使用 Unicode 字符集
struct button
{
    int x;
    int y;
    int width;
    int height;
    COLORREF color;
    char* pText;
};
//初始化按钮属性
struct button* createButton(int x, int y, int width, int height, COLORREF color, const char* pText)
{
    struct button* pB = (struct button*)malloc(sizeof(struct button));
    pB->x = x;
    pB->y = y;
    pB->width = width;
    pB->height = height;
    pB->color = color;
    pB->pText = (char*)malloc(strlen(pText) + 1);
    strcpy(pB->pText, pText);
    return pB;

}
void drawButton(struct button* pB)
{
    setfillcolor(pB->color);
    settextstyle(35, 0, _T("楷体"));
    setlinecolor(BLACK);
    settextcolor(BLACK);
    setbkmode(TRANSPARENT);
    fillrectangle(pB->x, pB->y, pB->x + pB->width, pB->y + pB->height);
    outtextxy(pB->x + 20, pB->y + 10, L"pB->pText");
}
int mouseInButton(struct button* pB, MOUSEMSG m)
{
    if (pB->x <= m.x && m.x <= pB->x + pB->width && pB->y <= m.y && m.y <= pB->height + pB->y)
    {
        pB->color = RED;
        return 1;
    }
    pB->color = YELLOW;
    return 0;
}
int clickButton(struct button* pB, MOUSEMSG m)
{
    if (mouseInButton(pB, m) && m.uMsg == WM_LBUTTONDOWN)
    {
        return 1;
    }
    return 0;
}
#endif // !BUTTON_H


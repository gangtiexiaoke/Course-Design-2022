#ifndef STUDENT_RANK_H
#define STUDENT_RANK_H
#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <string.h>
#include <graphics.h>
#pragma comment(lib,"winmm.lib")//提供了一些与多媒体处理相关的函数和类型。
#pragma warning (disable:4996)//编译器禁用特定的警告编号
#undef UNICODE
#undef _UNICODE//表示使用 Unicode 字符集
typedef struct {
    int wordcount;
    char name[20];
} Student;
Student student[200];
int num = 0, numrank = 0, flag = 1;//num用来计数，在排行榜
int compare_scores(const void* a, const void* b)
{
    const Student* studentA = (const Student*)a;
    const Student* studentB = (const Student*)b;

    // 降序排列
    if (studentA->wordcount < studentB->wordcount)
        return 1;
    else if (studentA->wordcount > studentB->wordcount)
        return -1;
    else
        return 0;
}
void output_students()
{
    FILE* fp;
    fp = fopen("rank.txt", "r");
    Student student[200];
    int numStudents = 0;
    if (fp != NULL)
    {
        while (fscanf(fp, "%s %d", student[numStudents].name, &student[numStudents].wordcount) == 2)
        {
            numStudents++;
        }
        fclose(fp);
    }
    qsort(student, numStudents, sizeof(Student), compare_scores);
    int x = 0;
    int y = 350;
    int count = 0;
    settextstyle(20, 0, _T("Grinched"));
    settextcolor(BLUE);
    setbkmode(TRANSPARENT);
    outtextxy(0, 300, _T("最长单词保持纪录"));
    outtextxy(0, 325, _T("用户"));
    outtextxy(100, 325, _T("最多数量"));
    for (int i = 0; i < numStudents && count < 3; i++)
    {
        wchar_t wideName[20];
        mbstowcs(wideName, student[i].name, sizeof(student[i].name));
        //这里使用了 mbstowcs 函数将 char[] 类型的字符串 student[i].name 转换为宽字符字符串 wideName，
        outtextxy(x, y, wideName);  // 输出名字
        char scoreText[10];
        sprintf(scoreText, "%d", student[i].wordcount);
        wchar_t wideScore[10];
        //先通过 sprintf 函数将整数类型的分数 student[i].wordcount 转换为字符串类型 scoreText，
        //然后再将其转换为宽字符字符串 wideScore
        mbstowcs(wideScore, scoreText, sizeof(scoreText));
        outtextxy(x + 100, y, wideScore); // 输出分数
        y += 30;  // 调整下一行的显示位置
        count++;
    }
}
#endif // !STUDENT_RANK_H


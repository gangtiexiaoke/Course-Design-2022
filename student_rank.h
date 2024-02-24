#ifndef STUDENT_RANK_H
#define STUDENT_RANK_H
#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <string.h>
#include <graphics.h>
#pragma comment(lib,"winmm.lib")//�ṩ��һЩ���ý�崦����صĺ��������͡�
#pragma warning (disable:4996)//�����������ض��ľ�����
#undef UNICODE
#undef _UNICODE//��ʾʹ�� Unicode �ַ���
typedef struct {
    int wordcount;
    char name[20];
} Student;
Student student[200];
int num = 0, numrank = 0, flag = 1;//num���������������а�
int compare_scores(const void* a, const void* b)
{
    const Student* studentA = (const Student*)a;
    const Student* studentB = (const Student*)b;

    // ��������
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
    outtextxy(0, 300, _T("����ʱ��ּ�¼"));
    outtextxy(0, 325, _T("�û�"));
    outtextxy(100, 325, _T("�������"));
    for (int i = 0; i < numStudents && count < 3; i++)
    {
        wchar_t wideName[20];
        mbstowcs(wideName, student[i].name, sizeof(student[i].name));
        //����ʹ���� mbstowcs ������ char[] ���͵��ַ��� student[i].name ת��Ϊ���ַ��ַ��� wideName��
        outtextxy(x, y, wideName);  // �������
        char scoreText[10];
        sprintf(scoreText, "%d", student[i].wordcount);
        wchar_t wideScore[10];
        //��ͨ�� sprintf �������������͵ķ��� student[i].wordcount ת��Ϊ�ַ������� scoreText��
        //Ȼ���ٽ���ת��Ϊ���ַ��ַ��� wideScore
        mbstowcs(wideScore, scoreText, sizeof(scoreText));
        outtextxy(x + 100, y, wideScore); // �������
        y += 30;  // ������һ�е���ʾλ��
        count++;
    }
}
#endif // !STUDENT_RANK_H


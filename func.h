#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>
#include <conio.h>
#include <windows.h>
#include"student_rank.h"
#define max_len 50
#define max_word 100
wchar_t* copy_word(wchar_t* word)//ȫ�Ŀ��ַ�����
{
    int length = wcslen(word) + 1;//��ȡ word �ַ����ĳ��ȣ����� 1�����ڴ洢�ַ�����β�Ŀ��ַ���
    wchar_t* copy = (wchar_t*)malloc(length * sizeof(wchar_t));
    if (copy != NULL)
    {
        wcscpy(copy, word);//word �ַ������Ƶ� copy �ַ����У�ʹ�� wcscpy ������ɸ��ơ�
    }
    return copy;
}
void compare_word(wchar_t* correct_word)
{
    FILE* fp;
    fp = fopen("cuotiben.txt", "a+");
    int input_wrong = 0;
    while (true)
    {
        wchar_t player_word[max_len + 1];
        bool input_success = InputBox(player_word, max_len, L"�����뵥��", L"word game");
        if (!input_success)
        {
            break;
        }
        if (wcscmp(correct_word, player_word) == 0)
        {
            cleardevice();
            IMAGE photo;
            loadimage(&photo, L"photo.jpg");
            putimage(0, 0, &photo);
            MessageBoxW(NULL, L"��ϲ�㣬ƴд��ȷ��", L"���", MB_OK | MB_ICONINFORMATION);
            if (flag)
                num++;
            break;
        }//MB_OK | MB_ICONINFORMATION���Դ���һ������һ��"ȷ��"��ť��һ����Ϣͼ�����Ϣ��
        else
        {
            input_wrong++;
        }
        if (input_wrong >= 2)
        {
            MessageBoxW(NULL, correct_word, L"��ȷ����", MB_OK | MB_ICONINFORMATION);
            fwprintf(fp, L"%s\n", correct_word);
            break;
        }
        int result = MessageBoxW(NULL, L"ƴд�����Ƿ��ٴ����룿", L"���", MB_YESNO | MB_ICONQUESTION);
        if (result == IDNO)
        {
            cleardevice();
            IMAGE photo;
            loadimage(&photo, L"photo.jpg");
            putimage(0, 0, &photo);
            MessageBoxW(NULL, correct_word, L"��ȷ����", MB_OK | MB_ICONINFORMATION);
            break;
        }
        Sleep(1000);
        cleardevice();
        IMAGE photo;
        loadimage(&photo, L"photo.jpg");
        putimage(0, 0, &photo);
    }
    fclose(fp);
}
void show_word(wchar_t* word)
{
    int color;
    srand((unsigned)time(NULL));
    color = RGB(rand() % 256, rand() % 256, rand() % 256);
    settextcolor(color);
    settextstyle(70, 0, _T("Arial Bold"));
    outtextxy(100, 100, word);
}
void modify_word(wchar_t* px)
{
    int i, miss_pos1, miss_pos2;
    srand((unsigned)time(NULL));
    int word_len = wcslen(px);
    miss_pos1 = rand() % word_len;
    miss_pos2 = rand() % word_len;
    if (miss_pos2 == miss_pos1)
    {
        miss_pos2 = (miss_pos2 + 1) % word_len;
    }
    for (i = 0; px[i] != L'\0'; i++)
    {
        if (i == miss_pos1 || i == miss_pos2)
        {
            px[i] = L'_ ';
        }
    }
}
void read_word(wchar_t words[][max_len+1], int max_words, int* count_word)
{
    FILE* fp;
    wchar_t word[max_len + 1];
    int i;
    *count_word = 0;
    fp = fopen("words.txt", "r");
    if (fp == NULL)
    {
        wprintf(L"Failed to open file\n");
        exit(1);
    }
    while (fgetws(word, max_len + 1, fp) != NULL)
    {
        for (i = 0; word[i] != L'\0'; i++)
        {
            if (word[i] == L'\n')
            {
                word[i] = L'\0';
            }
        }
        wcscpy(words[*count_word], word);
        (*count_word)++;
    }
    fclose(fp);
}
#endif // !FUNC_H


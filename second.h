#ifndef SECOND_H
#define SECOND_H
#include <stdio.h>
#include"music_control.h"
#include"secfunc.h"
void Menu()
{
    int i = 7;
    while (i)
    {
        printf("****************1.增加单词****************\n");
        printf("****************2.查找单词****************\n");
        printf("****************3.删除单词****************\n");
        printf("****************4.查看单词****************\n");
        printf("****************5.查看错题****************\n");
        printf("****************6.清空错题****************\n");
        printf("****************0.退出操作****************\n");
        printf("请输入你的选择：");
        scanf("%d", &i);
        getchar();
        switch (i)
        {
        case 1:
            addword();  //跳转对应增加单词的子函数
            break;
        case 2:
            findword();//跳转对应查找单词的子函数
            break;
        case 3:
            delword();	//delword()为删除单词对应子函数
            break;
        case 4:
            Visit();
            break;
        case 5:
            cuotiben();
            break;
        case 6:
            destorycuotiben();
            break;
        default:
            printf("请输入正确选项!\n");
        }
        system("cls");    // 清屏
    }
    system("cls");    // 清屏

    returnToMainMenu = true;
}
void second_game()
{
    FreeConsole(); //分离原有的控制台
    AllocConsole(); //分配一个新的控制台
    SetConsoleTitleA("second_game");
    RegisterorLoading();
    Menu();
}
#endif // !SECOND_H


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
        printf("****************1.���ӵ���****************\n");
        printf("****************2.���ҵ���****************\n");
        printf("****************3.ɾ������****************\n");
        printf("****************4.�鿴����****************\n");
        printf("****************5.�鿴����****************\n");
        printf("****************6.��մ���****************\n");
        printf("****************0.�˳�����****************\n");
        printf("���������ѡ��");
        scanf("%d", &i);
        getchar();
        switch (i)
        {
        case 1:
            addword();  //��ת��Ӧ���ӵ��ʵ��Ӻ���
            break;
        case 2:
            findword();//��ת��Ӧ���ҵ��ʵ��Ӻ���
            break;
        case 3:
            delword();	//delword()Ϊɾ�����ʶ�Ӧ�Ӻ���
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
            printf("��������ȷѡ��!\n");
        }
        system("cls");    // ����
    }
    system("cls");    // ����

    returnToMainMenu = true;
}
void second_game()
{
    FreeConsole(); //����ԭ�еĿ���̨
    AllocConsole(); //����һ���µĿ���̨
    SetConsoleTitleA("second_game");
    RegisterorLoading();
    Menu();
}
#endif // !SECOND_H


#ifndef REGISTER_H
#define REGISTER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char mingzi[20];
char shuru[8];
void Register()                        //�û���ע��
{

    char yonghuming1[20], mima1[8], mima2[8], mima3[8], mm[8];       //�û�������һ��������룬��һ��ȷ�ϵ����룬��һ��ȷ���������ʱ�ڶ���ȷ�ϵ����룬���մ����ļ������롣
    FILE* fp;
    fp = fopen("yonghushuju.txt", "a+");
    if (!fp)
    {
        printf("file error\n");
        exit(1);
    };
    printf("��ע������û���:\n");
    scanf("%s", yonghuming1);
    printf("����������:\n");
    scanf("%s", mima1);
    printf("��ȷ������:\n");
    scanf("%s", mima2);
    if (!strcmp(mima1, mima2))               //�����һ�������������ȷ�ϵ�����һ����ע��ɹ���
    {
        strcpy(mm, mima1);
        printf("ע��ɹ�!");

    }
    else
    {
        printf("���ٴ�ȷ������:\n");
        scanf("%s", mima3);
        if (!strcmp(mima1, mima3))    //����һ�β�һ������ڶ���ȷ��һ�¡�
        {
            strcpy(mm, mima1);
            printf("��ϲ�㣬ע��ɹ���\n");
        }
        else
        {
            printf("ע��ʧ��!\n");
            getchar();
            getchar();    //��������ȷ�ϲ�һ����ע��ʧ��ֱ���˳���
            exit(1);
        }
    }
    fprintf(fp, "%s %s \n", yonghuming1, mm);      //�û��������뻹�г�ʼ���������ļ���
    fclose(fp);
}
void Loading()          //��¼
{
    int ch = 0;                   //�м�����������ж��û����Ƿ���ڡ�
    typedef struct yhsj      //����ṹ��
    {
        char name[20];
        char password[8];
        int dkts;
    }sj;
    sj yhxx[1000]; //����ṹ�����飬�����洢�û���Ϣ
    int i = 0;      //ѭ������
    FILE* fp;     //�����ļ�ָ��
    fp = fopen("yonghushuju.txt", "r");//��ֻ������ʽ���û������ļ�
    if (!fp)
    {
        printf("file error!\n");
        exit(1);
    }             //����ʧ�ܣ����˳�����
    printf("�������û�����¼:\n");
    scanf("%s", mingzi);   //���û��������Ϣ�洢���ַ�������
    fscanf(fp, "%s%s%d", yhxx[i].name, yhxx[i].password, &yhxx[i].dkts);
    while (!feof(fp))
    {
        i++;
        fscanf(fp, "%s%s%d", yhxx[i].name, yhxx[i].password, &yhxx[i].dkts);
    }                  //���ļ������е��û���Ϣ����ṹ��
    fclose(fp);       //�ر��ļ�
    for (i = 0; i < 1000; i++)
    {
        if (!strcmp(mingzi, yhxx[i].name))    //�ж��û������ļ����Ƿ�����֮������û���
        {
            ch = 1;                               //�����ڸ��û�������ch��ֵΪ1��
            printf("���������룺\n");
            scanf("%s", shuru);
            if (!strcmp(shuru, yhxx[i].password))   //���û�������������û������ļ��е�����ȶ�
            {
                printf("��¼�ɹ������밴�س�������\n");
                getchar();
                getchar();
            }           //ͣ��
            else
            {
                printf("����������������룺\n");
                scanf("%s", shuru);
                if (!strcmp(shuru, yhxx[i].password))         //�ٴν�������ȶ�
                {
                    printf("��¼�ɹ������밴�س�������\n");
                    getchar();
                    getchar();
                }
                else
                {
                    printf("�������������࣬�ټ���\n");
                    getchar();
                    getchar();
                    exit(1);         //��������������ޣ�ͣ�ٺ�ֱ�ӽ�������
                }
            }
        }
    }
    if (ch == 0)      //�û������ļ����Ҳ������û��������������û�ע��
    {
        printf("�޴��û�������ע�ᣡ\n");
        getchar();
        getchar();
        exit(1);
    }
}
void printInfo()           //�������ο�
{
    printf("\n\n\n\n\n");
    printf("\t                                     ***************************\n");
    printf("\t                                     &                         &\n");
    printf("\t                                     &      Hi!    spideman    &\n");
    printf("\t                                     &                         &\n");
    printf("\t                                     &                         &\n");
    printf("\t                                     &          1.ע��         &\n");
    printf("\t                                     &                         &\n");
    printf("\t                                     &                         &\n");
    printf("\t                                     &                         &\n");
    printf("\t                                     &          2.��¼         &\n");
    printf("\t                                     &                         &\n");
    printf("\t                                     &                         &\n");
    printf("\t                                     &                         &\n");
    printf("\t                                     &          3.�ο�         &\n");
    printf("\t                                     &                         &\n");
    printf("\t                                     &                         &\n");
    printf("\t                                     &                         &\n");
    printf("\t                                     &                         &\n");
    printf("\t                                     &**************************\n\n");
}
void RegisterorLoading()      //ע�����¼����
{
    int i;                                  //ѡ���¼��ע��ı���
    printInfo();                       //���ڽ�������
    printf("��ѡ����Ľ��뷽ʽ��\n");
    scanf("%d", &i);
    system("cls");                   //������д��ڽ���
    switch (i)
    {
    case 1:
        Register();
        getchar();
        getchar();                 //��תע����¼
    case 2:
        Loading();
        system("cls");
        break;
    case 3:
        system("cls");
        break;
    }
}
#endif // !REGISTER_H


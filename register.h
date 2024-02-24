#ifndef REGISTER_H
#define REGISTER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char mingzi[20];
char shuru[8];
void Register()                        //用户名注册
{

    char yonghuming1[20], mima1[8], mima2[8], mima3[8], mm[8];       //用户名，第一次设的密码，第一次确认的密码，第一次确认密码错误时第二次确认的密码，最终存入文件的密码。
    FILE* fp;
    fp = fopen("yonghushuju.txt", "a+");
    if (!fp)
    {
        printf("file error\n");
        exit(1);
    };
    printf("请注册你的用户名:\n");
    scanf("%s", yonghuming1);
    printf("请输入密码:\n");
    scanf("%s", mima1);
    printf("请确认密码:\n");
    scanf("%s", mima2);
    if (!strcmp(mima1, mima2))               //如果第一次输入的密码与确认的密码一致则注册成功。
    {
        strcpy(mm, mima1);
        printf("注册成功!");

    }
    else
    {
        printf("请再次确认密码:\n");
        scanf("%s", mima3);
        if (!strcmp(mima1, mima3))    //若第一次不一致则需第二次确认一致。
        {
            strcpy(mm, mima1);
            printf("恭喜你，注册成功！\n");
        }
        else
        {
            printf("注册失败!\n");
            getchar();
            getchar();    //密码两次确认不一致则注册失败直接退出。
            exit(1);
        }
    }
    fprintf(fp, "%s %s \n", yonghuming1, mm);      //用户名与密码还有初始打卡数存入文件。
    fclose(fp);
}
void Loading()          //登录
{
    int ch = 0;                   //中间变量，用来判断用户名是否存在。
    typedef struct yhsj      //定义结构体
    {
        char name[20];
        char password[8];
        int dkts;
    }sj;
    sj yhxx[1000]; //定义结构体数组，用来存储用户信息
    int i = 0;      //循环变量
    FILE* fp;     //定义文件指针
    fp = fopen("yonghushuju.txt", "r");//以只读的形式打开用户数据文件
    if (!fp)
    {
        printf("file error!\n");
        exit(1);
    }             //若打开失败，则退出程序
    printf("请输入用户名登录:\n");
    scanf("%s", mingzi);   //将用户输入的信息存储到字符数组中
    fscanf(fp, "%s%s%d", yhxx[i].name, yhxx[i].password, &yhxx[i].dkts);
    while (!feof(fp))
    {
        i++;
        fscanf(fp, "%s%s%d", yhxx[i].name, yhxx[i].password, &yhxx[i].dkts);
    }                  //将文件里所有的用户信息读入结构体
    fclose(fp);       //关闭文件
    for (i = 0; i < 1000; i++)
    {
        if (!strcmp(mingzi, yhxx[i].name))    //判断用户数据文件里是否有与之相配的用户名
        {
            ch = 1;                               //若存在该用户名，则将ch赋值为1；
            printf("请输入密码：\n");
            scanf("%s", shuru);
            if (!strcmp(shuru, yhxx[i].password))   //将用户输入的密码与用户数据文件中的密码比对
            {
                printf("登录成功！（请按回车继续）\n");
                getchar();
                getchar();
            }           //停顿
            else
            {
                printf("密码错误，请重新输入：\n");
                scanf("%s", shuru);
                if (!strcmp(shuru, yhxx[i].password))         //再次进行密码比对
                {
                    printf("登录成功！（请按回车继续）\n");
                    getchar();
                    getchar();
                }
                else
                {
                    printf("输入错误次数过多，再见！\n");
                    getchar();
                    getchar();
                    exit(1);         //密码输入次数超限，停顿后直接结束程序。
                }
            }
        }
    }
    if (ch == 0)      //用户数据文件里找不到该用户名，引导进行用户注册
    {
        printf("无此用户名，请注册！\n");
        getchar();
        getchar();
        exit(1);
    }
}
void printInfo()           //界面外形框
{
    printf("\n\n\n\n\n");
    printf("\t                                     ***************************\n");
    printf("\t                                     &                         &\n");
    printf("\t                                     &      Hi!    spideman    &\n");
    printf("\t                                     &                         &\n");
    printf("\t                                     &                         &\n");
    printf("\t                                     &          1.注册         &\n");
    printf("\t                                     &                         &\n");
    printf("\t                                     &                         &\n");
    printf("\t                                     &                         &\n");
    printf("\t                                     &          2.登录         &\n");
    printf("\t                                     &                         &\n");
    printf("\t                                     &                         &\n");
    printf("\t                                     &                         &\n");
    printf("\t                                     &          3.游客         &\n");
    printf("\t                                     &                         &\n");
    printf("\t                                     &                         &\n");
    printf("\t                                     &                         &\n");
    printf("\t                                     &                         &\n");
    printf("\t                                     &**************************\n\n");
}
void RegisterorLoading()      //注册与登录界面
{
    int i;                                  //选择登录或注册的变量
    printInfo();                       //窗口界面美观
    printf("请选择你的进入方式：\n");
    scanf("%d", &i);
    system("cls");                   //清空已有窗口界面
    switch (i)
    {
    case 1:
        Register();
        getchar();
        getchar();                 //跳转注册或登录
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


#ifndef SECFUNC_H
#define SECFUNC_H
#include<stdio.h>
#include"register.h"
#include <thread>
bool check(unsigned char c) {
    //通过utf-8字节码进行判断
    return c >= 0xE0;
}
void Visit()
{
    typedef struct stu
    {
        char px[100];
        char zw[100];
    }dcxx;
    int i = 0;
    char dy;  // 定义字符变量
    dcxx dcsj[1000];  // 定义结构体数组，用来存储单词信息
    FILE* fp;             // 定义文件指针
    fp = fopen("words.txt", "r"); // 以只读的形式打开单词本文件
    if (!fp)   // 判断文件是否成功打开
    {
        printf("file error!\n");
        return;
    }
    while (fscanf(fp, "%s%ls", dcsj[i].px, dcsj[i].zw) != EOF)
    {
        i++;
    }
    fclose(fp);
    printf("单词本信息如下(技术问题，中文用拼音代替）：\n");
    for (int j = 0; j < i; j++)
    {
        printf("%s ", dcsj[j].px);
        printf("  ");
        printf("%ls", dcsj[j].zw);
        printf("\n");
    }
    system("pause");
}
void delword()
{
    typedef struct stu {
        char px[500];
        char zw[500];
    } dcxx;
    dcxx dcsj[1000];
    FILE* fp;
    // 读取文件中的单词到内存数组
    fp = fopen("words.txt", "r");
    if (!fp) {
        printf("文件打开失败！\n");
        exit(1);
    }
    char word[100];
    printf("请输入要删除的单词：");
    scanf("%s", word);
    int i = 0;
    while (fscanf(fp, "%s %s", dcsj[i].px, dcsj[i].zw) != EOF) {
        i++;
    }
    int totalWords = i;
    fclose(fp);
    // 从内存数组中查找并删除目标单词
    int found = 0;
    for (i = 0; i < totalWords; i++) {
        if (strcmp(dcsj[i].px, word) == 0 || strcmp(dcsj[i].zw, word) == 0) {
            // 找到目标单词，将其后面的单词依次前移
            found = 1;
            for (int j = i; j < totalWords - 1; j++) {
                strcpy(dcsj[j].px, dcsj[j + 1].px);
                strcpy(dcsj[j].zw, dcsj[j + 1].zw);
            }
            break;
        }
    }
    if (!found) {
        printf("未找到要删除的单词！\n");
        return;
    }
    // 将修改后的单词列表写回文件
    fp = fopen("words.txt", "w");
    if (!fp) {
        printf("文件打开失败！\n");
        exit(1);
    }
    for (i = 0; i < totalWords - 1; i++) {
        fprintf(fp, "%s %s\n", dcsj[i].px, dcsj[i].zw);
    }
    fclose(fp);
    printf("删除成功！\n");
    system("pause");
}
void findword()
{
    typedef struct stu {
        char px[500];
        char zw[500];
    } dcxx;
    int count = 0;               // 定义整型数
    char search[500];            // 定义字符数组，用来存储用户输入的待查找的单词
    dcxx dcsj[1000];             // 定义结构体数组，用来存储单词数据
    int i = 0;
    FILE* fp1;                   // 定义文件指针
    fp1 = fopen("words.txt", "r");  // 打开文件以读取单词数据
    if (!fp1)                    // 判断文件是否成功打开
    {
        printf("file error\n");
        exit(1);
    }
    while (fscanf(fp1, "%s%s", dcsj[i].px, dcsj[i].zw) != EOF)  // 将文件中的单词数据读出并存储到结构体数组
    {
        i++;
    }
    fclose(fp1);   // 关闭文件
    count = i;        // 记录单词总数
    // 读取用户需要查找的单词
    printf("请输入要查找的单词：\n");
    scanf("%s", search);
    // 遍历结构体数组查找单词
    int flag = 1;
    for (i = 0; i < count; i++)
    {
        if (strcmp(search, dcsj[i].px) == 0 || strcmp(search, dcsj[i].zw) == 0 && i < count)  // 进行英文或中文比对
        {
            printf("已找到该单词!\n");
            printf("英文：%s\n", dcsj[i].px);
            printf("中文：%s\n", dcsj[i].zw);
            flag = 1;
        }
    }
    if (!flag)
        printf("查找不到该单词\n");
    system("pause");    // 清屏
}
void addword() {
    int count = 0;
    typedef struct stu {
        char px[500];
        char zw[500];
    } dcxx;
    dcxx dcsj[1000];
    FILE* fp;

    fp = fopen("words.txt", "a+"); // 以追加模式打开文件，若没有此文件则自动创建
    if (!fp) {
        printf("文件打开失败！\n");
        exit(1);
    }
    printf("请输入要添加的单词及其翻译（中文或英文）：\n");
    printf("英文：");
    scanf("%s", dcsj[count].px);
    printf("中文：");
    wscanf(L"%ls", dcsj[count].zw);
    fprintf(fp, "%s   ", dcsj[count].px); // 将新单词写入文件
    fwprintf(fp, L"%s\n", dcsj[count].zw);
    count++;
    fclose(fp); // 关闭文件
    printf("添加成功！\n");
    system("pause");
}
void cuotiben()
{
    typedef struct stu {
        char px[100];    // 用来存储单词英文
        wchar_t zw[100];    // 用来存储单词中文
    } dcxx;
    int i = 0;
    char dy;  // 定义字符变量
    dcxx dcsj[1000];      // 定义文件指针
    // 定义结构体数组，用来存储单词信息
    FILE* fp;
    fp = fopen("cuotiben.txt", "r"); // 以只读的形式打开单词本文件
    if (!fp)   // 判断文件是否成功打开
    {
        printf("file error!\n");
        return;
    }

    while (fscanf(fp, "%s%ls", dcsj[i].px, dcsj[i].zw) != EOF)  // 将单词本内的单词信息存储到结构体数组中
    {
        i++;
    }
    fclose(fp);   // 关闭文件
    printf("单词本信息如下(技术问题，中文用拼音代替）：\n");
    for (int j = 0; j < i; j++)  // 输出用于存储单词信息的结构体的内容
    {
        printf("%s %ls\n", dcsj[j].px, dcsj[j].zw);
    }
    printf("\n按任意键并回车后返回主菜单！\n");
    scanf("   %c", &dy);  // 将用户输入的任意字符存储到字符变量里，并执行下一步
    system("cls");    // 清屏
}
void destorycuotiben()
{
    const char* filename = "cuotiben.txt";
    remove(filename);
    // 创建一个新的和原文件名称相同的文件
    FILE* fp = fopen(filename, "w");
    fclose(fp);
    system("cls");
}
int Exit()
{
    printf("要退出吗\n1.是2.否");
    int a;
    scanf("%d", &a);
    if (a == 1)
        return 0;
    if (a == 2)
        return 1;
}
#endif // !SECFUNC_H

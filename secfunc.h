#ifndef SECFUNC_H
#define SECFUNC_H
#include<stdio.h>
#include"register.h"
#include <thread>
bool check(unsigned char c) {
    //ͨ��utf-8�ֽ�������ж�
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
    char dy;  // �����ַ�����
    dcxx dcsj[1000];  // ����ṹ�����飬�����洢������Ϣ
    FILE* fp;             // �����ļ�ָ��
    fp = fopen("words.txt", "r"); // ��ֻ������ʽ�򿪵��ʱ��ļ�
    if (!fp)   // �ж��ļ��Ƿ�ɹ���
    {
        printf("file error!\n");
        return;
    }
    while (fscanf(fp, "%s%ls", dcsj[i].px, dcsj[i].zw) != EOF)
    {
        i++;
    }
    fclose(fp);
    printf("���ʱ���Ϣ����(�������⣬������ƴ�����棩��\n");
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
    // ��ȡ�ļ��еĵ��ʵ��ڴ�����
    fp = fopen("words.txt", "r");
    if (!fp) {
        printf("�ļ���ʧ�ܣ�\n");
        exit(1);
    }
    char word[100];
    printf("������Ҫɾ���ĵ��ʣ�");
    scanf("%s", word);
    int i = 0;
    while (fscanf(fp, "%s %s", dcsj[i].px, dcsj[i].zw) != EOF) {
        i++;
    }
    int totalWords = i;
    fclose(fp);
    // ���ڴ������в��Ҳ�ɾ��Ŀ�굥��
    int found = 0;
    for (i = 0; i < totalWords; i++) {
        if (strcmp(dcsj[i].px, word) == 0 || strcmp(dcsj[i].zw, word) == 0) {
            // �ҵ�Ŀ�굥�ʣ��������ĵ�������ǰ��
            found = 1;
            for (int j = i; j < totalWords - 1; j++) {
                strcpy(dcsj[j].px, dcsj[j + 1].px);
                strcpy(dcsj[j].zw, dcsj[j + 1].zw);
            }
            break;
        }
    }
    if (!found) {
        printf("δ�ҵ�Ҫɾ���ĵ��ʣ�\n");
        return;
    }
    // ���޸ĺ�ĵ����б�д���ļ�
    fp = fopen("words.txt", "w");
    if (!fp) {
        printf("�ļ���ʧ�ܣ�\n");
        exit(1);
    }
    for (i = 0; i < totalWords - 1; i++) {
        fprintf(fp, "%s %s\n", dcsj[i].px, dcsj[i].zw);
    }
    fclose(fp);
    printf("ɾ���ɹ���\n");
    system("pause");
}
void findword()
{
    typedef struct stu {
        char px[500];
        char zw[500];
    } dcxx;
    int count = 0;               // ����������
    char search[500];            // �����ַ����飬�����洢�û�����Ĵ����ҵĵ���
    dcxx dcsj[1000];             // ����ṹ�����飬�����洢��������
    int i = 0;
    FILE* fp1;                   // �����ļ�ָ��
    fp1 = fopen("words.txt", "r");  // ���ļ��Զ�ȡ��������
    if (!fp1)                    // �ж��ļ��Ƿ�ɹ���
    {
        printf("file error\n");
        exit(1);
    }
    while (fscanf(fp1, "%s%s", dcsj[i].px, dcsj[i].zw) != EOF)  // ���ļ��еĵ������ݶ������洢���ṹ������
    {
        i++;
    }
    fclose(fp1);   // �ر��ļ�
    count = i;        // ��¼��������
    // ��ȡ�û���Ҫ���ҵĵ���
    printf("������Ҫ���ҵĵ��ʣ�\n");
    scanf("%s", search);
    // �����ṹ��������ҵ���
    int flag = 1;
    for (i = 0; i < count; i++)
    {
        if (strcmp(search, dcsj[i].px) == 0 || strcmp(search, dcsj[i].zw) == 0 && i < count)  // ����Ӣ�Ļ����ıȶ�
        {
            printf("���ҵ��õ���!\n");
            printf("Ӣ�ģ�%s\n", dcsj[i].px);
            printf("���ģ�%s\n", dcsj[i].zw);
            flag = 1;
        }
    }
    if (!flag)
        printf("���Ҳ����õ���\n");
    system("pause");    // ����
}
void addword() {
    int count = 0;
    typedef struct stu {
        char px[500];
        char zw[500];
    } dcxx;
    dcxx dcsj[1000];
    FILE* fp;

    fp = fopen("words.txt", "a+"); // ��׷��ģʽ���ļ�����û�д��ļ����Զ�����
    if (!fp) {
        printf("�ļ���ʧ�ܣ�\n");
        exit(1);
    }
    printf("������Ҫ��ӵĵ��ʼ��䷭�루���Ļ�Ӣ�ģ���\n");
    printf("Ӣ�ģ�");
    scanf("%s", dcsj[count].px);
    printf("���ģ�");
    wscanf(L"%ls", dcsj[count].zw);
    fprintf(fp, "%s   ", dcsj[count].px); // ���µ���д���ļ�
    fwprintf(fp, L"%s\n", dcsj[count].zw);
    count++;
    fclose(fp); // �ر��ļ�
    printf("��ӳɹ���\n");
    system("pause");
}
void cuotiben()
{
    typedef struct stu {
        char px[100];    // �����洢����Ӣ��
        wchar_t zw[100];    // �����洢��������
    } dcxx;
    int i = 0;
    char dy;  // �����ַ�����
    dcxx dcsj[1000];      // �����ļ�ָ��
    // ����ṹ�����飬�����洢������Ϣ
    FILE* fp;
    fp = fopen("cuotiben.txt", "r"); // ��ֻ������ʽ�򿪵��ʱ��ļ�
    if (!fp)   // �ж��ļ��Ƿ�ɹ���
    {
        printf("file error!\n");
        return;
    }

    while (fscanf(fp, "%s%ls", dcsj[i].px, dcsj[i].zw) != EOF)  // �����ʱ��ڵĵ�����Ϣ�洢���ṹ��������
    {
        i++;
    }
    fclose(fp);   // �ر��ļ�
    printf("���ʱ���Ϣ����(�������⣬������ƴ�����棩��\n");
    for (int j = 0; j < i; j++)  // ������ڴ洢������Ϣ�Ľṹ�������
    {
        printf("%s %ls\n", dcsj[j].px, dcsj[j].zw);
    }
    printf("\n����������س��󷵻����˵���\n");
    scanf("   %c", &dy);  // ���û�����������ַ��洢���ַ��������ִ����һ��
    system("cls");    // ����
}
void destorycuotiben()
{
    const char* filename = "cuotiben.txt";
    remove(filename);
    // ����һ���µĺ�ԭ�ļ�������ͬ���ļ�
    FILE* fp = fopen(filename, "w");
    fclose(fp);
    system("cls");
}
int Exit()
{
    printf("Ҫ�˳���\n1.��2.��");
    int a;
    scanf("%d", &a);
    if (a == 1)
        return 0;
    if (a == 2)
        return 1;
}
#endif // !SECFUNC_H

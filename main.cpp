#include<easyx.h>//easyx ͼ�ο��ͷ�ļ������ڻ���ͼ�ν���
#include<locale.h>//���ػ����ÿ��ͷ�ļ����ṩ��һЩ�뱾�ػ�������صĺ���
#include<stdbool.h>//��׼���ͷ�ļ��������� bool ���ͺ� true/false ������
#include<process.h>//���̿��ƿ��ͷ�ļ����ṩ��һЩ�������صĺ���������
#include<atomic>//C++11 ��׼�ṩ��ԭ�Ӳ���ͷ�ļ�������ʵ�ֶ��̻߳����µ�ԭ�Ӳ���
#include"func.h"
#include"overgame.h"
#include"gamehelp.h"
#include"playtime.h"
#include"register.h"
#include"welcome_origin.h"
#include"music_control.h"
#include"student_rank.h"
#include"button.h"
#include"second.h"
#include"playgame.h"
#include"secfunc.h"
#include<thread>// C++11 �ṩ���߳̿��ͷ�ļ����ṩ��һЩ���߳���صĺ��������ͣ����ڴ����͹����̡߳�

#pragma comment(lib,"winmm.lib")//�ṩ��һЩ���ý�崦����صĺ��������͡�
#pragma warning (disable:4996)//�����������ض��ľ�����
#undef UNICODE
#undef _UNICODE//��ʾʹ�� Unicode �ַ���

#define max_len 50
#define max_word 100
/*char mingzi[20];
char shuru[8];*/
//bool returnToMainMenu = false;
const int window_width = 800;
const int window_height = 600;
/*void welcome_music();//��������
void pausemusic();//ֹͣ���ֲ���
void resumemusic();//��������
void Loadimage();//����ͼ�λ�����
int welcome();//��ӭ����
void play_word_game();//�淨
void goodbye();//�ټ�
void show_word(wchar_t* word);//��ʾҪ��ĵ���
void modify_word(wchar_t* word);//���ѡ������λ�ã�����������λ�ö�Ӧ���ַ��滻Ϊ�»��ߺͿո����ϡ�
wchar_t* copy_word(wchar_t* word);//���Ƶ���
void compare_word(wchar_t* correct_word);//�Ƚϵ���
void read_word(wchar_t words[][max_len + 1], int max_words, int* count_word);//���ļ��ж�ȡ����
void DisplayThread();//��ʾ����ʱ��
//void countdown(int seconds);//����ʱ
void game_help();//��Ϸ����
void second_game();//�ڶ����
void Menu();//�ڶ�����Ĳ˵�
void Visit();//��ʾ���ʱ��е���
void delword();//ɾ������
void addword();//���ӵ���
void findword();//�����ض�����
void drawButton(struct button* pB);//���ư�ť
int mouseInButton(struct button* pB, MOUSEMSG m);//��괥������
void music_help();//��������
void Register();//ע��
void Loading();//��¼
void RegisterorLoading();//ע���¼��ת
void cuotiben();//���Ȿ
void printInfo();//�����¼����
void switchmusic();//��������
void playmusic(int n);//��������
int compare_scores(const void* a, const void* b);//�ȽϷ���
void output_students();//���а�
void destorycuotiben();//��մ���
int Exit();//�˳�*/
/*typedef struct {
    char name[20];
    int wordcount;
} Student;
Student student[200];*/
//int num = 0, numrank = 0, flag = 1;//num���������������а�
//int n = 0;
int main()
{
    setlocale(LC_ALL, "");//���ػ��ĺ������ã����ڽ�����ı��ػ���������Ϊ�û���Ĭ�ϱ��ػ����á�
    initgraph(800, 600);
    Loadimage();
    welcome_music();
    std::thread displayThread(DisplayThread); // ��������ʱ���߳�
    //std::thread countdownThread(countdown); // ��������ʱ�߳�
    while (true)
    {

        int button = welcome();

        if (button == 0)
        {
            play_word_game();
        }
        else if (button == 1)
        {
            cleardevice();
            exit(0);
            return 0;
        }
        else if (button == 2)
        {
            second_game();
        }
        else if (button == 3)
        {
            game_help();
        }
        else if (button == 4)
        {
            pausemusic();
        }
        else if (button == 5)
        {
            resumemusic();
        }
        else if (button == 6)
        {
            switchmusic();
        }
    }
    return 0;
}
/*void countdown(int seconds)
{
    time_t endTime = time(nullptr) + seconds;
    //time_t ��һ�����ͣ����ڱ�ʾ��ĳ���ض���㿪ʼ�����ʱ��ֵ
    while (time(nullptr) < endTime)
    {
        settextcolor(YELLOW);
        settextstyle(20, 0, _T("Consolas"));

        // ���ԭ����ʱ��
        setfillcolor(BLACK); // ���������ɫΪ��ɫ
        solidrectangle(0, 140, 170, 160); // ���һ����������
        int remaining = endTime - time(nullptr);
        int minutes = remaining / 60;
        int seconds = remaining % 60;

        TCHAR timeString[8];
        _stprintf(timeString,_T("%02d:%02d"), minutes, seconds);
        //��ʽ��������������ڽ���ʽ������ַ���д�뵽 timeString ������
        settextstyle(40, 0, _T("Arial"));  // �����ı���ʽ
        outtextxy(0, 140, timeString);  // ��ָ��λ�û��Ƶ���ʱ
        //_T ��һ���꣬�����ڿ�ƽ̨�����ʵ�ֿ��ַ���խ�ַ��ļ�����
        Sleep(1000);  // ��ͣ1��
    }
}
void DisplayThread()
{
    while (1)
    {

        settextcolor(YELLOW);
        settextstyle(20, 0, _T("Consolas"));

        // ���ԭ����ʱ��
        setfillcolor(BLACK); // ���������ɫΪ��ɫ
        solidrectangle(0, 200, 170, 220); // ���һ����������
        // ��ȡ��ǰ���ں�ʱ��
        time_t now;
        time(&now);//��ȡ��ǰʱ��� time_t ֵ��������洢�� now �����С�
        struct tm* timeInfo = localtime(&now);
        //ͨ�� localtime(&now) �� time_t ֵת��Ϊ����ʱ��Ľṹ�� struct tm��������ָ��洢�� timeInfo �����С�
        // ��ʽ�����ں�ʱ��
        TCHAR currentTime[20];
        _tcsftime(currentTime, sizeof(currentTime) / sizeof(TCHAR), _T("%Y-%m-%d %H:%M:%S"), timeInfo);
        //_tcsftime ������ʱ��ṹ�� timeInfo �е����ں�ʱ���ʽ��Ϊ�ַ�������������洢�� currentTime �����С�
        int weekday = timeInfo->tm_wday;
        //timeInfo->tm_wday ��ȡ��ǰ���ڶ�Ӧ�����ڼ���ֵ����������洢�����ͱ��� weekday ��
        TCHAR weekdayStr[10];

        // ���� weekday ֵ���ö�Ӧ�����ڼ��ַ���
        switch (weekday)
        {
        case 0:
            _tcscpy(weekdayStr, _T("������"));
            break;
        case 1:
            _tcscpy(weekdayStr, _T("����һ"));
            break;
        case 2:
            _tcscpy(weekdayStr, _T("���ڶ�"));
            break;
        case 3:
            _tcscpy(weekdayStr, _T("������"));
            break;
        case 4:
            _tcscpy(weekdayStr, _T("������"));
            break;
        case 5:
            _tcscpy(weekdayStr, _T("������"));
            break;
        case 6:
            _tcscpy(weekdayStr, _T("������"));
            break;
        default:
            _tcscpy(weekdayStr, _T("δ֪"));
            break;
        }
        // ����Ļ�ϻ������ں�ʱ��
        setbkmode(TRANSPARENT);
        settextcolor(YELLOW); // �����ı���ɫ
        settextstyle(20, 0, _T("Consolas")); // �����ı���ʽ
        // �����ı�
        outtextxy(0, 200, currentTime);
        settextcolor(BLACK);
        outtextxy(0, 230, weekdayStr);
        FlushBatchDraw(); // ˢ�»�ͼ������
        Sleep(1000); // ��ͣ1��
    }
}*/
/*void welcome_music()
{
    wchar_t music_file[] = L"welcome.mp3";//wchar_t
    wchar_t a[256];
    swprintf_s(a, 256, L"open welcome.mp3 alias currentSong", music_file);
    mciSendString(a, NULL, 0, NULL);
    mciSendString(L"play currentSong repeat", NULL, 0, NULL);
}//���ر�������
void pausemusic()
{
    wchar_t music_file[] = L"welcome.mp3";//wchar_t
    wchar_t a[256];
    swprintf_s(a, 256, L"open welcome.mp3 alias currentSong", music_file);
    mciSendString(a, NULL, 0, NULL);
    mciSendString(L"stop currentSong", NULL, 0, NULL);

    returnToMainMenu = true;
}
void resumemusic()
{
    mciSendString(L"resume currentSong", NULL, 0, NULL);
    returnToMainMenu = true;
}*/
/*
void Loadimage()//����ͼƬ
{
    IMAGE photo;
    loadimage(&photo, L"photo.jpg");
    putimage(0, 0, &photo);
}
int welcome()//��ӭͼƬ
{
    initgraph(800, 600);
    Loadimage();
    output_students();
    settextstyle(50, 0, _T("����"));
    settextcolor(BLUE);
    setbkmode(TRANSPARENT);

    outtextxy(200, 0, _T("��Щ�����赥��"));
    outtextxy(230, 60, _T("���ڱ�����"));

    settextstyle(20, 0, _T("Grinched"));
    settextcolor(BLUE);
    setbkmode(TRANSPARENT);
    outtextxy(0, 500, _T("������Ա������С��"));
    outtextxy(0, 520, _T("������Ա������� ������"));
    outtextxy(0, 540, _T("���������������"));
    outtextxy(0, 560, _T("������Ա��֧��"));
    outtextxy(500, 560, _T("����Ӣ��ĳ���Ա���Ǻó���Ա"));

    settextstyle(14, 0, _T("Grinched"));
    settextcolor(RED);
    setbkmode(TRANSPARENT);

    outtextxy(480, 200, _T("���˶�������"));
    outtextxy(480, 230, _T("Ŀ��������ϤC���Ե�ʵ��Ӧ��"));
    outtextxy(480, 260, _T("�Ͼ��кܶණ�����ǵ�һ�νӴ�"));
    outtextxy(480, 290, _T("����������Ҳ��ʶ�˺ܶ����벻��������"));
    outtextxy(480, 320, _T("C���Ժܲ����п����Ժ���c++"));
    outtextxy(480, 350, _T("ͷ�ļ���ʹ������������Ч��"));

    RECT rect = { 300, 200, 480, 250 };
    const int button_len = 180;
    const int button_high = 50;
    const int button_count = 7;
    int y = rect.top;
    int word_button = -1;
    for (int i = 0; i < button_count; i++)
    {
        RECT buttonRect = { rect.left, y, rect.right, y + button_high };
        const wchar_t* word_button_text = nullptr;//���ݰ�ť������ i �����ö�Ӧ�İ�ť�ı�
        switch (i)
        {
        case 0:
            word_button_text = L"��ʼ��Ϸ";
            break;
        case 1:
            word_button_text = L"������Ϸ";
            break;
        case 2:
            word_button_text = L"�ڶ����";
            break;
        case 3:
            word_button_text = L"��Ϸ˵��";
            break;
        case 4:
            word_button_text = L"ֹͣ����";
            break;
        case 5:
            word_button_text = L"��������";
            break;
        case 6:
            word_button_text = L"�л�����";
        }
        for (int j = 0; j < button_high; j++)
        {
            int r = 0, g = 0, b = 0;
            r = (i + 1) * 20;
            g = 0;
            b = 200 - i * 20;
            setlinecolor(RGB(r, g, b));
            setfillcolor(RGB(r, g, b));
            int top = buttonRect.top + j;
            int bottom = buttonRect.top + j + 1;
            solidrectangle(buttonRect.left + 1, top + 1, buttonRect.right - 1, bottom - 1);
        }
        
        �������������ͱ��� r��g��b�����ڱ�ʾ��ɫ�� RGB ����
        ͨ�� (i + 1) * 20 �����ɫ���� r ��ֵ��ͨ�� 200 - i * 20 ������ɫ���� b ��ֵ��
        ����ɫ���� g ���̶�Ϊ0���ڰ�ť���ƵĹ����У�����ݰ�ť������ i ��ͬ��
        ���㲢���ð�ť��������ɫ�������ɫ����ʵ��ÿ����ť��ɫ��ͬ��Ч����
        setbkmode(TRANSPARENT);//setbkmode �����ı�����ģʽΪ͸��
        settextstyle(35, 0, _T("Arial Bold"));
        settextcolor(RGB(255, 255, 255));
        rectangle(buttonRect.left, buttonRect.top, buttonRect.right, buttonRect.bottom);//solidrectangle ��������һ��ʵ�ľ���
        drawtext(word_button_text, &buttonRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        // word_button_text �����ڰ�ť�ڲ��� DT_CENTER | DT_VCENTER | DT_SINGLELINE �������ı����ж���
        y += 5 + button_high;
    }

    while (word_button == -1)
    {
        if (MouseHit())
        {
            MOUSEMSG msg = GetMouseMsg();
            if (msg.uMsg == WM_LBUTTONDOWN)
            {
                for (int i = 0; i < button_count; i++)
                {
                    RECT buttonRect = { rect.left, rect.top + (button_high + 5) * i, rect.right, rect.top + (button_high + 5) * i + button_high };
                    if (msg.x >= buttonRect.left && msg.x <= buttonRect.right && msg.y >= buttonRect.top && msg.y <= buttonRect.bottom)
                    {
                        word_button = i;
                        break;
                    }
                }
            }
        }
    }
    return word_button;
}*/
/*
void play_word_game()
{
    FILE* fp;
    fp = fopen("rank.txt", "a+");
    initgraph(800, 600);
    IMAGE photo;
    loadimage(&photo, L"photo.jpg");
    putimage(0, 0, &photo);
    wchar_t words[max_word][max_len + 1] = { 0 };
    int  num_words = 0, srand_word_pos;
    wchar_t* play_word;
    wchar_t* Copy_Word;
    wchar_t count[max_word];
    InputBox(count, max_word, L"������ƻ�������");
    int a = _wtoi(count);
    for (int k = 1; k <= a; k++)
    {
        read_word(words, max_word, &num_words);
        srand((unsigned)time(NULL));
        srand_word_pos = rand() % num_words;
        play_word = words[srand_word_pos];
        Copy_Word = copy_word(play_word);
        modify_word(play_word);
        show_word(play_word);
        compare_word(Copy_Word);
        free(Copy_Word);
    }
    student[numrank].wordcount = num;
    strcpy(student[numrank].name, "likeyan");
    fprintf(fp, "%s %d\n", student[numrank].name, student[numrank].wordcount);
    numrank++;
    fclose(fp);
    closegraph();
    goodbye();
}*/
/*void goodbye()
{
    cleardevice();
    initgraph(800, 600);
    IMAGE photo;
    loadimage(&photo, L"photo.jpg");
    putimage(0, 0, &photo);
    int color;
    srand((unsigned)time(NULL));//���� srand �����Ե�ǰʱ��Ϊ���ӳ�ʼ���������������
    color = RGB(rand() % 256, rand() % 256, rand() % 256);
    //rand ��������������������ֱ�ͨ��ȡģ���� % 256 �����޶��� 0 �� 255 �ķ�Χ��
    settextcolor(color);
    settextstyle(30, 0, _T("Arial Bold"));
    outtextxy(0, 0, L"congratulations on completing the challenge");
    while (!kbhit())
    {
        Sleep(100); // �ʵ���ʱ���������Ƶ����ѭ��
    }
    getch(); // �����������������ȡ�û�����
    closegraph(); // �رջ�ͼ����
    returnToMainMenu = true;
}*/
/*wchar_t* copy_word(wchar_t* word)//ȫ�Ŀ��ַ�����
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
void modify_word(wchar_t* word)
{
    int i, miss_pos1, miss_pos2;
    srand((unsigned)time(NULL));
    int word_len = wcslen(word);
    miss_pos1 = rand() % word_len;
    miss_pos2 = rand() % word_len;
    if (miss_pos2 == miss_pos1)
    {
        miss_pos2 = (miss_pos2 + 1) % word_len;
    }
    for (i = 0; word[i] != L'\0'; i++)
    {
        if (i == miss_pos1 || i == miss_pos2)
        {
            word[i] = L'_ ';
        }
    }
}
void read_word(wchar_t words[][max_len + 1], int max_words, int* count_word)
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
}*/
/*void game_help()
{
    initgraph(800, 600);
    IMAGE picture;
    loadimage(&picture, L"game_help.jpg");
    while (!kbhit())
    {
        putimage(0, 0, &picture);
    }
    while (!kbhit())
    {
        Sleep(100); // �ʵ���ʱ���������Ƶ����ѭ��
    }

    getch(); // ��ȡ�û�����

    closegraph(); // �رջ�ͼ����

    returnToMainMenu = true; // ���ñ�־����Ϊtrue����ʾ�������˵�
}*/
/*int compare_scores(const void* a, const void* b)
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
    typedef struct {
        char name[20];
        int wordcount;
    } Student;
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
}*/
/*void second_game()
{
    FreeConsole(); //����ԭ�еĿ���̨
    AllocConsole(); //����һ���µĿ���̨
    SetConsoleTitleA("second_game");
    RegisterorLoading();
    Menu();
}
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
}*/
/*void Visit()
{
    typedef struct stu {
        char px[100];    // �����洢����Ӣ��
        wchar_t zw[100];    // �����洢��������
    } dcxx;
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

    while (fscanf(fp, "%s%ls", dcsj[i].px, dcsj[i].zw) != EOF)  // �����ʱ��ڵĵ�����Ϣ�洢���ṹ��������
    {
        i++;
    }

    fclose(fp);   // �ر��ļ�

    printf("���ʱ���Ϣ����(�������⣬������ƴ�����棩��\n");
    for (int j = 0; j < i; j++)  // ������ڴ洢������Ϣ�Ľṹ�������
    {
        printf("%s ", dcsj[j].px);
        wprintf(L"%ls", dcsj[j].zw);
        printf("\n");
    }

    system("pause");

}*/
/*void delword()
{
    int ch = 0, count = 0, count1 = 0;  //����������
    char del[500];              //�����ַ����飬�����洢�û�����ģ���Ҫɾ���ģ�����
    typedef struct stu          //����ṹ��
    {
        char px[500];
        char zw[500];
    }dcxx;
    dcxx dcsj[1000];            //����ṹ�����飬�����洢��������
    int i = 0;
    FILE* fp1, * fp2;               //�����ļ�ָ��
    fp1 = fopen("words.txt", "r+");   //�����ļ�ָ��ֱ�ָ�������ļ�
    fp2 = fopen("words1.txt", "w+");  //�ԡ�w+������ʽ�򿪣���û�д��ļ����Զ�����
    if (!fp1)                    //�ж��ļ��Ƿ�ɹ���
    {
        printf("file error\n");
        exit(1);
    };
    if (!fp2)
    {
        printf("file error\n");
        exit(1);
    };
    fscanf(fp1, "%s%s", dcsj[i].px, dcsj[i].zw);  //���ļ��еĵ������ݶ������洢���ṹ������
    while (!feof(fp1))
    {
        i++;
        fscanf(fp1, "%s%s",dcsj[i].px, dcsj[i].zw);
    }
    fclose(fp1);   //�ر��ļ�
    count = i;        //��¼��������
    printf("��������Ҫɾ���ĵ��ʣ����Ļ�Ӣ�ģ���\n");
    scanf("%s", del);  //��ȡ�û���Ҫɾ���ĵ���
    for (i = 0; i < count + 1; i++)  //�ж��ļ�����û���û���Ҫɾ���ĵ���
    {
        if (!strcmp(del, dcsj[i].px))  //����Ӣ�ıȶ�
        {
            ch = 1;  //�ı�ch��ֵ������֮���ж��Ƿ��ҵ��õ���
            printf("���ҵ��õ��ʲ�ɾ��!\n");
            count1 = i;    //��¼�����ڽṹ�������е�λ��
            break;       //���ҵ��������˳�forѭ��
        }
        if (!strcmp(del, dcsj[i].zw))  //�������ıȶ�
        {
            ch = 1;
            printf("���ҵ��õ��ʲ�ɾ��!\n");
            count1 = i;
            break;
        }
    }
    if (ch == 0) //���Ҳ����õ��ʣ������д˲���
    {
        printf("�鲻���õ��ʣ�\n");
        //Menu();
    }
    strcpy(dcsj[count + 1].px, "###");
    strcpy(dcsj[count + 1].zw, "###");
    for (i = count1; i < count; i++)  //��Ҫɾ���ĵ��ʵ�λ�ÿ�ʼ������forѭ�������ν����ʡ���ǰ�ơ�������Ҫɾ���ĵ���
    {
        dcsj[i] = dcsj[i + 1];
    }
    i = 0;  //��i�������¸�ֵ
    printf("���º�ĵ��ʱ�Ϊ��\n");
    while (count!= 0)   //������º�ĵ��ʱ��������º�ĵ���д�뵥���ʱ������ļ���
    {
        fprintf(fp2, "%s %s\n",dcsj[i].px, dcsj[i].zw);
        printf("%s %s\n",dcsj[i].px, dcsj[i].zw);
        count--;
        i++;
    };
    rename("words1.txt", "words.txt");
    rename("words.txt", "words1.txt");
    fclose(fp2); //�ر��ļ�
}*/
/*
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
        if (strcmp(search, dcsj[i].px) == 0 || strcmp(search, dcsj[i].zw) == 0&&i<count)  // ����Ӣ�Ļ����ıȶ�
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
    scanf("%ls", dcsj[count].zw);

    fprintf(fp, "%s %s\n", dcsj[count].px, dcsj[count].zw); // ���µ���д���ļ�

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
    scanf(" %c", &dy);  // ���û�����������ַ��洢���ַ��������ִ����һ��
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
}*/
/*struct button
{
    int x;
    int y;
    int width;
    int height;
    COLORREF color;
    char* pText;
};
//��ʼ����ť����
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
    settextstyle(35, 0, _T("����"));
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
void music_help()
{
    struct button* pause = createButton(0, 205, 180, 50, YELLOW, "stop music");
    struct button* resume = createButton(0, 260, 180, 50, YELLOW, "continue music");
    while (1)
    {
        BeginBatchDraw();
        MOUSEMSG m = GetMouseMsg();
        drawButton(pause);
        drawButton(resume);
        if (clickButton(pause, m))
        {
            mciSendString(L"pause welcome.mp3", 0, 0, 0);
        }
        if (clickButton(resume, m))
        {
            mciSendString(L"resume welcome.mp3", 0, 0, 0);
        }
        EndBatchDraw();
    }
}*/
/*void RegisterorLoading()      //ע�����¼����
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
}*/
/*void printInfo()           //�������ο�
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
}*/
/*void playmusic(int n)
{
    //mciSendString("open song2.mp3 alias currentSong", NULL, 0, NULL);
    switch (n)
    {
    case 1:
        // ֹͣ���ŵ�ǰ����
        mciSendString(L"close currentSong", NULL, 0, NULL);
        // ���ŵ�һ�׸���
        mciSendString(L"open music1.mp3 alias currentSong ", NULL, 0, NULL);
        break;
    case 2:
        // ֹͣ���ŵ�ǰ����
        mciSendString(L"close currentSong ", NULL, 0, NULL);
        // ���ŵڶ��׸���
        mciSendString(L"open music2.mp3 alias currentSong", NULL, 0, NULL);
        break;
    case 3:
        // ֹͣ���ŵ�ǰ����
        mciSendString(L"close currentSong", NULL, 0, NULL);
        // ���ŵ����׸���
        mciSendString(L"open music3.mp3 alias currentSong", NULL, 0, NULL);
        break;
    case 4:
        mciSendString(L"close currentSong", NULL, 0, NULL);
        mciSendString(L"open music4.mp3 alias currentSong", NULL, 0, NULL);
        break;
    case 0:
        mciSendString(L"close currentSong", NULL, 0, NULL);
        mciSendString(L"open welcome.mp3 alias currentSong", NULL, 0, NULL);
        // ���Ը������������Ӹ���ĸ���
    }

    // ���ŵ�ǰ�ĸ���
    mciSendString(L"play currentSong repeat", NULL, 0, NULL);
}
void switchmusic()
{
    n = (n + 1) % 5; // �л���������
    playmusic(n); // �����µĸ���
}*/
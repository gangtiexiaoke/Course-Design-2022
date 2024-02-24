#include<easyx.h>//easyx 图形库的头文件，用于绘制图形界面
#include<locale.h>//本地化设置库的头文件，提供了一些与本地化设置相关的函数
#include<stdbool.h>//标准库的头文件，定义了 bool 类型和 true/false 常量。
#include<process.h>//进程控制库的头文件，提供了一些与进程相关的函数和类型
#include<atomic>//C++11 标准提供的原子操作头文件，用于实现多线程环境下的原子操作
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
#include<thread>// C++11 提供的线程库的头文件，提供了一些与线程相关的函数和类型，用于创建和管理线程。

#pragma comment(lib,"winmm.lib")//提供了一些与多媒体处理相关的函数和类型。
#pragma warning (disable:4996)//编译器禁用特定的警告编号
#undef UNICODE
#undef _UNICODE//表示使用 Unicode 字符集

#define max_len 50
#define max_word 100
/*char mingzi[20];
char shuru[8];*/
//bool returnToMainMenu = false;
const int window_width = 800;
const int window_height = 600;
/*void welcome_music();//背景音乐
void pausemusic();//停止音乐播放
void resumemusic();//继续播放
void Loadimage();//加载图形化界面
int welcome();//欢迎界面
void play_word_game();//玩法
void goodbye();//再见
void show_word(wchar_t* word);//显示要填的单词
void modify_word(wchar_t* word);//随机选择两个位置，并将这两个位置对应的字符替换为下划线和空格的组合。
wchar_t* copy_word(wchar_t* word);//复制单词
void compare_word(wchar_t* correct_word);//比较单词
void read_word(wchar_t words[][max_len + 1], int max_words, int* count_word);//从文件中读取单词
void DisplayThread();//显示日期时间
//void countdown(int seconds);//倒计时
void game_help();//游戏帮助
void second_game();//第二软件
void Menu();//第二软件的菜单
void Visit();//显示单词本中单词
void delword();//删除单词
void addword();//增加单词
void findword();//查找特定单词
void drawButton(struct button* pB);//绘制按钮
int mouseInButton(struct button* pB, MOUSEMSG m);//鼠标触发函数
void music_help();//播放音乐
void Register();//注册
void Loading();//登录
void RegisterorLoading();//注册登录跳转
void cuotiben();//错题本
void printInfo();//输出登录界面
void switchmusic();//更换音乐
void playmusic(int n);//播放音乐
int compare_scores(const void* a, const void* b);//比较分数
void output_students();//排行榜
void destorycuotiben();//清空错题
int Exit();//退出*/
/*typedef struct {
    char name[20];
    int wordcount;
} Student;
Student student[200];*/
//int num = 0, numrank = 0, flag = 1;//num用来计数，在排行榜
//int n = 0;
int main()
{
    setlocale(LC_ALL, "");//本地化的函数调用，用于将程序的本地化设置设置为用户的默认本地化设置。
    initgraph(800, 600);
    Loadimage();
    welcome_music();
    std::thread displayThread(DisplayThread); // 开启日期时间线程
    //std::thread countdownThread(countdown); // 开启倒计时线程
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
    //time_t 是一个类型，用于表示从某个特定起点开始计算的时间值
    while (time(nullptr) < endTime)
    {
        settextcolor(YELLOW);
        settextstyle(20, 0, _T("Consolas"));

        // 清除原来的时间
        setfillcolor(BLACK); // 设置填充颜色为黑色
        solidrectangle(0, 140, 170, 160); // 清除一个矩形区域
        int remaining = endTime - time(nullptr);
        int minutes = remaining / 60;
        int seconds = remaining % 60;

        TCHAR timeString[8];
        _stprintf(timeString,_T("%02d:%02d"), minutes, seconds);
        //格式化输出函数，用于将格式化后的字符串写入到 timeString 数组中
        settextstyle(40, 0, _T("Arial"));  // 设置文本样式
        outtextxy(0, 140, timeString);  // 在指定位置绘制倒计时
        //_T 是一个宏，用于在跨平台编程中实现宽字符和窄字符的兼容性
        Sleep(1000);  // 暂停1秒
    }
}
void DisplayThread()
{
    while (1)
    {

        settextcolor(YELLOW);
        settextstyle(20, 0, _T("Consolas"));

        // 清除原来的时间
        setfillcolor(BLACK); // 设置填充颜色为黑色
        solidrectangle(0, 200, 170, 220); // 清除一个矩形区域
        // 获取当前日期和时间
        time_t now;
        time(&now);//获取当前时间的 time_t 值，并将其存储在 now 变量中。
        struct tm* timeInfo = localtime(&now);
        //通过 localtime(&now) 将 time_t 值转换为本地时间的结构体 struct tm，并将其指针存储在 timeInfo 变量中。
        // 格式化日期和时间
        TCHAR currentTime[20];
        _tcsftime(currentTime, sizeof(currentTime) / sizeof(TCHAR), _T("%Y-%m-%d %H:%M:%S"), timeInfo);
        //_tcsftime 函数将时间结构体 timeInfo 中的日期和时间格式化为字符串，并将结果存储在 currentTime 数组中。
        int weekday = timeInfo->tm_wday;
        //timeInfo->tm_wday 获取当前日期对应的星期几的值，并将结果存储在整型变量 weekday 中
        TCHAR weekdayStr[10];

        // 根据 weekday 值设置对应的星期几字符串
        switch (weekday)
        {
        case 0:
            _tcscpy(weekdayStr, _T("星期日"));
            break;
        case 1:
            _tcscpy(weekdayStr, _T("星期一"));
            break;
        case 2:
            _tcscpy(weekdayStr, _T("星期二"));
            break;
        case 3:
            _tcscpy(weekdayStr, _T("星期三"));
            break;
        case 4:
            _tcscpy(weekdayStr, _T("星期四"));
            break;
        case 5:
            _tcscpy(weekdayStr, _T("星期五"));
            break;
        case 6:
            _tcscpy(weekdayStr, _T("星期六"));
            break;
        default:
            _tcscpy(weekdayStr, _T("未知"));
            break;
        }
        // 在屏幕上绘制日期和时间
        setbkmode(TRANSPARENT);
        settextcolor(YELLOW); // 设置文本颜色
        settextstyle(20, 0, _T("Consolas")); // 设置文本样式
        // 绘制文本
        outtextxy(0, 200, currentTime);
        settextcolor(BLACK);
        outtextxy(0, 230, weekdayStr);
        FlushBatchDraw(); // 刷新绘图缓冲区
        Sleep(1000); // 暂停1秒
    }
}*/
/*void welcome_music()
{
    wchar_t music_file[] = L"welcome.mp3";//wchar_t
    wchar_t a[256];
    swprintf_s(a, 256, L"open welcome.mp3 alias currentSong", music_file);
    mciSendString(a, NULL, 0, NULL);
    mciSendString(L"play currentSong repeat", NULL, 0, NULL);
}//加载背景音乐
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
void Loadimage()//背景图片
{
    IMAGE photo;
    loadimage(&photo, L"photo.jpg");
    putimage(0, 0, &photo);
}
int welcome()//欢迎图片
{
    initgraph(800, 600);
    Loadimage();
    output_students();
    settextstyle(50, 0, _T("楷体"));
    settextcolor(BLUE);
    setbkmode(TRANSPARENT);

    outtextxy(200, 0, _T("那些年生疏单词"));
    outtextxy(230, 60, _T("现在保熟吗？"));

    settextstyle(20, 0, _T("Grinched"));
    settextcolor(BLUE);
    setbkmode(TRANSPARENT);
    outtextxy(0, 500, _T("开发人员：钢铁小科"));
    outtextxy(0, 520, _T("测试人员：尹宇飞 刘嘉琪"));
    outtextxy(0, 540, _T("创意帮助：王雨欣"));
    outtextxy(0, 560, _T("音乐人员：支书"));
    outtextxy(500, 560, _T("不会英语的程序员不是好程序员"));

    settextstyle(14, 0, _T("Grinched"));
    settextcolor(RED);
    setbkmode(TRANSPARENT);

    outtextxy(480, 200, _T("个人独立开发"));
    outtextxy(480, 230, _T("目的在于熟悉C语言的实际应用"));
    outtextxy(480, 260, _T("毕竟有很多东西都是第一次接触"));
    outtextxy(480, 290, _T("开发过程中也见识了很多意想不到的问题"));
    outtextxy(480, 320, _T("C语言很不错，有可能以后用c++"));
    outtextxy(480, 350, _T("头文件的使用无疑是最有效的"));

    RECT rect = { 300, 200, 480, 250 };
    const int button_len = 180;
    const int button_high = 50;
    const int button_count = 7;
    int y = rect.top;
    int word_button = -1;
    for (int i = 0; i < button_count; i++)
    {
        RECT buttonRect = { rect.left, y, rect.right, y + button_high };
        const wchar_t* word_button_text = nullptr;//根据按钮的索引 i 来设置对应的按钮文本
        switch (i)
        {
        case 0:
            word_button_text = L"开始游戏";
            break;
        case 1:
            word_button_text = L"结束游戏";
            break;
        case 2:
            word_button_text = L"第二软件";
            break;
        case 3:
            word_button_text = L"游戏说明";
            break;
        case 4:
            word_button_text = L"停止音乐";
            break;
        case 5:
            word_button_text = L"继续音乐";
            break;
        case 6:
            word_button_text = L"切换音乐";
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
        
        定义了三个整型变量 r、g、b，用于表示颜色的 RGB 分量
        通过 (i + 1) * 20 计算红色分量 r 的值，通过 200 - i * 20 计算蓝色分量 b 的值，
        而绿色分量 g 被固定为0。在按钮绘制的过程中，会根据按钮的索引 i 不同，
        计算并设置按钮的线条颜色和填充颜色，来实现每个按钮颜色不同的效果。
        setbkmode(TRANSPARENT);//setbkmode 设置文本背景模式为透明
        settextstyle(35, 0, _T("Arial Bold"));
        settextcolor(RGB(255, 255, 255));
        rectangle(buttonRect.left, buttonRect.top, buttonRect.right, buttonRect.bottom);//solidrectangle 函数绘制一个实心矩形
        drawtext(word_button_text, &buttonRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        // word_button_text 绘制在按钮内部， DT_CENTER | DT_VCENTER | DT_SINGLELINE 参数将文本居中对齐
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
    InputBox(count, max_word, L"请输入计划单词数");
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
    srand((unsigned)time(NULL));//调用 srand 函数以当前时间为种子初始化随机数生成器。
    color = RGB(rand() % 256, rand() % 256, rand() % 256);
    //rand 函数生成三个随机数，分别通过取模运算 % 256 将其限定在 0 到 255 的范围内
    settextcolor(color);
    settextstyle(30, 0, _T("Arial Bold"));
    outtextxy(0, 0, L"congratulations on completing the challenge");
    while (!kbhit())
    {
        Sleep(100); // 适当延时，避免过于频繁的循环
    }
    getch(); // 清除按键缓冲区，获取用户按键
    closegraph(); // 关闭绘图窗口
    returnToMainMenu = true;
}*/
/*wchar_t* copy_word(wchar_t* word)//全文宽字符类型
{
    int length = wcslen(word) + 1;//获取 word 字符串的长度，并加 1，用于存储字符串结尾的空字符。
    wchar_t* copy = (wchar_t*)malloc(length * sizeof(wchar_t));
    if (copy != NULL)
    {
        wcscpy(copy, word);//word 字符串复制到 copy 字符串中，使用 wcscpy 函数完成复制。
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
        bool input_success = InputBox(player_word, max_len, L"请输入单词", L"word game");
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
            MessageBoxW(NULL, L"恭喜你，拼写正确！", L"结果", MB_OK | MB_ICONINFORMATION);
            if (flag)
                num++;
            break;
        }//MB_OK | MB_ICONINFORMATION可以创建一个包含一个"确定"按钮和一个信息图标的消息框
        else
        {
            input_wrong++;
        }
        if (input_wrong >= 2)
        {
            MessageBoxW(NULL, correct_word, L"正确单词", MB_OK | MB_ICONINFORMATION);
            fwprintf(fp, L"%s\n", correct_word);
            break;
        }
        int result = MessageBoxW(NULL, L"拼写错误！是否再次输入？", L"结果", MB_YESNO | MB_ICONQUESTION);
        if (result == IDNO)
        {
            cleardevice();
            IMAGE photo;
            loadimage(&photo, L"photo.jpg");
            putimage(0, 0, &photo);
            MessageBoxW(NULL, correct_word, L"正确单词", MB_OK | MB_ICONINFORMATION);
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
        Sleep(100); // 适当延时，避免过于频繁的循环
    }

    getch(); // 获取用户按键

    closegraph(); // 关闭绘图窗口

    returnToMainMenu = true; // 设置标志变量为true，表示返回主菜单
}*/
/*int compare_scores(const void* a, const void* b)
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
}*/
/*void second_game()
{
    FreeConsole(); //分离原有的控制台
    AllocConsole(); //分配一个新的控制台
    SetConsoleTitleA("second_game");
    RegisterorLoading();
    Menu();
}
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
}*/
/*void Visit()
{
    typedef struct stu {
        char px[100];    // 用来存储单词英文
        wchar_t zw[100];    // 用来存储单词中文
    } dcxx;
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

    while (fscanf(fp, "%s%ls", dcsj[i].px, dcsj[i].zw) != EOF)  // 将单词本内的单词信息存储到结构体数组中
    {
        i++;
    }

    fclose(fp);   // 关闭文件

    printf("单词本信息如下(技术问题，中文用拼音代替）：\n");
    for (int j = 0; j < i; j++)  // 输出用于存储单词信息的结构体的内容
    {
        printf("%s ", dcsj[j].px);
        wprintf(L"%ls", dcsj[j].zw);
        printf("\n");
    }

    system("pause");

}*/
/*void delword()
{
    int ch = 0, count = 0, count1 = 0;  //定义整形数
    char del[500];              //定义字符数组，用来存储用户输入的（需要删除的）内容
    typedef struct stu          //定义结构体
    {
        char px[500];
        char zw[500];
    }dcxx;
    dcxx dcsj[1000];            //定义结构体数组，用来存储单词数据
    int i = 0;
    FILE* fp1, * fp2;               //定义文件指针
    fp1 = fopen("words.txt", "r+");   //两个文件指针分别指向两个文件
    fp2 = fopen("words1.txt", "w+");  //以“w+”的形式打开，若没有此文件则自动创建
    if (!fp1)                    //判断文件是否成功打开
    {
        printf("file error\n");
        exit(1);
    };
    if (!fp2)
    {
        printf("file error\n");
        exit(1);
    };
    fscanf(fp1, "%s%s", dcsj[i].px, dcsj[i].zw);  //将文件中的单词数据读出并存储到结构体数组
    while (!feof(fp1))
    {
        i++;
        fscanf(fp1, "%s%s",dcsj[i].px, dcsj[i].zw);
    }
    fclose(fp1);   //关闭文件
    count = i;        //记录单词总数
    printf("请输入你要删除的单词（中文或英文）：\n");
    scanf("%s", del);  //读取用户需要删除的单词
    for (i = 0; i < count + 1; i++)  //判断文件中有没有用户想要删除的单词
    {
        if (!strcmp(del, dcsj[i].px))  //进行英文比对
        {
            ch = 1;  //改变ch的值，便于之后判断是否找到该单词
            printf("已找到该单词并删除!\n");
            count1 = i;    //记录单词在结构体数组中的位置
            break;       //若找到单词则退出for循环
        }
        if (!strcmp(del, dcsj[i].zw))  //进行中文比对
        {
            ch = 1;
            printf("已找到该单词并删除!\n");
            count1 = i;
            break;
        }
    }
    if (ch == 0) //若找不到该单词，则运行此步骤
    {
        printf("查不到该单词！\n");
        //Menu();
    }
    strcpy(dcsj[count + 1].px, "###");
    strcpy(dcsj[count + 1].zw, "###");
    for (i = count1; i < count; i++)  //从要删除的单词的位置开始，进行for循环，依次将单词“往前移”，覆盖要删除的单词
    {
        dcsj[i] = dcsj[i + 1];
    }
    i = 0;  //对i进行重新赋值
    printf("更新后的单词表为：\n");
    while (count!= 0)   //输出更新后的单词表，并将更新后的单词写入单单词本副本文件中
    {
        fprintf(fp2, "%s %s\n",dcsj[i].px, dcsj[i].zw);
        printf("%s %s\n",dcsj[i].px, dcsj[i].zw);
        count--;
        i++;
    };
    rename("words1.txt", "words.txt");
    rename("words.txt", "words1.txt");
    fclose(fp2); //关闭文件
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
        if (strcmp(search, dcsj[i].px) == 0 || strcmp(search, dcsj[i].zw) == 0&&i<count)  // 进行英文或中文比对
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
    scanf("%ls", dcsj[count].zw);

    fprintf(fp, "%s %s\n", dcsj[count].px, dcsj[count].zw); // 将新单词写入文件

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
    scanf(" %c", &dy);  // 将用户输入的任意字符存储到字符变量里，并执行下一步
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
//初始化按钮属性
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
    settextstyle(35, 0, _T("楷体"));
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
/*void RegisterorLoading()      //注册与登录界面
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
}*/
/*void printInfo()           //界面外形框
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
}*/
/*void playmusic(int n)
{
    //mciSendString("open song2.mp3 alias currentSong", NULL, 0, NULL);
    switch (n)
    {
    case 1:
        // 停止播放当前歌曲
        mciSendString(L"close currentSong", NULL, 0, NULL);
        // 播放第一首歌曲
        mciSendString(L"open music1.mp3 alias currentSong ", NULL, 0, NULL);
        break;
    case 2:
        // 停止播放当前歌曲
        mciSendString(L"close currentSong ", NULL, 0, NULL);
        // 播放第二首歌曲
        mciSendString(L"open music2.mp3 alias currentSong", NULL, 0, NULL);
        break;
    case 3:
        // 停止播放当前歌曲
        mciSendString(L"close currentSong", NULL, 0, NULL);
        // 播放第三首歌曲
        mciSendString(L"open music3.mp3 alias currentSong", NULL, 0, NULL);
        break;
    case 4:
        mciSendString(L"close currentSong", NULL, 0, NULL);
        mciSendString(L"open music4.mp3 alias currentSong", NULL, 0, NULL);
        break;
    case 0:
        mciSendString(L"close currentSong", NULL, 0, NULL);
        mciSendString(L"open welcome.mp3 alias currentSong", NULL, 0, NULL);
        // 可以根据需求继续添加更多的歌曲
    }

    // 播放当前的歌曲
    mciSendString(L"play currentSong repeat", NULL, 0, NULL);
}
void switchmusic()
{
    n = (n + 1) % 5; // 切换歌曲索引
    playmusic(n); // 播放新的歌曲
}*/
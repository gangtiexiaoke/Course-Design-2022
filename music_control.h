#ifndef MUSIC_CONTROL_H
#define MUSIC_CONTROL_H
#include <Windows.h>
#include <mmsystem.h>   
#include<stdio.h>
#include"button.h"
bool returnToMainMenu = false;
int n = 0;
void welcome_music()
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
}
void playmusic(int n)
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
}
#endif // !MUSIC_CONTROL_H

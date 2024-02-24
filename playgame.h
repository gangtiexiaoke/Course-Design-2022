#ifndef PLAYGAME_H
#define PLAYGAME_H
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <wchar.h>
#include <graphics.h>
#include"func.h"
#include"overgame.h"
#define max_len 50
#define max_word 100
void play_word_game()
{

    FILE* fp;
    fp = fopen("rank.txt", "a+");
    //clock_t start_time = clock();
    initgraph(800, 600);
    IMAGE photo;
    loadimage(&photo, L"photo.jpg");
    putimage(0, 0, &photo);
    wchar_t words[max_word][max_len+1] = {0};
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
    //clock_t end_time = clock();
    //double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    student[numrank].wordcount = num;
    strcpy(student[numrank].name, "likeyan");
    fprintf(fp, "%s %d\n", student[numrank].name, student[numrank].wordcount);
    numrank++;
    fclose(fp);
    closegraph();
    goodbye();
    TCHAR buff[100];
    /*_stprintf(buff, _T("%d"), elapsed_time);
    outtextxy(0, 30, L"The game time is ");
    outtextxy(30, 30, buff);*/
}
#endif // !PLAYGAME_H

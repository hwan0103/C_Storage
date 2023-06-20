#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include"gamemenu.h"

#define SCREEN_WIDTH 31
#define SCREEN_HEIGHT 15

void clearBuffer(char* screenBuf, int width, int height) {
    int i = 0;
    int j = 0;
    while (j < height) {
        while (i < width + 1) {
            if (i == width)
                screenBuf[i + (j * (width + 1))] = '\n';
            else {
                if (i == 0 || i == (width - 1) || j == 0 || j == (height - 1))
                    screenBuf[i + (j * (width + 1))] = '#';
                else if (i == 1 || i == (width - 2) || i == 8 || i == (width - 9) || i == 15)
                    screenBuf[i + (j * (width + 1))] = ' ';
                else if (j == (height - 2))
                    screenBuf[i + (j * (width + 1))] = ' ';
                else
                    screenBuf[i + (j * (width + 1))] = ' ';
            }
            i = i + 1;
        }
        i = 0;
        j = j + 1;
    }
    screenBuf[height * (width + 1) - 1] = '\0';
}
int writeStringToBuffer(char* screenBuf, const char* string, int x, int y, int width)
{
    int i = 0;
    while (string[i] != '\0')
    {
        screenBuf[x + i + (y * (width + 1))] = string[i];
        i++;
    }
    return 0;
}

int setTitleToScreenBuffer(char* screenBuf, int width, int height)
{
    system("cls");
    clearBuffer(screenBuf, 30, 12);

    writeStringToBuffer(screenBuf, "Rhythm game", 9, 3, width);
    writeStringToBuffer(screenBuf, "1. game start", 8, 6, width);
    writeStringToBuffer(screenBuf, "2. How to game", 8, 7, width);
    writeStringToBuffer(screenBuf, "3. EXIT", 8, 8, width);

    printf("%s\n", screenBuf);
    return 0;
}

int setGameOverToScreenBuffer(char* screenBuf, int width, int height)
{
    system("cls");
    clearBuffer(screenBuf, 30, 12);
    writeStringToBuffer(screenBuf, "Clear",11,3, width);
    writeStringToBuffer(screenBuf, "You cleared the game",4,6, width);
    writeStringToBuffer(screenBuf, "Once more?",8,9,width);
    writeStringToBuffer(screenBuf, "or Return to lobby", 6, 10, width);
    writeStringToBuffer(screenBuf, "[Y(1), N(2)]",8,11,width);

    printf("%s\n", screenBuf);
    return 0;
}

int setHowtoGameToScreenBuffer(char* screenBuf, int width, int height)
{
    system("cls");
    clearBuffer(screenBuf, 30, 12);

    writeStringToBuffer(screenBuf,"How To Game",8,4, width);
    writeStringToBuffer(screenBuf,"You can play this game",4,7, width);
    writeStringToBuffer(screenBuf,"using the number pad!", 5, 8, width);
    writeStringToBuffer(screenBuf,"press 1 to return to menu", 2, 10, width);

    printf("%s\n", screenBuf);
    return 0;
}

int loading()
{
    clock_t SJTstart;
    SJTstart = clock();

    int i = 0;

    while (i < 4)//.이 나오는 계수 -1
    {
        system("cls");

        COORD pos = { 0,0 };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

        printf("loading");//로딩창

        int j = 0;
        while (j < i)
        {
            printf(".");//로딩할때 보이는 점
            j = j + 1;
        }
        Sleep(100);//시간 조절
        i = i + 1;
    }

    clock_t SJTend;
    SJTend = clock();

    return 0;
}
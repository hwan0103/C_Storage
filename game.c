#include <stdio.h>
#include <stdbool.h>//typedef struct에서 bool isVisivle을 사용하기 위해서는 필요하다.
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include "gamemenu.h"

#define SCREEN_WIDTH 31
#define SCREEN_HEIGHT 15
#define FRAME_RATE 8 // 1초에 대한 프레임 수
#define GAME_DURATION 30 // 게임 지속 시간 (초)
#define KEY_1 '1'
#define KEY_2 '2'
#define KEY_3 '3'
#define KEY_4 '4'

typedef struct {
    int x;
    int y;
    bool isVisible;//필요한 상황에 따라 노트가 보이도록 추가
} Knot;//이 구조체에 이름이다.

int knotSpeed = 1;
bool isKeyPressed(char key);//리듬게임에서 1,2,3,4키 위치에 맞는 키가 눌렸는지 확인한다.

void updateNotes(Knot* knots, int* knotCount, int* score, int frameCounter) {
    static int frameCount = 0;

    if (frameCount % 5 == 0) {
        int x = 0;
        int option = rand() % 4;

        switch (option) {
        case 0:
            x = 2;
            break;
        case 1:
            x = 9;
            break;
        case 2:
            x = 16;
            break;
        case 3:
            x = 23;
            break;
        }

        knots[*knotCount].x = x;
        knots[*knotCount].y = 0;
        knots[*knotCount].isVisible = true;
        (*knotCount)++;
    }

    for (int i = 0; i < *knotCount; i++) {
        knots[i].y += knotSpeed;

        if (knots[i].y >= SCREEN_HEIGHT - 2) {
            if (knots[i].isVisible) {
                knots[i].isVisible = false;
            }
        }
        else if (knots[i].y == 12 && knots[i].isVisible) {//리듬게임에서 1번에서'OOOO'가 내려오는데 2번을 눌렀을때 점수가 올라가면 안되니, 다른 키를 눌렀을때 isVisible 적용
            // 사용자 입력에 따라 노트를 맞췄을 때 점수 증가
            if (knots[i].x == 2 && isKeyPressed(KEY_1)) {
                knots[i].isVisible = false;
                (*score) += 100; // 노트를 맞춘 경우 점수 증가
            }
            else if (knots[i].x == 9 && isKeyPressed(KEY_2)) {
                knots[i].isVisible = false;
                (*score) += 100; // 노트를 맞춘 경우 점수 증가
            }
            else if (knots[i].x == 16 && isKeyPressed(KEY_3)) {
                knots[i].isVisible = false;
                (*score) += 100; // 노트를 맞춘 경우 점수 증가
            }
            else if (knots[i].x == 23 && isKeyPressed(KEY_4)) {
                knots[i].isVisible = false;
                (*score) += 100; // 노트를 맞춘 경우 점수 증가
            }
        }
    }

    frameCount++;
}

//게임 화면
void clearGameBuffer(char* screenBuf, int width, int height) {
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
                    screenBuf[i + (j * (width + 1))] = '|';
                else if (j == (height - 2))
                    screenBuf[i + (j * (width + 1))] = '=';
                else
                    screenBuf[i + (j * (width + 1))] = ' ';
            }
            i++;
        }
        i = 0;
        j++;
    }
    screenBuf[height * (width + 1) - 1] = '\0';
}

void drawScreen(Knot* knots, int knotCount, int score) {
    char screenBuf[SCREEN_WIDTH * (SCREEN_HEIGHT + 1)];

    clearGameBuffer(screenBuf, SCREEN_WIDTH, SCREEN_HEIGHT);

    // 점수 출력
    char scoreText[19];
    sprintf(scoreText, "[ Score: %d ]", score);
    int scoreX = (SCREEN_WIDTH - strlen(scoreText)) / 2;
    int scoreY = SCREEN_HEIGHT - 1;
    for (int i = 0; i < strlen(scoreText); i++) {
        screenBuf[scoreX + i + 1 + (scoreY * (SCREEN_WIDTH + 1))] = scoreText[i];
    }

    // 노트 출력
    for (int i = 0; i < knotCount; i++) {
        int x = knots[i].x;
        int y = knots[i].y;

        if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT && knots[i].isVisible) {
            // 다중 문자열 복사
            char knotString[] = "0000";
            int knotStringLength = sizeof(knotString) - 1; // null 종료 문자 제외

            // screenBuf에 문자열 복사
            for (int j = 0; j < knotStringLength; j++) {
                screenBuf[x + 1 + ((y + 1) * (SCREEN_WIDTH + 1)) + j] = knotString[j];
            }
        }
    }

    system("cls");
    printf("%s", screenBuf);
}

bool isKeyPressed(char key) {
    return GetAsyncKeyState(key) & 0x8000;
}

int game() {
    Knot knots[100];
    int knotCount = 0;
    int frameCounter = 0;
    int score = 0;
    srand((unsigned int)time(NULL));

    while (true) {
        for (int i = 0; i < knotCount; i++) {
            if (knots[i].y >= SCREEN_HEIGHT - 1) {
                knots[i].x = -1;
                knots[i].y = -1;
                knots[i].isVisible = false;
            }
        }

        updateNotes(knots, &knotCount, &score, frameCounter);
        drawScreen(knots, knotCount, score);
        frameCounter++;

        Sleep(1000 / FRAME_RATE);

        if (frameCounter >= FRAME_RATE * GAME_DURATION) { // 1분에 해당하는 프레임 수
            system("pause");
            break;
        }
    }
    
}

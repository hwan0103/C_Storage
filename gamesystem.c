#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include"gamemenu.h"

#define SCREEN_WIDTH 31
#define SCREEN_HEIGHT 15

int main()
{
	int input = 0;
	char screenBuf[500];
	setTitleToScreenBuffer(screenBuf, 30, 12);
	scanf("%d", &input);
	while (setTitleToScreenBuffer) {
		if (input == 1) {
			loading();
			game();
			setGameOverToScreenBuffer(screenBuf, 30, 12);
			scanf("%d", &input);
			if (input == 1) {
				continue;
			}else if (input == 2) {
				setTitleToScreenBuffer(screenBuf, 30, 12);
				scanf("%d", &input);
			}
		}
		else if (input == 2) {
			setHowtoGameToScreenBuffer(screenBuf, 30, 12);
			scanf("%d", &input);
			if (input == 1) {
				setTitleToScreenBuffer(screenBuf, 30, 12);
				scanf("%d", &input);
			}
				}
		else {
			break;
		}
	}
		return 0;
}

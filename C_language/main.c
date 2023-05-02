#include <stdio.h>

int print_title_screen()
{
	printf("###############################\n");
	printf("##                           ##\n");
	printf("##         Dino Run          ##\n");
	printf("##          V.0.1            ##\n");
	printf("##                           ##\n");
	printf("##  1. Start Game            ##\n");
	printf("##  2. How to Play           ##\n");
	printf("##  3. Exit                  ##\n");
	printf("##                           ##\n");
	printf("###############################\n");

	return 0;
}

int print_how_to_play_screen()
{
	printf("###############################\n");
	printf("##                           ##\n");
	printf("##      To Avoid Enemy       ##\n");
	printf("##                           ##\n");
	printf("##  Press Space Bar To Jump  ##\n");
	printf("##  Return to menu(1.y/2.n)  ##\n");
	printf("##                           ##\n");
	printf("##                           ##\n");
        printf("###############################\n");

	return 0;
}

int main(){
	int menu = 1;
	int re = 0;
	int a = 0;
	while(menu){
		print_title_screen();
		printf("input>");
		scanf("%d", &re);
		if(re == 1){
		system("mkdir mumu_babo");
			printf("The program is not ready to ren yet.");
			continue;
		}
		else if(re == 2){
			while(re){
				print_how_to_play_screen();
				printf("input>");
				scanf("%d", &a);
				if(a == 1){
					break;
				}
				else if(a == 2){
					continue;
				}
		}
		}
		else if(re == 3){
			break;
		}
		

		
	}
}
	

#include <stdio.h>

int print_title_screen()
{
	int num;
	
	printf("############################################");
	printf("##                                        ##");
	printf("##               Dino Run                 ##");
	printf("##                 v.0.1                  ##");
	printf("##            1. Start Game               ##");
	printf("##            2. How to Play              ##");
	printf("##            3. Exit                     ##");
	printf("##                                        ##");
	printf("############################################");
	printf("Please enter the number of the item you wish to select :");
	scanf("%d, &num");
	return 0;
}



int How_to_play_this_game()
{
	printf("############################################");
	printf("##                                        ##");
	printf("##       2. How to Play this Game         ##");
	printf("##                                        ##");
	printf("##            To Avoid Enemy              ##");
	printf("##                                        ##");
	printf("##         Press Space Bar To Jump        ##");
	printf("##                                        ##");
	printf("############################################");
	
}
int main()
{
	print_title_screen(); // print the title screen




	return 0;
}


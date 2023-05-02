#include <stdio.h>

int main()
{
	int game_state = 0;

	scanf("%d",&game_state);
	if(game_state)
	{
		printf("나는 연애를 %d번 해본 정상인이다.",game_state);
	}
	else
	{
		printf("ㅋ");
	}		
	return 0;
}

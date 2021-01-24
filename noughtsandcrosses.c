#include <stdio.h>
#include <stdlib.h>

void showBoard(char *board)
{
	printf("\n");
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if(j % 2 == 1 && i % 2 == 0)
				printf("|");
			else if(j % 2 == 0 && i % 2 == 0)
				printf("%c", *board++);
			else
				printf("-");
		}
		printf("\n");
	}
}

char checkWin(char *board)
{
	char temp = ' ';

	//horizontal
	if(board[0] == board[1] && board[1] == board[2])
		temp = board[0];
	else if(board[3] == board[4] && board[4] == board[5])
		temp = board[3];
	else if(board[6] == board[7] && board[7] == board[8])
		temp = board[6];
	//vertical
	else if(board[0] == board[3] && board[3] == board[6])
		temp = board[0];
	else if(board[1] == board[4] && board[4] == board[7])
		temp = board[1];
	else if(board[2] == board[5] && board[5] == board[8])
		temp = board[2];
	//other
	else if(board[0] == board[4] && board[4] == board[8])
		temp = board[0];
	else if(board[2] == board[4] && board[4] == board[6])
		temp = board[2];

	//check for empty spaces
	if(temp == ' ')
		for(int i = 0; i < 10; i++){
			if(i < 9 && board[i] == ' ')
				break;
			else if(i == 10)
				return '-';
		}

	return temp;
}

void playerMove(char *board)
{
	int n;
	while(1){
		printf("> ");
		scanf("%d", &n);
		if(board[--n] == ' '){
			board += n;
			*board = 'X';
			break;
		}
	}
}

void computerMove(char *board)
{
	int space;
	while(1){
		space = rand()%9;
		if (board[space] == ' '){
			board[space] = 'O';
			break;
		}
	}
}

int main()
{
	srand(time(NULL));

	printf("spaces on board are numbered like this:\n");
	showBoard("123456789");

	char board[] = "         ";
	char gameState = ' ';

	while(1){
		showBoard(board);
		playerMove(board);
		gameState = checkWin(board);
		if(gameState != ' ')
			break;
		computerMove(board);
		gameState = checkWin(board);
		if(gameState != ' ')
			break;
	}

	if(gameState == 'X')
		printf("\nPLAYER WON");
	else if(gameState == 'O')
		printf("\nCOMPUTER WON");
	else if(gameState == '-')
		printf("\nIT WAS A TIE");
	else
		printf("\n%c", gameState);
	showBoard(board);
}

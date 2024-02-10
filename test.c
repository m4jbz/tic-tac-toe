#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

// Numero de posiciones
#define N 9

// Declaración de las funciones
char *boardMaker();
char *newBoardMaker(int randomNum, char *board, int position);
void printBoard(char *board);
void freeArray(char *board);
bool youWin(char *board);
bool pcWin(char *board);
int validPst(int validPositions);
void clean();

// Función main
int main() 
{
	srand(time(0));

	char *board = boardMaker();
	int *allPositions = calloc(9, sizeof(int));
	int position, randomNum;
	int quitGame = 0, i = 0, j = 0;

	clean();
	printf("%*s%s\n", 67, "", "Juego del gato 🐈\n");
	printBoard(board);

	while (1)
	{
		printf("Posición []: \n");
		scanf("%d", &position);

		if (position > N || position < 1 || !(board[position-1] == ' '))
		{
			printf("Posición no valida. Intenta de nuevo.\n");
		}
		else 
		{
			allPositions[i] = position-1;
			i++;

			if (i < 9)
			{
				do {
					randomNum = rand() % 9;
					j = 0;
					while (j < 9)
					{
						if (randomNum == allPositions[j])
							break;
						j++;
					}
				} while (randomNum == allPositions[j]);
				allPositions[i] = randomNum;
			}

			i++;
			board = newBoardMaker(randomNum, board, position);
			clean();
			printf("%*s%s\n", 67, "", "Juego del gato 🐈\n");
			printBoard(board);
		}

		if (youWin(board))
		{
			printf("Ganaste!\n");
			break;
		}
		if (pcWin(board))
		{
			printf("La PC Ganó!\n");
			break;
		}
		if (!(youWin(board)) && !(pcWin(board)) && i == 10)
		{
			printf("Es un empate!\n");
			break;
		}
	}

	freeArray(board);
	free(allPositions);
	
	return 0;
}

// Función para hacer un nuevo tablero modificado
char *newBoardMaker(int randomNum, char *board, int position)
{
	board[randomNum] = 'X';
	board[position-1] = 'O';

	return board;
}

// A partir de aca todo funciona correctamente
// Función que hace el primer tablero
char *boardMaker()
{
	char *board = malloc(N * sizeof(char));

	for (int i = 0; i < N; i++)
	{
		board[i] = ' ';
	}

	return board;
}

// Función que imprime el tablero
void printBoard(char *board) 
{
	int k = 0;
	printf("%*s|---|---|---|\n", 69, "");
	for (int i = 0; i < 3; i++)
	{
		printf("%*s|", 69, "");
		for (int j = 0; j < 3; j++)
		{
			printf(" %c |", board[k]);
			k++;
		}
		printf("\n");
		printf("%*s|---|---|---|\n", 69, "");
	}
}

bool youWin(char *board)
{
	if (board[0] == 'O' && board[1] == 'O' && board[2] == 'O' ||
			board[3] == 'O' && board[4] == 'O' && board[5] == 'O' ||
			board[6] == 'O' && board[7] == 'O' && board[8] == 'O')
	{
		return true;
	}
	else if (board[0] == 'O' && board[3] == 'O' && board[6] == 'O' ||
					 board[1] == 'O' && board[4] == 'O' && board[7] == 'O' ||
					 board[2] == 'O' && board[5] == 'O' && board[8] == 'O')
	{
		return true;
	}
	else if (board[0] == 'O' && board[4] == 'O' && board[8] == 'O' ||
					 board[2] == 'O' && board[4] == 'O' && board[6] == 'O')
	{
		return true;
	}
	else {
		return false;
	}
}

bool pcWin(char *board)
{
	if (board[0] == 'X' && board[1] == 'X' && board[2] == 'X' ||
			board[3] == 'X' && board[4] == 'X' && board[5] == 'X' ||
			board[6] == 'X' && board[7] == 'X' && board[8] == 'X')
	{
		return true;
	}
	else if (board[0] == 'X' && board[3] == 'X' && board[6] == 'X' ||
					 board[1] == 'X' && board[4] == 'X' && board[7] == 'X' ||
					 board[2] == 'X' && board[5] == 'X' && board[8] == 'X')
	{
		return true;
	}
	else if (board[0] == 'X' && board[4] == 'X' && board[8] == 'X' ||
					 board[2] == 'X' && board[4] == 'X' && board[6] == 'x')
	{
		return true;
	}
	else {
		return false;
	}
}

// Función para liberar memoria
void freeArray(char *board)
{
	free(board);
}

void clean()
{
	system("clear");
}

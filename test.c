#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

// Numero de posiciones
#define N 9

// Declaración de las funciones
char *boardMaker();
char *newBoardMaker(int arrRandom, char *board, int position);
void printBoard(char *board);
void freeArray(char *board);
bool youWin(char *board);
bool pcWin(char *board);
int validPst(int validPositions);
void clean();

// Función main
int main() 
{
	int position;
	char *board = boardMaker();
	int quitGame = 0;

	clean();
	printf("%*s%s\n", 67, "", "Juego del gato 🐈\n");
	printBoard(board);

	while (1)
	{
		printf("Posición []: \n");
		scanf("%d", &position);

		if (position > N || position < 1 || !(board[position-1] == ' ')) // Este if si funciona
		{
			printf("Posición no valida. Intenta de nuevo.\n");
		}
		else 
		{
			board = newBoardMaker(validPst(position-1), board, position);
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
	}

	freeArray(board);
	
	return 0;
}

// Función para saber las posiciones validas
int validPst(int validPositions)
{
	srand(time(0));
	int numRand;
	int matched = 0; 

	return numRand;
}

// Función para hacer un nuevo tablero modificado
char *newBoardMaker(int arrRandom, char *board, int position)
{

	printf("PC: %d, \n", arrRandom);
	printf("User: %d, \n", position-1);

	if (board[arrRandom] == 'X' || board[arrRandom] == 'O')
	{
		int o1 = (arrRandom > 1) ? -1 : 1;

		board[arrRandom+o1] = 'X';
	}
	board[arrRandom] = 'X';
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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

// Numero de filas y columnas
#define N 3

// Declaración de las funciones
char **boardMaker();
char **newBoardMaker(char **board, int row, int file);
void printBoard(char **board);
void freeMatrix(char **board);
bool youWin(char **board);
bool pcWin(char **board);
bool isValid(int row, int file, char **board);
void clean();

// Función main
int main() 
{
	int row, file;
	char **board = boardMaker();
	int quitGame = 0;

	clean();
	printf("%*s%s\n", 67, "", "Juego del gato 🐈\n");
	printBoard(board);

	while (1)
	{
		printf("Posición [][]: \n");
		scanf("%d", &row);
		scanf("%d", &file);

		if (row > N || file > N || row < 1 || file < 1 || !isValid(row, file, board))
		{
			printf("Posición no valida. Intenta de nuevo.\n");
		}
		else 
		{
			do {
				if (isValid(row, file, board))
				{
					board = newBoardMaker(board, row, file);
					printf("%*s%s\n", 67, "", "Juego del gato 🐈\n");
					printBoard(board);
					break;
				}
			} while (isValid(row, file, board));
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

	freeMatrix(board);
	
	return 0;
}


// Función que hace el primer tablero
char **boardMaker()
{
	char **board = malloc(N * sizeof(char *));

	for (int i = 0; i < N; i++)
	{
		board[i] = malloc(N * sizeof(char));

		for (int j = 0; j < N; j++)
		{
			board[i][j] = ' ';
		}
	}

	return board;
}

// Función para hacer un nuevo tablero modificado
char **newBoardMaker(char **board, int row, int file)
{
	srand(time(0));

	int *arrRandom = malloc(2 * sizeof(int));
	arrRandom[0] = rand() % 3;
	arrRandom[1] = rand() % 3;

	printf("PC: %d, %d\n", arrRandom[0], arrRandom[1]);
	printf("User: %d, %d\n", row-1, file-1);

	if (arrRandom[0] == (row-1) && arrRandom[1] == (file-1))
	{
		int offset1 = (arrRandom[0] > 1) ? -1 : 1;
		int offset2 = (arrRandom[1] > 1) ? -1 : 1;

		board[arrRandom[0]+offset1][arrRandom[1]+offset2] = 'X';
	} 
	else if (board[arrRandom[0]][arrRandom[1]] == 'O')
	{
		int offset1 = (arrRandom[0] > 1) ? -1 : 1;
		int offset2 = (arrRandom[1] > 1) ? -1 : 1;

		board[arrRandom[0]+offset1][arrRandom[1]+offset2] = 'X';
	} 
	else if (board[arrRandom[0]][arrRandom[1]] == 'X')
	{
		int offset1 = (arrRandom[0] > 1) ? -1 : 1;
		int offset2 = (arrRandom[1] > 1) ? -1 : 1;

		board[arrRandom[0]+offset1][arrRandom[1]+offset2] = 'X';
	} 
	else 
	{
		board[arrRandom[0]][arrRandom[1]] = 'X';
	} 

	board[row-1][file-1] = 'O';

	free(arrRandom);

	return board;
}

bool isValid(int row, int file, char **board)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[row-1][file-1] == ' ')
				return true;
		}
	}
	return true;
}

// Función que imprime el tablero
void printBoard(char **board) 
{
	printf("%*s|---|---|---|\n", 69, "");
	for (int i = 0; i < N; i++)
	{
		printf("%*s|", 69, "");
		for (int j = 0; j < N; j++)
		{
			printf(" %c |", board[i][j]);
		}
		printf("\n");
		printf("%*s|---|---|---|\n", 69, "");
	}
}

bool youWin(char **board)
{
	if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O' ||
			board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O' ||
			board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
	{
		return true;
	}
	else if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O' ||
					 board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O' ||
					 board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
	{
		return true;
	}
	else if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O' ||
					 board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
	{
		return true;
	}
	else {
		return false;
	}
}

bool pcWin(char **board)
{
	if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X' ||
			board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X' ||
			board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
	{
		return true;
	}
	else if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X' ||
					 board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X' ||
					 board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
	{
		return true;
	}
	else if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X' ||
					 board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
	{
		return true;
	}
	else {
		return false;
	}
}

// Función para liberar memoria
void freeMatrix(char **board)
{
	for (int i = 0; i < N; i++)
	{
		free(board[i]);
	}
	free(board);
}

void clean()
{
	system("clear");
}

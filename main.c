#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Numero de posiciones
#define N 9

// Declaración de las funciones
char *boardMaker();
char *newBoardMaker(int randomNum, char *board, int position);
void printBoard(char *board);
void clean();
bool youWin(char *board);
bool pcWin(char *board);

// Función main
int main() 
{
	srand(time(0));

	char *board = boardMaker();
	int *allPositions = calloc(9, sizeof(int)); // Array para guardar todas las posiciones
	int position, randomNum;
	int i = 0, j = 0;

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
			board = newBoardMaker(randomNum, board, position);

			if (i < 9 && !youWin(board)) 
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

	free(board);
	free(allPositions);
	
	return 0;
}

// Función que hace el primer tablero
char *boardMaker()
{
	char *board = malloc(N * sizeof(char));

	for (int i = 0; i < N; i++)
	{
		board[i] = ' ';
	}

	return board;
	free(board);
}

// Función para hacer un nuevo tablero modificado
char *newBoardMaker(int randomNum, char *board, int position)
{
	board[randomNum] = 'X';
	board[position-1] = 'O';

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

// Función para limpiar la pantalla
void clean()
{
	system("clear");
}

// Funciones para saber si gane o ganó la PC
bool youWin(char *board)
{
	for (int i = 0; i < 3; ++i) {
		if ((board[i] == 'O' && board[i + 3] == 'O' && board[i + 6] == 'O') ||
			(board[i * 3] == 'O' && board[i * 3 + 1] == 'O' && board[i * 3 + 2] == 'O'))
			return true;
	}
	if (board[0] == 'O' && board[4] == 'O' && board[8] == 'O' ||
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
	for (int i = 0; i < 3; ++i) {
		if ((board[i] == 'X' && board[i + 3] == 'X' && board[i + 6] == 'X') ||
			(board[i * 3] == 'X' && board[i * 3 + 1] == 'X' && board[i * 3 + 2] == 'X'))
			return true;
	}
	if (board[0] == 'X' && board[4] == 'X' && board[8] == 'X' ||
					 board[2] == 'X' && board[4] == 'X' && board[6] == 'X')
	{
		return true;
	}
	else {
		return false;
	}
}

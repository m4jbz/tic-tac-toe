#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Numero de posiciones
#define N 9

// Declaración de las funciones
int version2();
char *boardMaker2();
char *newBoardMaker2(char *board, int position, int counter);
void playerTurn(char *board, int player, int counter);
void printBoard2(char *board);
void clean2();
bool checkWin2(char *board, char player);

// Función main
int version2() 
{
	char *board = boardMaker2();
	int *allPositions = calloc(N, sizeof(int)); // Array para guardar todas las posiciones
	int position1, position2;
	int counter = 0;
	char choice;

	clean2();

	printf("%*s%s\n", 67, "", "Juego del gato 🐈\n");
	printBoard2(board);

	while (1)
	{
		counter++;
		if (counter % 2 == 1) playerTurn(board, 1, counter);
		if (counter % 2 == 0) playerTurn(board, 2, counter);

		if (checkWin2(board, 'O'))
		{
			printf("Jugador 1 (O) ganó!\n");
			break;
		}
		else if (checkWin2(board, 'X'))
		{
			printf("Jugador 2 (X) ganó!\n");
			break;
		}
		else if (counter == N)
		{
			printf("Es un empate!\n");
			break;
		}
	}

	// Liberar memoria
	free(board);
	free(allPositions);
	
	return 0;
}

// Función que hace el primer tablero
char *boardMaker2()
{
	char *board = malloc(N * sizeof(char));

	for (int i = 0; i < N; i++)
	{
		board[i] = ' ';
	}

	return board;
	// Liberar memoria
	free(board);
}

// Turno del jugador n
void playerTurn(char *board, int player, int counter)
{
	int position;

	printf("Jugador %d (%c) []: \n", player, (counter % 2 == 1) ? 'O' : 'X');
	scanf("%d", &position);

	if (position > N || position < 1 || board[position-1] != ' ')
	{
		printf("Posición no valida. Intenta de nuevo.\n");
	}
	else
	{
		clean2();
		printf("%*s%s\n", 67, "", "Juego del gato 🐈\n");
		newBoardMaker2(board, position, counter);
		printBoard2(board);
	}
}

// Función para hacer un nuevo tablero modificado
char *newBoardMaker2(char *board, int position, int counter)
{
	if (counter % 2 == 1) board[position-1] = 'O';
	if (counter % 2 == 0) board[position-1] = 'X';

	return board;
}

// Función que imprime el tablero
void printBoard2(char *board) 
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
void clean2()
{
	system("clear");
}


// Funciones para saber si gane o ganó la PC
bool checkWin2(char *board, char player)
{
	// Ciclo para saber si alguno de los dos gano de forma vertical u horizontal
	for (int i = 0; i < 3; ++i) {
		if ((board[i] == player && board[i + 3] == player && board[i + 6] == player) ||
			(board[i * 3] == player && board[i * 3 + 1] == player && board[i * 3 + 2] == player))
			return true;
	}

	// Condicional para saber si alguno de los dos gano de forma diagonal 
	if (board[0] == player && board[4] == player && board[8] == player ||
					 board[2] == player && board[4] == player && board[6] == player)
		return true;

	return false;
}

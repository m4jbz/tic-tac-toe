#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <verto.h>

// Numero de posiciones
#define N 9

// Declaración de las funciones
int version1();
char *boardMaker();
char *newBoardMaker(int randomNum, char *board, int position);
void printBoard(char *board);
void clean();
bool checkWin(char *board, char player);

// Función main
int version1() 
{
	srand(time(0));

	char *board = boardMaker();
	int *allPositions = calloc(N, sizeof(int)); // Array para guardar todas las posiciones
	int position, randomNum;
	int i = 0, j = 0;
	char choice;

	clean();

	printf("¿Quieres empezar con el primer movimiento? (s/n): ");
	scanf(" %c", &choice);

	if (choice == 'n' || choice == 'N') {
		randomNum = rand() % N;
		board[randomNum] = 'X';
		i++;
	}

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

			if (i != 1) board = newBoardMaker(randomNum, board, position);

			if (i < N && !checkWin(board, 'O')) 
			{
				do { // Ciclo para sacar un numero random que no sea igual a alguna posicion anterior
					randomNum = rand() % N;
					j = 0;
					while (j < N)
					{
						if (randomNum == allPositions[j])
							break;
						j++;
					}
				} while (randomNum == allPositions[j]);
				allPositions[i] = randomNum;
				i++;
			}

			board = newBoardMaker(randomNum, board, position);
			clean();
			printf("%*s%s\n", 67, "", "Juego del gato 🐈\n");
			printBoard(board);
		}

		// Condicionales para saber como quedo el juego
		if (checkWin(board, 'O'))
		{
			printf("Ganaste!\n");
			break;
		}
		if (checkWin(board, 'X'))
		{
			printf("La PC Ganó!\n");
			break;
		}
		if (i == N)
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
char *boardMaker()
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
bool checkWin(char *board, char player)
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

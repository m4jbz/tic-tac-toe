/*
 * Author: Marco Aurelio Juarez Baltazar
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "version1.h"
#include "version2.h"

int main()
{
	short option = 0;

	do {
		printf("1) Jugar contra la PC\n2) Jugador vs Jugador\n: ");
		scanf("%hd", &option);

		switch (option)
		{
			case 1:
				version1();
				break;
			case 2:
				version2();
				break;
			default:
				printf("Opcion invalida.\n");
				break;
		}
	} while (option != 1 && option != 2);

	return 0;
}

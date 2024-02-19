#ifndef VERSION2_H
#define VERSION2_H

int version2();
char *boardMaker2();
char *newBoardMaker2(char *board, int position, int counter);
void playerTurn(char *board, int player, int counter);
void printBoard2(char *board);
void clean2();
bool checkWin2(char *board, char player);

#endif 

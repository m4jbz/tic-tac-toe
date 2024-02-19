#ifndef VERSION1_H
#define VERSION1_H

int version1();
char *boardMaker();
char *newBoardMaker(int randomNum, char *board, int position);
void printBoard(char *board);
void clean();
bool checkWin(char *board, char player);

#endif 

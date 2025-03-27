/**
 * Prototypes and Macros used for board.c
 * @author Lillian Thereault
 * @version Feb 2025
 */

#ifndef BOARD_H
#define BOARD_H
#define BOARD_LENGTH 3
#define PLAYER 'X'
#define COMPUTER 'O'
#define TRUE 1
#define FALSE 0

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

#endif

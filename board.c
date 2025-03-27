/**
 * Game of tic-tac-toe between user and computer.
 * @author Lillian Thereault
 * @version Feb 2025
 */

#include <stdio.h>
#include <stdlib.h>
#include "./board.h"

//Game board
char board[BOARD_LENGTH][BOARD_LENGTH];

/**
 * Runs game setting all variable to their default values
 * @return int 0
 */
int main () {
    char winner = ' ';
    resetBoard();
    while(winner == ' ' && checkFreeSpaces() != 0) {
        playerMove();
        winner = checkWinner();
        computerMove();
        winner = checkWinner();
    }
    printBoard();
    printWinner(winner);
    return 0;
}

/**
 * Empties the board by setting 2D array to a space char
 */
void resetBoard() {
    for(int i = 0; i < BOARD_LENGTH; i++){
        for(int j = 0; j < BOARD_LENGTH; j++) {
            board[i][j] = ' ';
        }
        
    }
}

/**
 * Prints the game board in a visual manner to the console
 */
void printBoard() {
    //sets top row
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    //sets middle row
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    //sets botton row
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

/**
 * Searches through the game board for any empty spaces, decrements the
 * local varible when a empty space is not found
 * @return number of empty spaces in the game board
 */
int checkFreeSpaces() {
    int freeSpaces = 9;
    for(int i = 0; i < BOARD_LENGTH; i++) {
        for(int j = 0; j < BOARD_LENGTH; j++) {
            if(board[i][j] != ' ') {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}

/**
 * Calls the player to make their move, asking them to input a row and column
 * to place their move in as long as it's currently empty
 */
void playerMove() {
    printBoard();
    int x;
    int y;
    while(board[x][y] != ' ') {
        int condition = FALSE;
        //insure row is a number between 1 and 3
        printf("Enter a row from numbers 1-3: ");
        while(!condition) {
            scanf("%d", &x);
            if (x >= 1 && x <= 3) {
                condition = TRUE;
            } else {
                printf("Invalid index. Please enter a row from numbers 1-3: ");
            }
        }
        //decrement to match arr index
        x--;
        condition = FALSE;
        //insure column is a number between 1 and 3
        printf("\nEnter a column from numbers 1-3: ");
        while(!condition) {
            scanf("%d", &y);
            if (y >= 1 && y <= 3) {
                condition = TRUE;
            } else {
                printf("Invalid index. Please enter a row from numbers 1-3: ");
            }
        }
        //decrement to match arr index
        y--;
        if(board[x][y] != ' ') {
            printf("INVAILD MOVE!");
        } else {
            board[x][y] = PLAYER;
            break;
    }
    }   
}

/**
 * Calls the computers move, setting a random row and column to computer as
 * long as space is empty
 */
void computerMove() {
    int x = rand() %3;
    int y = rand() %3;
    if(checkFreeSpaces() > 0) {
        while(board[x][y] != ' ') {
            x = rand() %3;
            y = rand() %3;
        }
        board[x][y] = COMPUTER;
    } else {
        //draw
        printWinner(' ');
    }
}

/**
 * Searches the game board to see if computer or player is winning and returns
 * the winning array value, if no winner is found a space char is returned
 * @return winning player or space char if no winner found
 */
char checkWinner() {
    //check each row
    for(int i = 0; i < BOARD_LENGTH; i++) {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return board[i][0];
        }
    }
    //check columns
    for(int i = 0; i < BOARD_LENGTH; i++) {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return board[0][i];
        }
    }
    //check diangles
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
       return board[0][0]; 
    }
    if(board[2][0] == board[1][1] && board[2][0] == board[0][2]) {
       return board[2][0]; 
    }
    return ' '; 
}

/**
 * Prints the winner to the console
 * @param winner char associated with the winner
 */
void printWinner(char winner) {
    if(winner == PLAYER) {
        printf("YOU WIN!");
    } else if(winner == COMPUTER) {
        printf("COMPUTER WINS!");
    } else {
        printf("IT'S A DRAW!");
    }
}
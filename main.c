#include <stdbool.h>

#include <stdio.h>

#include <stdlib.h>

#include "disksAndPlayers.h"

player player1;

player player2;

int main()
{
    //Declaration of the board of type disk
    disk board[SIZE][SIZE];
    
    //Calling each function one by one which initialise teh board, perform the game logic and print the result
    initializePlayers();

    initializeBoard(board);

    
    
    gamelogic(board, player1, player2);// a method that implements the game logic

}

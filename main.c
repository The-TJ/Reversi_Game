#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "disksAndPlayers.h"
player player1;
player player2;
int main()
{
    // Variables declaration


    disk board[SIZE][SIZE];

    initializePlayers();

    initializeBoard(board);

    printBoard(board);
    
    gamelogic(board, player1, player2);//invoke a method that implements the game logic


}

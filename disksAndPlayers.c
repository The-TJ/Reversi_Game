#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "disksAndPlayers.h"



void initializePlayers(){
    int nameSize;
    // Insert player 1
    printf("Player 1 please insert your name:   \n");
    fgets(player1.name, 20, stdin);
    nameSize = strlen(player1.name);
    player1.name[nameSize -1] = '\0';

    // Assign colours and points to player 1
    player1.type = BLACK;
    player1.points = 2;

    // Insert player 2
    printf("Player 2 please insert your name:   \n");
    fgets(player2.name, 20, stdin);
    nameSize = strlen(player2.name);
    player2.name[nameSize -1] = '\0';

    // Assign colours and points to player 2
    player2.type = WHITE;
    player2.points = 2;

    printf("%s your disks are symbolised by 1\n", player1.name); //telling the players what number represents their disks
    printf("%s your disks are symbolised by 0\n", player2.name);
}


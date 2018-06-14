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

void initializeBoard(disk board [SIZE][SIZE]){
 int i, j;
 //board initialization
    for(i=0; i< SIZE; i++){
        for(j=0;j<SIZE; j++){
            if(i==3){
                if(j==3)
                    board[i][j].type = WHITE;
                else{
                    if(j==4)
                        board[i][j].type = BLACK;
                    else
                        board[i][j].type = NONE;
                    }
                }
            else {
                if(i==4){
                    if(j == 3)
                        board[i][j].type = BLACK;
                    else {
                        if(j == 4)
                        board[i][j].type = WHITE;
                        else
                            board[i][j].type = NONE;
                        }
                    }
                else
                    board[i][j].type = NONE;
            }
            board[i][j].pos.row = i;
            board[i][j].pos.col = j;

            }
        }
    }
void printBoard(disk board[SIZE][SIZE]){
    int i,j;
    j = 0;

    printf("\n    ");
    for(i=0; i< SIZE; i++){
        printf("%d   ",i+1);
    }
    for(i=0; i< SIZE; i++){
        printf("\n%d | ", i+1);
        for(j=0;j<SIZE; j++){
            switch(board[i][j].type){
                case BLACK:
                    printf("1 | ");
                    break;
                case WHITE:
                    printf("0 | ");
                    break;
                case NONE:
                    printf("x | ");
                    break;
                default:
                    break;
            }
        }
    }
    printf("\n");
}
void gamelogic(disk board[SIZE][SIZE], player player1, player player2)
{
	//This function iterates till all the positions in the board are taken or if any player can't make a move
    int checker = 4;
    int chance = 1;
    while(checker<64 && chance==1)
    {
        if(checker%2==0)
        {
            possiblemoves(board, player1);  //Calling the function with the board and the current players struct as parameters
            checker+=1;
        }

else
        {
            possiblemoves(board, player2);  //Calling the function with the board and the current players struct as parameters
            checker+=1;
        }
    }
    if(checker>=64)
    {
        results();    //When the board is full, display the result
    }
}
void possiblemoves(disk board[SIZE][SIZE], player Cplayer)

{
    int num=0;
    int arr[20][4];
    if(Cplayer.type==BLACK)
    {
        for(int i=0; i<SIZE;i++)
        {
            for(int j=0; j<SIZE;j++)
            {
                switch(board[i][j].type)
                {
                    case WHITE: // When we find a rival disk, a series of if statements determine if any of its neighbouring element is a possible move 

                        if(i-1>=0 && j-1>=0)       //Neighbpur position one row above and one coloum to the left
			 {
                            if(board[i-1][j-1].type==NONE)
                            {
                                int check=1;
                                int a=i+1;
                                int b=j+1;
                                while(a<SIZE && b<SIZE && check==1)
                                {
                                    if(board[a][b].type==BLACK)
                                    {
                                    	if((i-1>=0 && i-1<8) && (j-1>=0 && j-1<8)) //limiting the possible moves to between 1 and 8 so we don't get options outside this range
                                    	{
                                        	arr[num][0] = i-1;
                                        	arr[num][1] = j-1;
                                        	arr[num][2] = i;
                                        	arr[num][3] = j;
                                        	num++;
                                        	check=0;
                                        }
                                        break;
                                    }
                                    else if(board[a][b].type==NONE)
                                        break;
                                    else if(board[a][b].type==WHITE)
                                    {
                                        a+=1;
                                        b+=1;
                                    }

                            }
                        }
                        if(i-1>=0)        //Neighbpur position one row above and in the same coloumn

			{
                            if(board[i-1][j].type==NONE)
                            {
                                int check=1;
                                int a=i+1;
                                int b=j;
                                while(a<SIZE && check==1)
                                {
                                    if(board[a][b].type==BLACK)
                                    {
                                    	if((i-1>=0 && i-1<8) && (j>=0 && j<8))
                                    	{
                                       		arr[num][0]=i-1;
                                        	arr[num][1]=j;
                                        	arr[num][2] = i;
                                        	arr[num][3] = j;
                                        	num++;
                                        	check=0;
                                        }
                                        break;
                                    }
                                    else if(board[a][b].type==NONE)
                                        break;
                                    else if(board[a][b].type == WHITE)
                                    {
                                        a+=1;
                                    }
                                }
                            }
                        }
                        if(i-1>=0 && j+1<=SIZE)        //Neighbpur position one row above and one coloum to the right
                        {
                            if(board[i-1][j+1].type==NONE)
                            {
                                int check=1;
                                int a=i+1;
                                int b=j-1;
                                while(a<SIZE && b>=0 && check==1)
                                {
                                    if(board[a][b].type==BLACK)
                                    {
                                    	if((i-1>=0 && i-1<8) && (j+1>=0 && j+1<8))
                                    	{
                                        	arr[num][0]=i-1;
                                        	arr[num][1]=j+1;
                                        	arr[num][2] = i;
                                        	arr[num][3] = j;
                                        	num++;
                                        	check=0;
                                        }
                                        break;
                                    }
                                    else if(board[a][b].type==NONE)
                                        break;
                                    else if(board[a][b].type == WHITE)
                                    {
                                        a+=1;
                                        b-=1;
                                    }
                                }
                            }
                        }
                        if(j-1>=0)  //Neighbpur position in the same row and one coloum to the left
			{
                            if(board[i][j-1].type==NONE)
                            {
                                int check=1;
                                int a=i;
                                int b=j+1;
                                while(b<SIZE && check==1)
                                {
                                    if(board[a][b].type==BLACK)
                                    {
                                    	if((i>=0 && i<8) && (j-1>=0 && j-1<8))
                                    	{
                                        	arr[num][0]=i;
                                        	arr[num][1]=j-1;
                                        	arr[num][2] = i;
                                        	arr[num][3] = j;
                                        	num++;
                                        	check=0;
                                        }
                                        break;
                                    }
                                    else if(board[a][b].type==NONE)
                                        break;
                                    else if(board[a][b].type == WHITE)
                                    {
                                        b+=1;
                                    }
                                }
                            }
                        }
                        if(j+1<=SIZE)            //Neighbpur position in the same row and one coloum to the right
			{
                            if(board[i][j+1].type==NONE)
                            {
                                int check=1;
                                int a=i;
                                int b=j-1;
                                while(b>=0 && check==1)
                                {
                                    if(board[a][b].type==BLACK)
                                    {
                                    	if((i>=0 && i<8) && (j+1>=0 && j+1<8))
                                    	{
                                        	arr[num][0]=i;
                                        	arr[num][1]=j+1;
                                        	arr[num][2] = i;
                                        	arr[num][3] = j;
                                        	num++;
                                        	check=0;
                                        }
                                        break;
                                    }
                                    else if(board[a][b].type==NONE)
                                        break;
                                    else if(board[a][b].type == WHITE)
                                    {
                                        b-=1;
                                    }
                                }
                            }
                        }
                        if(i+1>=SIZE && j-1>=0)                //Neighbpur position one row below and one coloum to the left
                        {
                            if(board[i+1][j-1].type==NONE)
                            {
                                int check=1;
                                int a=i-1;
                                int b=j+1;
                                while(a<SIZE && b>=0 && check==1)
                                {
                                    if(board[a][b].type==BLACK)
                                    {
                                    	if((i+1>=0 && i+1<8) && (j-1>=0 && j-1<8))
                                    	{
                                        	arr[num][0]=i+1;
                                        	arr[num][1]=j-1;
                                        	arr[num][2] = i;
                                        	arr[num][3] = j;
                                        	num++;
                                        	check=0;
                                        }
                                        break;
                                    }
                                    else if(board[a][b].type==NONE)
                                        break;
                                    else if(board[a][b].type == WHITE)
                                    {
                                        a-=1;
                                        b+=1;
                                    }
                                }
                            }
                        }
                        if(i+1<=SIZE)            //Neighbpur position one row below and in the same coloumn
			{
                            if(board[i+1][j].type==NONE)
                            {
                                int check=1;
                                int a=i-1;
                                int b=j;
                                while(a>=0 && check==1)
                                {
                                    if(board[a][b].type==BLACK)
                                    {
                                    	if((i+1>=0 && i+1<8) && (j>=0 && j<8))
                                    	{
                                        	arr[num][0]=i+1;
                                        	arr[num][1]=j;
                                        	arr[num][2] = i;
                                        	arr[num][3] = j;
                                        	num++;
                                        	check=0;
                                        }
                                        break;
                                    }
                                    else if(board[a][b].type==NONE)
                                        break;
                                    else if(board[a][b].type == WHITE)
                                    {
                                        a-=1;
                                    }
                                }
                            }
                        }
                        if(i+1<=SIZE && j+1<=SIZE)              //Neighbpur position one row below and one coloum to the right
			{
                            if(board[i+1][j+1].type==NONE)
                            {
                                int check=1;
                                int a=i-1;
                                int b=j-1;
                                while(a>=0 && b>=0 && check==1)
                                {
                                    if(board[a][b].type==BLACK)
                                    {
                                    	if((i+1>=0 && i+1<8) && (j+1>=0 && j+1<8))
                                    	{
                                        	arr[num][0]=i+1;
                                        	arr[num][1]=j+1;
                                        	arr[num][2] = i;
                                        	arr[num][3] = j;
                                        	num++;
                                        	check=0;
                                        }
                                        break;
                                    }
                                    else if(board[a][b].type==NONE)
                                        break;
                                    else if(board[a][b].type == WHITE)
                                    {
                                        a-=1;
                                        b-=1;
                                    }
                                }
                            }
                        }
                        break;
                    default:
                        break;
                }
            }
        }
    }
}
else
    {
        for(int i=0; i<SIZE;i++)
        {
            for(int j=0; j<SIZE;j++)
            {
                switch(board[i][j].type)
                {
                    case BLACK: // When we find a rival disk, a series of if statements determine if any of its neighbouring element is a possible move 

                        if(i-1>=0 && j-1>=0)       //Neighbpur position one row above and one coloum to the left
			{
                            if(board[i-1][j-1].type==NONE)
                            {
                                int check=1;
                                int a=i+1;
                                int b=j+1;
                                while(a<SIZE && b<SIZE && check==1)
                                {
                                    if(board[a][b].type==WHITE)
                                    {
                                    	if((i-1>=0 && i-1<8) && (j-1>=0 && j-1<8))
                                    	{
                                        	arr[num][0] = i-1;
                                        	arr[num][1] = j-1;
                                        	arr[num][2] = i;
                                        	arr[num][3] = j;
                                        	num++;
                                        	check=0;
                                        }
                                        break;
                                    }
                                    else if(board[a][b].type==NONE)
                                        break;
                                    else if(board[a][b].type==BLACK)
                                    {
                                        a+=1;
                                        b+=1;
                                    }
                                }
                            }
                        }
                       
                        
                        


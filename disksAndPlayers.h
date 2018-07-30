
#define len 10
   typedef struct position{
        int row;
        int col;
    } position;

// Initialization of enum which is used to denote each disk
    enum colour{
        WHITE,
        BLACK,
        NONEp,
    };

    typedef struct disk{
        enum colour type;
        position pos;
    } disk;

    typedef struct player{
        char name[20];
        enum colour type;
        int points;
    } player;

    //The structs player1 and player2 are declared with extern keyword so that other functions and files can directly access them.
    extern player player1;
    extern player player2;
 
    void initializePlayers();

    void initializeBoard(disk board[SIZE][SIZE]);

    void results();

    void printBoard(disk board [SIZE][SIZE]);

    void makemove(disk board[SIZE][SIZE], player Cplayer, int chosenrow, int chosencol, int rivaldiskinquesrow, int rivaldiskinquescol);

    void possiblemoves(disk board[SIZE][SIZE], player Cplayer);
    
    
void gamelogic(disk board[SIZE][SIZE], player player1, player player2);

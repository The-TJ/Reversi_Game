 #define SIZE 8

    enum colour{
        WHITE,
        BLACK,
        NONE
    };

    typedef struct position{
        int row;
        int col;
    } position;

    typedef struct disk{
        enum colour type;
        position pos;
    } disk;

    typedef struct player{
        char name[20];
        enum colour type;
        int points;
    } player;

    extern player player1;
    extern player player2;
 
    void initializePlayers();

    void initializeBoard(disk board[SIZE][SIZE]);

    void results();

    void printBoard(disk board [SIZE][SIZE]);

    void makemove(disk board[SIZE][SIZE], player Cplayer, int chosenrow, int chosencol, int rivaldiskinquesrow, int rivaldiskinquescol);

    void possiblemoves(disk board[SIZE][SIZE], player Cplayer);

    void gamelogic(disk board[SIZE][SIZE], player player1, player player2);

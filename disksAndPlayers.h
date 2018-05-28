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

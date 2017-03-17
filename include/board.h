#ifndef BOARD_H
#define BOARD_H

    static const int FREE = -1;
    static const int WHITE = 0;
    static const int BLACK = 1;
    static const int SIZE = 4;

class board
{


    public:
        board();
        virtual ~board();

        int get_Board(int i, int j);
        void set_Board(int i, int j, int value);
    protected:

    private:
        int game_board[SIZE][SIZE];

};

#endif // BOARD_H

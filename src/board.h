#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <array>

    typedef std::array<int, 2> tabmove;
    typedef std::array<int,3> tabcount;
    static const int FREE = 0;
    static const int WHITE = -1;
    static const int BLACK = 1;
    static const int SIZE = 4;
    static const int LEFT_UP_START = (SIZE/2) - 1;
    static const int RIGHT_DOWN_START = (SIZE/2);

class board
{

    public:
        board();
        virtual ~board();

        int get_Board(int i, int j) const;
        void set_Board(int i, int j, int value);
        int number_pieces(int player);

    private:
        int game_board[SIZE][SIZE];

};

#endif // BOARD_H

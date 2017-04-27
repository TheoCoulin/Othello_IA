#ifndef DISPLAY_H
#define DISPLAY_H
#include "board.h"

class display
{
    public:
        display();
        virtual ~display();
        void print_board_term(board b);
};

#endif // DISPLAY_H

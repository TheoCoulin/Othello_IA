#ifndef DISPLAY_H
#define DISPLAY_H
#include "board.h"

class display
{
    public:
        display();
        virtual ~display();
        void print_board_term(board b);
    protected:

    private:
};

#endif // DISPLAY_H

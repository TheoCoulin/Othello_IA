#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "display.h"
#include "play.h"

class game
{
    public:
        game(board bo);
        virtual ~game();
        bool end_of_game(int player);
        int winner();
        void updateBoard(const tabmove& m, int player);
        board b;

    protected:

    private:
    	
};

#endif // GAME_H

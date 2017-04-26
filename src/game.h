#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "display.h"
#include "moves.h"

class game
{
    public:
        game(board bo);
        virtual ~game();
        bool end_of_game(int player);
        int winner();
        void updateBoard(const tabmove& m, int player);
	int switch_player(int player);        
	board b;
};

#endif // GAME_H

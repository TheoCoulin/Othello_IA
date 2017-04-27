#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "display.h"
#include "moves.h"

class game
{
    public:
        game(board bo, int p);
        virtual ~game();

        void game_loop();
        bool end_of_game(int player);
        int winner();
        void updateBoard(const tabmove& m, int player);
		int get_Player();
		void switch_player();
		int opposite_Player();        
		board b;

	private:
		int player;
};

#endif // GAME_H

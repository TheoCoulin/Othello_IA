#ifndef PLAY_H
#define PLAY_H
#include <array>
#include "board.h"
#include "game.h"



class play
{
	enum typeMode {Min, Max};
    public:
        play();
        virtual ~play();

        void game_loop();

		tabmove findBestMove(game g);
		int minimax(game g, int depth);
		int alphabeta(game g, int depth, int alpha, int beta);
		int evaluate(moves mo, board b);



	private:
		game g;
		display disp;
};

#endif // PLAY_H

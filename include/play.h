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

<<<<<<< HEAD
        void game_loop();

		tabmove findBestMove(game g);
		int minimax(game g, int depth);
		int alphabeta(game g, int depth, int alpha, int beta);
=======
		tabmove findBestMove(moves mo, board b, int player);
		int minimax(board b, int depth, typeMode mode);
>>>>>>> d72a38d3338ba190801b089eaa2b298f0a756dea
		int evaluate(moves mo, board b);



	private:
		game g;
		display disp;
};

#endif // PLAY_H

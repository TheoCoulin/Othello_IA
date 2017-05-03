#ifndef PLAY_H
#define PLAY_H
#include <array>
#include "board.h"
#include "moves.h"
#include "tree.h"



class play
{
	enum typeMode {Min, Max};
    public:
        play();
        virtual ~play();

		tabmove findBestMove(moves mo, board b, int player);
		int minimax(board b, int depth, typeMode mode);
		int evaluate(moves mo, board b);
};

#endif // PLAY_H

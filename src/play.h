#ifndef PLAY_H
#define PLAY_H
#include <array>
#include "board.h"
#include "moves.h"
#include "tree.h"



class play
{
	enum typeMode {min, max};
    public:
        play();
        virtual ~play();

		tabmove findBestMove(moves mo, board b, int player);
		int minimax(board b, tree& t, int depth, play::typeMode mode);
		//int min_value(node& n);
		//int max_value(node& n)
		int evaluate(moves mo, board b);
};

#endif // PLAY_H

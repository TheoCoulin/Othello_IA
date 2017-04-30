#ifndef PLAY_H
#define PLAY_H
#include <array>
#include "board.h"
#include "moves.h"

class play
{

    public:
        play();
        virtual ~play();

		tabmove findBestMove(moves mo, board b, int player);
		int minimax(board b, int depth, bool isMaxPlayer); // Rajouter un moves en param ?
		int evaluate(board b); // ajouter un moves en param ?
};

#endif // PLAY_H

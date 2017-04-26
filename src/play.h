#ifndef PLAY_H
#define PLAY_H
#include <array>
#include "board.h"
#include "moves.h"
#include "game.h"

class play
{

    public:
        play();
        virtual ~play();
	void make_move(moves mo, int player, game g);
};

#endif // PLAY_H

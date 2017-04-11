#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "display.h"
#include "play.h"

class game
{
    public:
        game();
        virtual ~game();
        bool end_of_game(board b, int player);
        int number_pieces(int player, board b);

    protected:

    private:
};

#endif // GAME_H

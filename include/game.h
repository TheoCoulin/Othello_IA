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
        bool end_of_game(board b);
        bool end_of_game_black(board b, play p);
        bool end_of_game_white(board b, play p);
        int number_pieces(int player, board b);

    protected:

    private:
};

#endif // GAME_H

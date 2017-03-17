#include <iostream>
#include "board.h"
#include "display.h"
#include "play.h"

using namespace std;

int main()
{
    board game;
    display disp;
    play p;
    int moves[2] = {0, 0};
    /* while (!end_of_game) {
            disp.print_board_term(game);
            ask_move(move);
       }
    */
    disp.print_board_term(game);
    p.ask_move(moves);
    return 0;
}

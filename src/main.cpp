#include "board.h"
#include "display.h"
#include "play.h"

using namespace std;

int main()
{

    board game;
    display disp;
    play p;
    tabmove moves;
    moves.fill(2);
    /* while (!end_of_game) {
            int player = BLACK;
            disp.print_board_term(game);
            do
            {
                ask_move(move);
            } while (!isValidMove())

            if (player == WHITE) player = BLACK;
            else player = WHITE;
       }
    */
    disp.print_board_term(game);
    p.ask_move(moves);
    return 0;
}

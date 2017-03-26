#include "board.h"
#include "display.h"
#include "play.h"
#include "game.h"

using namespace std;

int main()
{

    board b;
    display disp;
    play p;
    tabmove moves;
    moves.fill(0);
    game g;

    /*
    while(! g.end_of_game(b))
    {
        do
        {
            p.ask_move(moves);
        } while (p.isValidMove(moves, player, b));
        cout << "i : " << moves[0] << ", j : " << moves[1] << endl;
        p.updateBoard(b, moves, player, disp);
        if (player == BLACK) player = WHITE;
        else player = BLACK;
    }
    */


    return 0;
}

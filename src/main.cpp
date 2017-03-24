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
    moves.fill(0);
    bool a = true;
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


    //cout << "count : "<<p.searchColU(moves, WHITE, game)[0] << ", i : " << p.searchColU(moves, WHITE, game)[1] << ", j : " << p.searchColU(moves, WHITE, game)[2] << " " << endl;
    while (a)
    {
        game.set_Board(2, 1, BLACK);
        game.set_Board(1, 2, BLACK);
        game.set_Board(3,3, WHITE);
        disp.print_board_term(game);
        p.ask_move(moves);
        cout <<  "i : " << moves[0] << ", j : " << moves[1] << endl;
        p.isValidMove(moves, WHITE, game);
    }

    return 0;
}

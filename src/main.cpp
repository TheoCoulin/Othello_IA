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

    int player = BLACK;

  //  cout << LEFT_UP_START << " = LUS" << endl;
   // cout << RIGHT_DOWN_START << " = RDS" << endl;

    cout << "For each move, enter first the row, then the column" << endl;
    cout << endl;

    disp.print_board_term(b);

    while(!g.end_of_game(b, WHITE) || !g.end_of_game(b, BLACK))
    {
        cout << "number of blacks : " << g.number_pieces(BLACK, b) << endl;
        cout << "number of whites : " << g.number_pieces(WHITE, b) << endl;
        cout << "it's your turn ";
        if(player == 1) cout << "black" << endl;
        else cout << "white" << endl;

        do
        {
            p.ask_move(moves);
            if(! p.isValidMove(moves,player,b)) cout << "Try again" << endl;
        } while (! p.isValidMove(moves, player, b));
      //  cout << "i : " << moves[0] << ", j : " << moves[1] << endl;
        b = p.updateBoard(b, moves, player, disp);
        if (player == BLACK && !g.end_of_game(b, WHITE)) player = WHITE;
        else if (player == WHITE && !g.end_of_game(b, BLACK)) player = BLACK;
    }
    cout << "number of blacks: " << g.number_pieces(BLACK, b) << endl;
    cout << "number of whites: " << g.number_pieces(WHITE, b) << endl;
    g.winner(b);

    return 0;
}

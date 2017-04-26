#include "board.h"
#include "display.h"
#include "play.h"
#include "game.h"

using namespace std;

int main()
{

    board b;
    display disp;
    moves mo;
    game g (b);
    play p;

    int player = BLACK;

  //  cout << LEFT_UP_START << " = LUS" << endl;
   // cout << RIGHT_DOWN_START << " = RDS" << endl;

    cout << "For each move, enter first the row, then the column" << endl;
    cout << endl;

    disp.print_board_term(g.b);

    while(!g.end_of_game(WHITE) || !g.end_of_game(BLACK))
    {
        cout << "number of blacks : " << g.b.number_pieces(BLACK) << endl;
        cout << "number of whites : " << g.b.number_pieces(WHITE) << endl;
        cout << "it's your turn ";
        if(player == 1) cout << "black" << endl;
        else cout << "white" << endl;
	
	//p.make_move(mo, player, g.b);
    tabmove moves;
    moves.fill(0);
    
	do
    {
     	mo.ask_move(moves);
     	if(! mo.isValidMove(moves,player,g.b)) cout << "Try again" << endl;
     } while (! mo.isValidMove(moves, player, g.b));
     g.updateBoard(moves, player);
 
	
        disp.print_board_term(g.b);
        player = g.switch_player(player);
    }
    cout << "number of blacks: " << g.b.number_pieces(BLACK) << endl;
    cout << "number of whites: " << g.b.number_pieces(WHITE) << endl;
    g.winner();

    return 0;
}

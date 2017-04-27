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
    game g (b, BLACK);

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
        if(g.get_Player() == 1) cout << "black" << endl;
        else cout << "white" << endl;
	
    tabmove mov;
    mov.fill(0);
    
	do
    {
     	mo.ask_move(mov);
     	if(! mo.isValidMove(mov,g.get_Player(),g.b)) cout << "Try again" << endl;
     } while (! mo.isValidMove(mov, g.get_Player(), g.b));
     g.updateBoard(mov, g.get_Player());
 
	
        disp.print_board_term(g.b);
        if (!g.end_of_game(g.opposite_Player())) g.switch_player();
    }
    cout << "number of blacks: " << g.b.number_pieces(BLACK) << endl;
    cout << "number of whites: " << g.b.number_pieces(WHITE) << endl;
    g.winner();

    return 0;
}

#include "game.h"
#include <iostream>

using namespace std;

play p;

game::game()
{

}

game::~game()
{
    //dtor
}

bool game::end_of_game(board b, int player)
{
	tabmove move;
	bool end = true; // on considere que la partie est finie

    for(int i = 0; i < SIZE; i++)
    {
        int j = 0;
        while(end && j<SIZE)
        {
            move[0] = i;
            move[1] = j;
            if(b.get_Board(i,j) == FREE && p.isValidMove(move, player, b))
            {
                //cout << player << " : " << i << ", " << j << endl;
                end = false; // Si la case est vide mais qu'un coup est valide depuis celle-ci, on peut continuer a jouer : end passe a faux
            }
            j++;
        }
    }

    if (end) cout << player <<" : no more moves" << endl;
    return end;
}




int game::number_pieces(int player, board b)
{
    int res = 0;

    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(b.get_Board(i,j) == player) res ++;
        }
    }

    return res;
}


int game::winner(board b)
{
    if(end_of_game(b, WHITE) && end_of_game(b, BLACK))
    {
        cout << "End of game !" << endl;
        if(number_pieces(WHITE,b) > number_pieces(BLACK,b))
        {
            cout << "Whites win" << endl;
            return WHITE;
        }
        else
        {
            cout << "Blacks win" << endl;
            return BLACK;
        }
    }
    return -1;
}

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
	bool end = true; // on considere aue la partie est finie

    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
			move[0] = i;
			move[1] = j;
            if(b.get_Board(i,j) == FREE && p.isValidMove(move, player, b)) end = false; // Si la case est vide mais qu'un coup est valide depuis celle-ci, on peut continuer a jouer : end passe a faux
        }
    }

    if (end) cout << "partie finie" << endl;
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



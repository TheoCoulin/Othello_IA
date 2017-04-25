#include "game.h"
#include <iostream>

using namespace std;

play p;

game::game(board bo)
{
    b = bo;
}

game::~game()
{
    //dtor
}

bool game::end_of_game(int player)
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

int game::winner()
{
    if(end_of_game(WHITE) && end_of_game(BLACK))
    {
        cout << "End of game !" << endl;
        if(b.number_pieces(WHITE) > b.number_pieces(BLACK))
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
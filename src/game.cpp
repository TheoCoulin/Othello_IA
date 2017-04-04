#include "game.h"
#include <iostream>

using namespace std;

game::game()
{
    //ctor
}

game::~game()
{
    //dtor
}

bool game::end_of_game(board b)
{

    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(b.get_Board(i,j) != FREE) return false;
        }
    }

    cout << "partie finie" << endl;
    return true;
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



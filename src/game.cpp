#include "game.h"

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
    bool res = true;

    for (int i = 0; i < SIZE; i++)
    {
        for(int j; j < SIZE; j++)
        {
            if (b.get_Board(i,j) != FREE) res = false;
        }
    }

    return res;

}




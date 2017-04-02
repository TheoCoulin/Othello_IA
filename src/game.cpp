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

    play p;
    if(!end_of_game_black(b,p) || end_of_game_white(b,p)) return false;

    cout << "partie finie" << endl;
    return true;
}

bool game::end_of_game_black(board b, play p)
{
    tabmove tab;
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            tab[0] = i;
            tab[1] = j;
            if(p.isValidMove(tab,BLACK,b)) return false;
        }
    }
    cout << "aucun coup possible pour le noirs" << endl;
    return true;
}

bool game::end_of_game_white(board b, play p)
{
    tabmove tab;
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            tab[0] = i;
            tab[1] = j;
            if(p.isValidMove(tab,WHITE,b)) return false;
        }
    }
    cout << "aucun coup possible pour les blancs" << endl;
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



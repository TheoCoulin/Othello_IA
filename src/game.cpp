#include "game.h"
#include <iostream>

using namespace std;

moves mo;

game::game(board bo, int p)
{
    b = bo;
    player = p;
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
            if(b.get_Board(i,j) == FREE && mo.isValidMove(move, player, b))
                end = false; // Si la case est vide mais qu'un coup est valide depuis celle-ci, on peut continuer a jouer : end passe a faux
            j++;
        }
    }

    // if (end) cout << player <<" : no more moves" << endl;
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

/******************************************************
*   for each sort of move (line left, column up, ..)
*   we verify it's valid (count != 0)
*   we change the value of each place between the move
*   and the closest other piece of the player.
*   finally we display the new board
*   Problem with all the diagonals. 
*   It doesn't display anything..
*******************************************************/
void game::updateBoard(const tabmove& m, int player)
{
    int i, j;
    tabcount tab;

    tab = mo.searchLineL(m, player, b);
    if(tab[0] != 0)
    {
        for(j = m[1]; j > tab[2]; j--)
            b.set_Board(m[0], j, player);
    }

    tab = mo.searchLineR(m, player, b);
    if(tab[0] != 0)
    {
        for (j = m[1]; j < tab[2]; j++)
            b.set_Board(m[0], j, player);
    }

    tab = mo.searchColD(m, player, b);
    if(tab[0] != 0)
    {
        for(int i = m[0]; i < tab[1]; i++)
            b.set_Board(i, m[1], player);
    }

    tab = mo.searchColU(m, player, b);
    if(tab[0] != 0)
    {
        for(i = m[0]; i > tab[1]; i--)
            b.set_Board(i, m[1], player);
    }


    tab = mo.searchDiagRD(m, player, b);
    if(tab[0] != 0)
    {
        i = m[0];
        j = m[1];
        while (i < tab[1] && j < tab[2])
        {
            b.set_Board(i, j, player);
            i++;
            j++;
        }
    }

    tab = mo.searchDiagLD(m, player, b);
    if(tab[0] != 0)
    {
        i = m[0];
        j = m[1];
        while(i < tab[1] && j > tab[2])
        {
            b.set_Board(i, j, player);
            i++;
            j--;
        }
    }


    tab = mo.searchDiagRU(m, player, b);
    if(tab[0] != 0)
    {
        i = m[0];
        j = m[1];
        while(i > tab[1] && j < tab[2])
        {
            b.set_Board(i, j, player);
            i--;
            j++;
        }
    }


    tab = mo.searchDiagLU(m, player, b);
    if(tab[0] !=0)
    {
        i = m[0];
        j = m[1];
        while(i > tab[1] && j > tab[2])
        {
            b.set_Board(i, j, player);
            i--;
            j--;
        }
    }
}

int game::get_Player()
{
    return player;
}

void game::switch_player()
{
	player = -player;
}

int game::opposite_Player()
{
    return -player;
}
       

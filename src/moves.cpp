#include "moves.h"
#include <iostream>


moves::moves()
{
    //ctor
}

moves::~moves()
{
    //dtor
}

tabmove moves::ask_move(tabmove& m)
{
    // Vérifier que les caractères entrés sont bien des entiers ET sont compris entre 0 et 7 inclus.
    cin >> m[0] ;
    cin >> m[1] ;

    return m;
}

tabcount moves::searchLineL(const tabmove& m, int player, board b) const
{
    int count = 0;
    tabcount tab;
    tab.fill(0);
    tab[1] = m[0];
    // test if the move can be valid in a line by looking at the direct neighbours (cf rules)
    if(m[1] == 0 || b.get_Board(m[0], m[1]-1) == FREE || b.get_Board(m[0], m[1]-1) == player) return tab;

    int j= m[1] - 1;
    while ( b.get_Board(m[0],j) != player && b.get_Board(m[0],j) != FREE && j > 0)
    {
        count ++;
        tab[2] = j - 1; // Pour aller cherche le pion de la couleur player qui "ferme la ligne"
        j -- ;
    }

    if (b.get_Board(tab[1], tab[2]) == player) tab[0] = count; // Si au bout de la ligne de pions adverse on trouve un pion du joueur, le coup est valide

    return tab;
}

tabcount moves::searchLineR(const tabmove& m, int player, board b) const
{
    int count = 0;      //initialization of count
    tabcount tab;
    tab.fill(0);
    tab[1] = m[0];      // on se place sur la ligne du mouvement

    //test if the move can be valid  in a line by looking at the direct right neighbour
    if(m[1] == SIZE - 1 || b.get_Board(tab[1], m[1]+1) == FREE || b.get_Board(tab[1], m[1]+1) == player) return tab;

    int j = m[1] + 1;
    while(b.get_Board(tab[1], j) != player && b.get_Board(tab[1], j) != FREE && j < SIZE-1)
    {
        count ++;
        tab[2] = j + 1;
        j ++;
    }

    if(b.get_Board(tab[1], tab[2]) == player) tab[0] = count;
    return tab;

}

tabcount moves::searchColU(const tabmove& m, int player, board b) const
{
    int count = 0;
    tabcount tab;
    tab.fill(0);
    tab[2] = m[1];
    // test if the move can be valid in a column by looking at the direct neighbours (cf rules)
    if(m[0] == 0 || b.get_Board( m[0]-1, m[1]) == FREE || b.get_Board(m[0]-1, m[1]) == player) return tab;


    int i= m[0] - 1;
    while ( b.get_Board(i,m[1]) != player && b.get_Board(i, m[1]) != FREE && i > 0)
    {
        count ++;
        tab[1] = i - 1;
        i--;
    }
    if (b.get_Board(tab[1], tab[2]) == player) tab[0] = count; // Si au bout de la ligne de pions adverse on trouve un pion du joueur, le coup est valide
    return tab;
}

tabcount moves::searchColD(const tabmove& m, int player, board b) const
{
    int count = 0;
    tabcount tab;
    tab.fill(0);
    tab[2] = m[1];
    // test if the move can be valid in a column by looking at the direct neighbours (cf rules)
    if(m[0] == SIZE - 1 || b.get_Board(m[0] + 1, m[1]) == FREE || b.get_Board(m[0] + 1, m[1]) == player) return tab;

    int i= m[0] + 1;
    while (b.get_Board(i,m[1]) != player && b.get_Board(i, m[1]) != FREE && i < SIZE-1)
    {
        count ++;
        tab[1] = i + 1;
        i++;
    }
    if (b.get_Board(tab[1], tab[2]) == player) tab[0] = count; // Si au bout de la ligne de pions adverse on trouve un pion du joueur, le coup est valide
    return tab;
}

tabcount moves::searchDiagLU(const tabmove& m, int player, board b) const
{
    int count = 0;
    tabcount tab;
    tab.fill(0);
    tab[2] = m[1];
    // test if the move can be valid in a diagonal by looking at the direct neighbours (cf rules)
    if(m[0] == 0 || m[1] == 0 || b.get_Board(m[0]-1, m[1] - 1) == FREE || b.get_Board(m[0]-1, m[1] - 1) == player) return tab;
    int i = m[0]-1;
    int j = m[1]-1;
    while ((i > 0) && (j > 0) && b.get_Board(i,j) != player && b.get_Board(i, j) != FREE)
    {
        count ++;
        tab[1] = i - 1;
        tab[2] = j - 1;

        i--;
        j--;
    }
    if (b.get_Board(tab[1], tab[2]) == player) tab[0] = count; // Si au bout de la ligne de pions adverse on trouve un pion du joueur, le coup est valide
    return tab;
}

tabcount moves::searchDiagRU(const tabmove& m, int player, board b) const
{
    int count = 0;
    tabcount tab;
    tab.fill(0);
    // test if the move can be valid in a diagonal by looking at the direct neighbours (cf rules)
    if(m[0] == 0 || m[1] == SIZE - 1 || b.get_Board(m[0] - 1, m[1] + 1) == FREE || b.get_Board(m[0] - 1, m[1] + 1) == player) return tab;
    int i = m[0]-1;
    int j = m[1]+1;
    while ((i > 0) && (j < SIZE - 1) && b.get_Board(i,j) != player && b.get_Board(i, j) != FREE)
    {
        count ++;
        tab[1] = i - 1;
        tab[2] = j + 1;

        i--;
        j++;
    }
    if (b.get_Board(tab[1], tab[2]) == player) tab[0] = count; // Si au bout de la ligne de pions adverse on trouve un pion du joueur, le coup est valide
    return tab;
}

tabcount moves::searchDiagLD(const tabmove& m, int player, board b) const
{
    int count = 0;
    tabcount tab;
    tab.fill(0);
    // test if the move can be valid in a diagonal by looking at the direct neighbours (cf rules)
    if(m[0] == SIZE - 1 || m[1] == 0 || b.get_Board(m[0] + 1, m[1] - 1) == FREE || b.get_Board(m[0] + 1, m[1] - 1) == player) return tab;
    int i = m[0]+1;
    int j = m[1]-1;
    while ((i < SIZE - 1) && (j > 0) && b.get_Board(i,j) != player && b.get_Board(i, j) != FREE)
{
        count ++;
        tab[1] = i + 1;
        tab[2] = j - 1;
        i++;
        j--;
    }
    if (b.get_Board(tab[1], tab[2]) == player) tab[0] = count; // Si au bout de la ligne de pions adverse on trouve un pion du joueur, le coup est valide
    return tab;
}

tabcount moves::searchDiagRD(const tabmove& m, int player, board b) const
{
    int count = 0;
    tabcount tab;
    tab.fill(0);
    // test if the move can be valid in a diagonal by looking at the direct neighbours (cf rules)
    if(m[0] == SIZE - 1 || b.get_Board(m[0] + 1, m[1] + 1) == FREE || b.get_Board(m[0] + 1, m[1] + 1) == player) return tab;
    int i = m[0]+1;
    int j = m[1]+1;
    while ((i < SIZE - 1) && (j < SIZE - 1) && b.get_Board(i,j) != player && b.get_Board(i, j) != FREE)
    {
        count ++;
        tab[1] = i + 1;
        tab[2] = j + 1;
        i++;
        j++;
    }
    if (b.get_Board(tab[1], tab[2]) == player) tab[0] = count; // Si au bout de la ligne de pions adverse on trouve un pion du joueur, le coup est valide
    return tab;
}

bool moves::isValidMove(const tabmove& m, int player, board b) const
{

    if((searchLineL(m, player, b)[0] != 0 || searchLineR(m, player, b)[0] != 0 || searchColD(m, player, b)[0] != 0 || searchColU(m, player, b)[0] != 0
    || searchDiagRD(m, player, b)[0] != 0 || searchDiagLU(m, player, b)[0] != 0 || searchDiagLD(m, player, b)[0] != 0 || searchDiagRU(m, player, b)[0] != 0)
    && b.get_Board(m[0], m[1]) == FREE)
        return true;
    else
    	return false;
}

/***********************************
*   Function that return all 
*   the possible moves of the
*   current player in a list of
*   "tabmove" arrays : [0] : i
*   coordinate of the move,
*   [1] : j coordinate of the move
***********************************/

list<tabmove> moves::get_Moves(board b, int player)
{
    list<tabmove> possibleMoves;
    tabmove m;
    for (int i = 0; i < SIZE; i++)
    {
        m[0] = i;
        for (int j = 0; j< SIZE; j++)
        {
            m[1] = j;
            if (isValidMove(m, player, b)) possibleMoves.push_back(m); 
        }
    }
    return possibleMoves;
}
#include "play.h"
#include <iostream>

using namespace std;

play::play()
{
    //ctor
}

play::~play()
{
    //dtor
}

tabmove play::ask_move(tabmove& m)
{
    cout << "Entrez ligne et colonne" << endl;
    cin >> m[0] ;
    cin >> m[1] ;

    return m;
}

tabcount play::searchLineL(const tabmove& m, int player, board b) const
{
    int count = 0;
    tabcount tab;
    tab.fill(0);
    tab[1] = m[0];
    // test if the move can be valid in a line by looking at the direct neighbours (cf rules)
    if(m[1] == 0 || b.get_Board(m[0], m[1]-1) == FREE || b.get_Board(m[0], m[1]-1) == player) return tab;

    for(int j= m[1] - 1; j >= 0; j--)
    {
        if ( b.get_Board(m[0],j) != player && b.get_Board(m[0],j) != FREE)
        {
            count ++;
            tab[2] = j - 1; // Pour aller cherche le pion de la couleur player qui "ferme la ligne"
        }
    }

    if (b.get_Board(tab[1], tab[2]) == player) tab[0] = count; // Si au bout de la ligne de pions adverse on trouve un pion du joueur, le coup est valide
    return tab;
}

tabcount play::searchLineR(const tabmove& m, int player, board b) const
{
    int count = 0;
    tabcount tab;
    tab.fill(0);
    tab[1] = m[0];
    // test if the move can be valid in a line by looking at the direct neighbours (cf rules)
    if(m[1] == SIZE - 1 || b.get_Board(m[0], m[1]+1) == FREE || b.get_Board(m[0], m[1]+1) == player) return tab;
    for(int j= m[1] + 1; j < SIZE; j++)
    {
        if ( b.get_Board(m[0],j) != player && b.get_Board(m[0],j) != FREE)
        {
            count ++;
            tab[2] = j + 1;
        }
    }
    if (b.get_Board(tab[1], tab[2]) == player) tab[0] = count; // Si au bout de la ligne de pions adverse on trouve un pion du joueur, le coup est valide
    return tab;
}

tabcount play::searchColU(const tabmove& m, int player, board b) const
{
    int count = 0;
    tabcount tab;
    tab.fill(0);
    tab[2] = m[1];
    // test if the move can be valid in a line by looking at the direct neighbours (cf rules)
    if(m[0] == 0 || b.get_Board( m[0]-1, m[1]) == FREE || b.get_Board(m[0]-1, m[1]) == player) return tab;
    for(int i= m[0] + 1; i >= 0; i--)
    {
        if ( b.get_Board(i,m[1]) != player && b.get_Board(i, m[1]) != FREE)
        {
            count ++;
            tab[1] = i - 1;
        }
    }
    if (b.get_Board(tab[1], tab[2]) == player) tab[0] = count; // Si au bout de la ligne de pions adverse on trouve un pion du joueur, le coup est valide
    return tab;
}

tabcount play::searchColD(const tabmove& m, int player, board b) const
{
    int count = 0;
    tabcount tab;
    tab.fill(0);
    tab[2] = m[1];
    // test if the move can be valid in a line by looking at the direct neighbours (cf rules)
    if(m[0] == SIZE - 1 || b.get_Board(m[0]-1, m[1]) == FREE || b.get_Board(m[0]-1, m[1]) == player) return tab;
    for(int i= m[0] + 1; i < SIZE; i++)
    {
        if ( b.get_Board(i,m[1]) != player && b.get_Board(i, m[1]) != FREE)
        {
            count ++;
            tab[1] = i + 1;
        }
    }
    if (b.get_Board(tab[1], tab[2]) == player) tab[0] = count; // Si au bout de la ligne de pions adverse on trouve un pion du joueur, le coup est valide
    return tab;
}

tabcount play::searchDiagLU(const tabmove& m, int player, board b) const
{
    int count = 0;
    tabcount tab;
    tab.fill(0);
    tab[2] = m[1];
    // test if the move can be valid in a line by looking at the direct neighbours (cf rules)
    if(m[0] == 0 || m[1] == 0 || b.get_Board(m[0]-1, m[1] - 1) == FREE || b.get_Board(m[0]-1, m[1] - 1) == player) return tab;
    int i = m[0];
    int j = m[1];
    while ((i > 0) || (j > 0))
    {
        if (b.get_Board(i,j) != player && b.get_Board(i, j) != FREE)
        {
            count ++;
            tab[1] = i - 1;
            tab[2] = j - 1;
        }
        i--;
        j--;
    }
    if (b.get_Board(tab[1], tab[2]) == player) tab[0] = count; // Si au bout de la ligne de pions adverse on trouve un pion du joueur, le coup est valide
    return tab;
}

tabcount play::searchDiagRU(const tabmove& m, int player, board b) const
{
    int count = 0;
    tabcount tab;
    tab.fill(0);
    // test if the move can be valid in a line by looking at the direct neighbours (cf rules)
    if(m[0] == 0 || m[1] == SIZE - 1 || b.get_Board(m[0] - 1, m[1] + 1) == FREE || b.get_Board(m[0] - 1, m[1] + 1) == player) return tab;
    int i = m[0];
    int j = m[1];
    while ((i > 0) && (j < SIZE))
    {
        if (b.get_Board(i,j) != player && b.get_Board(i, j) != FREE)
        {
            count ++;
            tab[1] = i - 1;
            tab[2] = j + 1;
        }
        i--;
        j++;
    }
    if (b.get_Board(tab[1], tab[2]) == player) tab[0] = count; // Si au bout de la ligne de pions adverse on trouve un pion du joueur, le coup est valide
    return tab;
}

tabcount play::searchDiagLD(const tabmove& m, int player, board b) const
{
    int count = 0;
    tabcount tab;
    tab.fill(0);
    // test if the move can be valid in a line by looking at the direct neighbours (cf rules)
    if(m[0] == SIZE - 1 || m[1] == 0 || b.get_Board(m[0] + 1, m[1] - 1) == FREE || b.get_Board(m[0] + 1, m[1] - 1) == player) return tab;
    int i = m[0];
    int j = m[1];
    while ((i < SIZE) && (j > 0))
    {
        if (b.get_Board(i,j) != player && b.get_Board(i, j) != FREE)
        {
            count ++;
            tab[1] = i + 1;
            tab[2] = j - 1;
        }
        i++;
        j--;
    }
    if (b.get_Board(tab[1], tab[2]) == player) tab[0] = count; // Si au bout de la ligne de pions adverse on trouve un pion du joueur, le coup est valide
    return tab;
}

tabcount play::searchDiagRD(const tabmove& m, int player, board b) const
{
    int count = 0;
    tabcount tab;
    tab.fill(0);
    // test if the move can be valid in a line by looking at the direct neighbours (cf rules)
    if(m[0] == SIZE - 1 || b.get_Board(m[0] + 1, m[1] + 1) == FREE || b.get_Board(m[0] + 1, m[1] + 1) == player) return tab;
    int i = m[0];
    int j = m[1];
    while ((i < SIZE) && (j < SIZE))
    {
        if (b.get_Board(i,j) != player && b.get_Board(i, j) != FREE)
        {
            count ++;
            tab[1] = i + 1;
            tab[2] = j + 1;
        }
        i++;
        j++;
    }
    if (b.get_Board(tab[1], tab[2]) == player) tab[0] = count; // Si au bout de la ligne de pions adverse on trouve un pion du joueur, le coup est valide
    return tab;
}

bool play::isValidMove(const tabmove& m, int player, board b) const
{

    if((searchLineL(m, player, b)[0] != 0 || searchLineR(m, player, b)[0] != 0 || searchColD(m, player, b)[0] != 0 || searchColU(m, player, b)[0] != 0
    || searchDiagLD(m, player, b)[0] != 0 || searchDiagLU(m, player, b)[0] != 0 || searchDiagRD(m, player, b)[0] != 0 || searchDiagRU(m, player, b)[0] != 0)
    && b.get_Board(m[0], m[1]) == FREE)
    {
        cout << "Trop fort !" << endl;
        return true;
    }
    else
    {
        cout << "Nul" << endl;
        return false;
    }
}

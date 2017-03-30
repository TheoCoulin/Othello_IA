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

    for(int j= m[1] - 1; j > 0; j--)
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
    for(int j= m[1] + 1; j < SIZE - 1; j++)
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
    for(int i= m[0] - 1; i > 0; i--)
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
    if(m[0] == SIZE - 1 || b.get_Board(m[0] + 1, m[1]) == FREE || b.get_Board(m[0] + 1, m[1]) == player) return tab;
    for(int i= m[0] + 1; i < SIZE - 1; i++)
    {
        if (b.get_Board(i,m[1]) != player && b.get_Board(i, m[1]) != FREE)
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
    while ((i > 0) && (j < SIZE - 1))
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
    while ((i < SIZE - 1) && (j > 0))
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
    while ((i < SIZE - 1) && (j < SIZE - 1))
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

    if((searchLineL(m, player, b)[0] != 0 || searchLineR(m, player, b)[0] != 0  || searchColD(m, player, b)[0] != 0 || searchColU(m, player, b)[0] != 0
    || searchDiagRD(m, player, b)[0] != 0 || searchDiagLU(m, player, b)[0] != 0 || searchDiagLD(m, player, b)[0] != 0 || searchDiagRU(m, player, b)[0] != 0)
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

/*
* for each sort of move (line left, column up, ..) we verify it's valid (count != 0)
* we change the value of each place between the move and the closest other piece of the player.
* finally we display the new board
* Problem with all the diagonals. It doesn't display anything..
*/
board play::updateBoard(board b, const tabmove& m, int player, display disp)
{
    int i, j;

    tabcount tabLL = searchLineL(m, player, b);
    cout << "tabLL : " << tabLL[0] << tabLL[1] << tabLL[2] << endl;
   // cout << "searchLineL : " << searchLineL(m, player, b)[0] << searchLineL(m, player, b)[1] << searchLineL(m, player, b)[2] << endl;
    if(tabLL[0] != 0)
    {
        for(j = m[1]; j > tabLL[2]; j--)
            b.set_Board(m[0], j, player);
    }

    tabcount tabLR = searchLineR(m, player, b);
    cout << "tabLR : " << tabLR[0] << tabLR[1] << tabLR[2] << endl;
  //  cout << "searchLineR : " << searchLineR(m, player, b)[0] << searchLineR(m, player, b)[1] << searchLineR(m, player, b)[2] << endl;
    if(tabLR[0] != 0)
    {
        for (j = m[1]; j < tabLR[2]; j++)
            b.set_Board(m[0], j, player);
    }

    tabcount tabCD = searchColD(m, player, b);
    cout << "tabCD : " << tabCD[0] << tabCD[1] << tabCD[2] << endl;
 //   cout << "searchColD : " << searchColD(m, player, b)[0] << searchColD(m, player, b)[1] << searchColD(m, player, b)[2] << endl;
    if(tabCD[0] != 0)
    {
        for(int i = m[0]; i < tabCD[1]; i++)
            b.set_Board(i, m[1], player);
    }

    tabcount tabCU = searchColU(m, player, b);
    cout << "tabCU : " << tabCU[0] << tabCU[1] << tabCU[2] << endl;
  //  cout << "searchColU : " << searchColU(m, player, b)[0] << searchColU(m, player, b)[1] << searchColU(m, player, b)[2] << endl;
    if(tabCU[0] != 0)
    {
        for(i = m[0]; i > tabCU[1]; i--)
            b.set_Board(i, m[1], player);
    }


    tabcount tabDRD = searchDiagRD(m, player, b);
    cout << "tabDRD : " << tabDRD[0] << tabDRD[1] << tabDRD[2] << endl;
  //  cout << "searchDiagRD : " << searchDiagRD(m, player, b)[0] << searchDiagRD(m, player, b)[1] << searchDiagRD(m, player, b)[2] << endl;
    if(tabDRD[0] != 0)
    {
        i = m[0];
        j = m[1];
        while (i < tabDRD[1] && j < tabDRD[2])
        {
            b.set_Board(i, j, player);
            i++;
            j++;
        }
    }

    tabcount tabDLD = searchDiagLD(m, player, b);
    cout << "tabDLD : " << tabDLD[0] << tabDLD[1] << tabDLD[2] << endl;
//    cout << "searchDiagLD : " << searchDiagLD(m, player, b)[0] << searchDiagLD(m, player, b)[1] << searchDiagLD(m, player, b)[2] << endl;
    if(tabDLD[0] != 0)
    {
        i = m[0];
        j = m[1];
        while(i < tabDLD[1] && j > tabDLD[2])
        {
            b.set_Board(i, j, player);
            i++;
            j--;
        }
    }


    tabcount tabDRU = searchDiagRU(m, player, b);
    cout << "tabDRU : " << tabDRU[0] << tabDRU[1] << tabDRU[2] << endl;
 //   cout << "searchDiagRU : " << searchDiagRU(m, player, b)[0] << searchDiagRU(m, player, b)[1] << searchDiagRU(m, player, b)[2] << endl;
    if(tabDRU[0] != 0)
    {
        i = m[0];
        j = m[1];
        while(i > tabDRU[1] && j < tabDRU[2])
        {
            b.set_Board(i, j, player);
            i--;
            j++;
        }
    }


    tabcount tabDLU = searchDiagLU(m, player, b);
    cout << "tabDLU : " << tabDLU[0] << tabDLU[1] << tabDLU[2] << endl;
 //   cout << "searchDiagLU : " << searchDiagLU(m, player, b)[0] << searchDiagLU(m, player, b)[1] << searchDiagLU(m, player, b)[2] << endl;
    if(tabDLU[0] !=0)
    {
        i = m[0];
        j = m[1];
        while(i > tabDLU[1] && j > tabDLU[2])
        {
            b.set_Board(i, j, player);
            i--;
            j--;
        }
    }

    disp.display::print_board_term(b);
    return b;
}








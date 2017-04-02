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

tabcount play::searchLineR(const tabmove& m, int player, board b) const
{
    int count = 0;      //initialization of count
    tabcount tab;
    tab.fill(0);
    tab[1] = m[0];      // on se place sur la ligne du mouvement

    //test if the move can be valid  in a line by looking at the direct right neighbour
    if(m[1] == SIZE - 1 || b.get_Board(tab[1], m[1]+1) == FREE || b.get_Board(tab[1], m[1]+1) == player) return tab;

    int j = m[1] + 1;
    while(b.get_Board(tab[1], j) != player && b.get_Board(tab[1], j) != FREE && j < SIZE)
    {
        count ++;
        tab[2] = j + 1;
        j ++;
    }

    if(b.get_Board(tab[1], tab[2]) == player) tab[0] = count;
    return tab;

}

tabcount play::searchColU(const tabmove& m, int player, board b) const
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

tabcount play::searchColD(const tabmove& m, int player, board b) const
{
    int count = 0;
    tabcount tab;
    tab.fill(0);
    tab[2] = m[1];
    // test if the move can be valid in a column by looking at the direct neighbours (cf rules)
    if(m[0] == SIZE - 1 || b.get_Board(m[0] + 1, m[1]) == FREE || b.get_Board(m[0] + 1, m[1]) == player) return tab;

    int i= m[0] + 1;
    while (b.get_Board(i,m[1]) != player && b.get_Board(i, m[1]) != FREE && i < SIZE)
    {
        count ++;
        tab[1] = i + 1;
        i++;
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
    // test if the move can be valid in a diagonal by looking at the direct neighbours (cf rules)
    if(m[0] == 0 || m[1] == 0 || b.get_Board(m[0]-1, m[1] - 1) == FREE || b.get_Board(m[0]-1, m[1] - 1) == player) return tab;
    int i = m[0];
    int j = m[1];
    while ((i > 0) && (j > 0))
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
    // test if the move can be valid in a diagonal by looking at the direct neighbours (cf rules)
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
    // test if the move can be valid in a diagonal by looking at the direct neighbours (cf rules)
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
    // test if the move can be valid in a diagonal by looking at the direct neighbours (cf rules)
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

    if((searchLineL(m, player, b)[0] != 0 || searchLineR(m, player, b)[0] != 0 || searchColD(m, player, b)[0] != 0 || searchColU(m, player, b)[0] != 0
    || searchDiagRD(m, player, b)[0] != 0 || searchDiagLU(m, player, b)[0] != 0 || searchDiagLD(m, player, b)[0] != 0 || searchDiagRU(m, player, b)[0] != 0)
    && b.get_Board(m[0], m[1]) == FREE)
    {
        cout << "Trop fort !" << endl;
        return true;
    }
    else
    {
        cout << "Nul" << endl;
        cout << "tabLL" << searchLineL(m, player, b)[0] << searchLineL(m, player, b)[1] << searchLineL(m, player, b)[2] << endl;
        cout << "tabLR" << searchLineR(m, player, b)[0] << searchLineR(m, player, b)[1] << searchLineR(m, player, b)[2] << endl;
        cout << "tabCD" <<  searchColD(m, player, b)[0] << searchColD(m, player, b)[1] << searchColD(m, player, b)[2] << endl;
        cout << "tabCU" << searchColU(m, player, b)[0] << searchColU(m, player, b)[1] << searchColU(m, player, b)[2] << endl;
        cout << "tabDRD" << searchDiagRD(m, player, b)[0] << searchDiagRD(m, player, b)[1] << searchDiagRD(m, player, b)[2] << endl;
        cout << "tabDLU" << searchDiagLU(m, player, b)[0] << searchDiagLU(m, player, b)[1] << searchDiagLU(m, player, b)[2] << endl;
        cout << "tabDLD" << searchDiagLD(m, player, b)[0] << searchDiagLD(m, player, b)[1] <<searchDiagLD(m, player, b)[2] << endl;
        cout << "tabDRU" << searchDiagRU(m, player, b)[0] << searchDiagRU(m, player, b)[1] << searchDiagRU(m, player, b)[2] << endl;
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
    tabcount tab;

    tab = searchLineL(m, player, b);
    cout << "tabLL : " << tab[0] << tab[1] << tab[2] << endl;
   // cout << "searchLineL : " << searchLineL(m, player, b)[0] << searchLineL(m, player, b)[1] << searchLineL(m, player, b)[2] << endl;
    if(tab[0] != 0)
    {
        for(j = m[1]; j > tab[2]; j--)
            b.set_Board(m[0], j, player);
    }

    tab = searchLineR(m, player, b);
    cout << "tabLR : " << tab[0] << tab[1] << tab[2] << endl;
  //  cout << "searchLineR : " << searchLineR(m, player, b)[0] << searchLineR(m, player, b)[1] << searchLineR(m, player, b)[2] << endl;
    if(tab[0] != 0)
    {
        for (j = m[1]; j < tab[2]; j++)
            b.set_Board(m[0], j, player);
    }

    tab = searchColD(m, player, b);
    cout << "tabCD : " << tab[0] << tab[1] << tab[2] << endl;
 //   cout << "searchColD : " << searchColD(m, player, b)[0] << searchColD(m, player, b)[1] << searchColD(m, player, b)[2] << endl;
    if(tab[0] != 0)
    {
        for(int i = m[0]; i < tab[1]; i++)
            b.set_Board(i, m[1], player);
    }

    tab = searchColU(m, player, b);
    cout << "tabCU : " << tab[0] << tab[1] << tab[2] << endl;
  //  cout << "searchColU : " << searchColU(m, player, b)[0] << searchColU(m, player, b)[1] << searchColU(m, player, b)[2] << endl;
    if(tab[0] != 0)
    {
        for(i = m[0]; i > tab[1]; i--)
            b.set_Board(i, m[1], player);
    }


    tab = searchDiagRD(m, player, b);
    cout << "tabDRD : " << tab[0] << tab[1] << tab[2] << endl;
  //  cout << "searchDiagRD : " << searchDiagRD(m, player, b)[0] << searchDiagRD(m, player, b)[1] << searchDiagRD(m, player, b)[2] << endl;
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

    tab = searchDiagLD(m, player, b);
    cout << "tabDLD : " << tab[0] << tab[1] << tab[2] << endl;
//    cout << "searchDiagLD : " << searchDiagLD(m, player, b)[0] << searchDiagLD(m, player, b)[1] << searchDiagLD(m, player, b)[2] << endl;
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


    tab = searchDiagRU(m, player, b);
    cout << "tabDRU : " << tab[0] << tab[1] << tab[2] << endl;
 //   cout << "searchDiagRU : " << searchDiagRU(m, player, b)[0] << searchDiagRU(m, player, b)[1] << searchDiagRU(m, player, b)[2] << endl;
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


    tab = searchDiagLU(m, player, b);
    cout << "tabDLU : " << tab[0] << tab[1] << tab[2] << endl;
 //   cout << "searchDiagLU : " << searchDiagLU(m, player, b)[0] << searchDiagLU(m, player, b)[1] << searchDiagLU(m, player, b)[2] << endl;
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

    disp.display::print_board_term(b);
    return b;
}








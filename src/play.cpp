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

int * play::ask_move(int *m)
{
    cout << "Entrez ligne et colonne" << endl;
    cin >> m[0] ;
    cin >> m[1] ;

    return m;
}

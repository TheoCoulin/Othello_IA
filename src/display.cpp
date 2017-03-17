#include "display.h"
#include <iostream>

using namespace std;

display::display()
{
    //ctor
}

display::~display()
{
    //dtor
}

void display::print_board_term(board b)
{

    cout << "       0   1   2   3   "<< endl;
    cout << "     +---------------+"<< endl;

    for (int i = 0; i < SIZE; i++) {
        cout << "   " << i << " |" ;
        for (int j = 0; j < SIZE; j++) {
            if(b.get_Board(i, j) == FREE) cout << "   |" ;
            if(b.get_Board(i, j) == WHITE) cout << " O |" ;
            if(b.get_Board(i, j) == BLACK) cout << " X |" ;
        }
        cout << endl;
        cout << "     +---------------+"<< endl;
    }

}

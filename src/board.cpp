#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

board::board()
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == 0 || i == 3 || j == 0 || j == 3) game_board[i][j] = FREE;
            else if (i == j) game_board[i][j] = BLACK;
            else game_board[i][j] = WHITE;
        }
    }
}

board::~board()
{
    //dtor
}

int board::get_Board(int i, int j)
{
    return game_board[i][j];
}

void board::set_Board(int i, int j, int value)
{
    game_board[i][j] = value;
}

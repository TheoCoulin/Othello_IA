#include "game.h"
#include <iostream>

using namespace std;

moves mo;

game::game()
{
    // The first player is always Black pieces
    player = BLACK;
}

game::~game()
{
    //dtor
}

void game::game_loop()
{
    cout << "For each move, enter first the row, then the column" << endl;
    cout << endl;

    disp.print_board_term(b);
    tabmove mov;

    // While one of the players can play, the game continues
    while(!end_of_game(WHITE) || !end_of_game(BLACK))
    {   

        // Clock to see how much time it takes to get the moves
        clock_t start;
        double duration;
        start = clock();    

        list<tabmove> possibleMoves = mo.get_Moves(b, player);

        duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
        cout << "Number of moves available : " << mo.nb_Possible_Moves(b, player) << endl;
        cout << "time to get moves : " << duration << " sec" << endl;
        // 10e-4 seconds average, to get all the possible moves.

        cout << "number of blacks : " << b.number_pieces(BLACK) << endl;
        cout << "number of whites : " << b.number_pieces(WHITE) << endl;
        cout << "it's your turn ";
        if(get_Player() == 1) cout << "black" << endl;
        else cout << "white" << endl;

        mov.fill(0);
        
        // Loop to get a valid move from the human player
        if (player == BLACK)
        {
            do
            {
                mo.ask_move(mov);
                if(! mo.isValidMove(mov, get_Player(), b)) cout << "Try again" << endl;
            } while (! mo.isValidMove(mov, get_Player(), b));
    
        }
        else 
        {
            mov = p.findBestMove(mo, b, player);
        }
        
        cout << "mov[0] : " << mov[0] << "   , mov[1] : " << mov[1] << endl;
        // When we have a valid move in the array mov, we update the board
        updateBoard(mov);
        b.nbPiecesPlayed++;

        // Then we print the board using the display
        disp.print_board_term(b);

        //Then, we switch the player, only if the player to come has a valid move
        if (!end_of_game(opposite_Player())) switch_player();
    } // End of the game loop

    // Here the game is finished, we print the final number of pieces for each player
    cout << "number of blacks: " << b.number_pieces(BLACK) << endl;
    cout << "number of whites: " << b.number_pieces(WHITE) << endl;
    // Here we determine the winner and print it
    winner();
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
void game::updateBoard(const tabmove& m)
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

board game::getBoard()
{
    return b;
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

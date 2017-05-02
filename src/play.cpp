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



/*********************************
*   Function that return the best
*   possible move of the AI.
**********************************/ 


tabmove play::findBestMove(moves mo, board b, int player)
{
	list<tabmove> possibleMoves = mo.get_Moves(b,player); 

    int bestValue = -9000;
    tabmove bestmove = {-1,-1};
    board undo = b;

    for (tabmove m : possibleMoves)
    {   
        // Make the move
        b.set_Board(m[0], m[1], player);

        /*****************************************************
        *   Evaluate the move using the minimax function
        *   depth is 0 because we use this function to start
        *   the minimax, and false because we call this
        *   function when the ai plays, which means the next
        *   move will be made by the minimizing player 
        *****************************************************/
        int moveValue =  evaluate(mo, b); // = minimax(b, 0, false);

        // Undo the move we just did, care, this might use a lot of memory space
        // Do we have a copy of the gameboard or the gameboard itself ?
        // Cause we might not even need to undo, if we do not touch the game board but a copy of itself
        b = undo;    

        /************************************
        *   If the value we just calculated
        *   is better than the previous 
        *   best value, we update it and 
        *   make the current move as the new
        *   best move.
        *************************************/
        if (moveValue > bestValue) 
        {
            bestmove = m;
            bestValue = moveValue;
        }
    }

    cout << "Best move evaluation is : " << bestValue << endl;
    cout << "Coordinates :" << endl;
    cout << "   - i : " << bestmove[0] << endl;
    cout << "   - j : " << bestmove[1] << endl;

    return bestmove;
}


/****************************
*	Main AI function,
*	using minimax algorithm
****************************/

int play::minimax(board b, int depth, bool isMaxPlayer)
{

}

/**************************
*	Heuristics function.
*	We consider that the 
*	ai plays the white 
*	pieces.
**************************/
int play::evaluate(moves mo, board b)
{
	int score = 0;

	// Number of black pieces
	int nbBlack = b.number_pieces(BLACK);
	// Number of white pieces
	int nbWhite = b.nbPiecesPlayed - nbBlack;

	int parity;
	int actualMobility = 0;
	
	// Number of available moves for each player
	int nbBlackMoves = mo.nb_Possible_Moves(b, BLACK);
	int nbWhiteMoves = mo.nb_Possible_Moves(b, WHITE);

	// Coin parity : difference between white and black pieces 
	parity = 100 * (nbWhite - nbBlack) / (b.nbPiecesPlayed);

	// Actual Mobility : diff between nb of white moves and black moves
	// If ther is at least one move available (to avoid dividing by 0)
	if (nbBlackMoves + nbWhiteMoves != 0)
	{
		actualMobility = 100 * (nbWhiteMoves - nbBlackMoves) / (nbWhiteMoves + nbBlackMoves);
	}

	score = parity;
} 
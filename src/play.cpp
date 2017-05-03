#include "play.h"
#include <iostream>
#include <algorithm>

using namespace std;

play::play()
{
    //ctor
}

play::~play()
{
    //dtor
}


/*****************
* Game loop here.
*
******************/
void play::game_loop()
{
    cout << "For each move, enter first the row, then the column" << endl;
    cout << endl;

    g.disp.print_board_term(g.b);
    tabmove mov;

    // While one of the players can play, the game continues
    while(!g.end_of_game(WHITE) || !g.end_of_game(BLACK))
    {   
        /*
        // Clock to see how much time it takes to get the moves
        clock_t start;
        double duration;
        start = clock();    

        list<tabmove> possibleMoves = g.mo.get_Moves(b, player);

        duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
        cout << "Number of moves available : " << mo.nb_Possible_Moves(b, player) << endl;
        cout << "time to get moves : " << duration << " sec" << endl;
        // 10e-4 seconds average, to get all the possible moves.
        */
        cout << "number of blacks : " << g.b.number_pieces(BLACK) << endl;
        cout << "number of whites : " << g.b.number_pieces(WHITE) << endl;
        cout << "it's your turn ";
        if(g.get_Player() == 1) cout << "black" << endl;
        else cout << "white" << endl;

        mov.fill(0);
        
        // Loop to get a valid move from the human player
        if (g.player == BLACK)
        {
            do
            {
                g.mo.ask_move(mov);
                if(! g.mo.isValidMove(mov, g.get_Player(), g.b)) cout << "Try again" << endl;
            } while (! g.mo.isValidMove(mov, g.get_Player(), g.b));
    
        }
        else 
        {
          /******************************
          *   Timer to see how much time 
          *   is spent calculating the 
          *   next move made by the ai.
          *******************************/
          clock_t start;
          double duration;
          start = clock();
          
          mov = findBestMove(g);

          duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
          cout << "Time spent by the ai : " << duration << " sec" << endl;
        }
        
        //cout << "mov[0] : " << mov[0] << "   , mov[1] : " << mov[1] << endl;
        // When we have a valid move in the array mov, we update the board
        g.updateBoard(mov);
        g.b.nbPiecesPlayed++;

        // Then we print the board using the display
        g.disp.print_board_term(g.b);

        //Then, we switch the player, only if the player to come has a valid move
        if (!g.end_of_game(g.opposite_Player())) g.switch_player();
    } // End of the game loop

    // Here the game is finished, we print the final number of pieces for each player
    cout << "number of blacks: " << g.b.number_pieces(BLACK) << endl;
    cout << "number of whites: " << g.b.number_pieces(WHITE) << endl;
    // Here we determine the winner and print it
    g.winner();
}



/*********************************
*   Function that return the best
*   possible move of the AI.
**********************************/ 


tabmove play::findBestMove(game g)
{
  //cout << "IN findBestMove" << endl << endl; // DEBUG

	list<tabmove> possibleMoves = g.mo.get_Moves(g.b,g.player); 

  int bestValue = -9000;
  tabmove bestmove = {-1,-1};
  board undo = g.b;
  bool playerswapped = false;

  for (tabmove m : possibleMoves)
  {   
      // Make the move and switch the player if necessary
      g.updateBoard(m);
      if (!g.end_of_game(g.opposite_Player())) 
      {
        g.switch_player();
        playerswapped = true;

      }  

      // Debug output
      /*
      g.disp.print_board_term(g.b);
      cout << "Current move tested :" << endl;
      cout << "	- i = " << m[0] << endl;
      cout << "	- j = " << m[1] << endl << endl;
      */

      /*****************************************************
      *   Evaluate the move using the minimax function
      *   depth is 0 because we use this function to start
      *   the minimax, and false because we call this
      *   function when the ai plays, which means the next
      *   move will be made by the minimizing player 
      *****************************************************/
      int moveValue = alphabeta(g, 4, -99999, 99999); // = evaluate(mo, b);  

      // Undo the move we just did, care, this might use a lot of memory space
      // Do we have a copy of the gameboard or the gameboard itself ?
      // Cause we might not even need to undo, if we do not touch the game board but a copy of itself
      g.b = undo;
      if (playerswapped) g.switch_player();

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

int play::minimax(game g, int depth)
{
  //cout << "In minimax !" << endl << endl; // DEBUG
  //cout << "depth = " << depth << endl; // DEBUG
  list<tabmove> liste;
  int res;
  tabmove tab;
  board undo = g.b;
  bool playerswapped;

  if(depth == 0 || g.winner() != -100) 
  {
    //if (g.player == WHITE) cout << "Last move played by min" << endl; //DEBUG
    //disp.print_board_term(g.b); // DEBUG
    return evaluate(g.mo, g.b);
  }
  else
  {
    //Calcul des moves possibles pour le joueur courant
    if (g.player == WHITE) // Max player 
    {
      //cout << "Max player" << endl; // DEBUG
      liste = g.mo.get_Moves(g.b, WHITE);
      res = -9999999;
    }
    else 
    {
      //cout << "Min player" << endl; // DEBUG
      liste = g.mo.get_Moves(g.b, BLACK);
      res = 9999999;
    }
    //cout << "Number of moves to play from this board : " << liste.size() << endl; // DEBUG
    for (tabmove m : liste)
    {
      //cout << "m[0] : " << m[0] << ", m[1] : " << m[1] <<endl; // DEBUG
      
      g.updateBoard(m);
      if (g.player == WHITE) // Max player 
      {
        if (!g.end_of_game(g.opposite_Player()))
        {
          g.switch_player();
          playerswapped = true;
        }
        res = max(res, minimax(g, depth-1));
        //cout << "max value selected : " << res << endl; // DEBUG
      }
      else
      {
        if (!g.end_of_game(g.opposite_Player()))
        {
          g.switch_player();
          playerswapped = true;
        }
        res = min(res, minimax(g, depth-1));
        //cout << "Min value selected : " << res << endl; // DEBUG
      }
      
      g.b = undo;
      if (playerswapped) g.switch_player();  
    }
  }
  
  return res;
}

/*****************************
* AI using alpha-beta pruning
******************************/

int play::alphabeta(game g, int depth, int alpha, int beta)
{
  list<tabmove> liste;
  int res;
  tabmove tab;
  board undo = g.b;
  bool playerswapped;

  if(depth == 0 || g.winner() != -100) 
  {
    //if (g.player == WHITE) cout << "Last move played by min" << endl; //DEBUG
    //disp.print_board_term(g.b); // DEBUG
    return evaluate(g.mo, g.b);
  }
  else
  {
    //Calcul des moves possibles pour le joueur courant
    if (g.player == WHITE) // Max player 
    {
      //cout << "Max player" << endl; // DEBUG
      liste = g.mo.get_Moves(g.b, WHITE);
      res = -9999999;
    }
    else 
    {
      //cout << "Min player" << endl; // DEBUG
      liste = g.mo.get_Moves(g.b, BLACK);
      res = 9999999;
    }
    //cout << "Number of moves to play from this board : " << liste.size() << endl; // DEBUG
    for (tabmove m : liste)
    {
      //cout << "m[0] : " << m[0] << ", m[1] : " << m[1] <<endl; // DEBUG
      
      g.updateBoard(m);
      if (g.player == WHITE) // Max player 
      {
        if (!g.end_of_game(g.opposite_Player()))
        {
          g.switch_player();
          playerswapped = true;
        }
        res = max(res, alphabeta(g, depth-1, alpha, beta));
        alpha = res;
        if (beta <= alpha) 
        { 
          cout << "Cutoff !" << endl;
          break; // Cut-off : Stops the foreach execution
        }
      }
      else
      {
        if (!g.end_of_game(g.opposite_Player()))
        {
          g.switch_player();
          playerswapped = true;
        }
        res = min(res, minimax(g, depth-1));
        beta = res;
        if (beta <= alpha) break; // Cut-off : Stops the foreach execution
      }
      
      g.b = undo;
      if (playerswapped) g.switch_player();  
    }
  }
  
  return res;
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
	//cout << "nb of black moves : " << nbBlackMoves << endl; // DEBUG
	int nbWhiteMoves = mo.nb_Possible_Moves(b, WHITE);
	//cout << "nb of white moves : " << nbWhiteMoves << endl; // DEBUG


	// Coin parity : difference between white and black pieces 
	parity = 100 * (nbWhite - nbBlack) / (b.nbPiecesPlayed);

	// Actual Mobility : diff between nb of white moves and black moves
	// If ther is at least one move available (to avoid dividing by 0)
	if (nbBlackMoves + nbWhiteMoves != 0)
	{
		actualMobility = 100 * (nbWhiteMoves - nbBlackMoves) / (nbWhiteMoves + nbBlackMoves);
	}



	score = parity + actualMobility;
	//cout << "Score for this move is : " << score << endl; // DEBUG
	return score;
} 


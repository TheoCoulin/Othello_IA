#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "display.h"
#include "moves.h"
//#include "play.h"
#include <list>
#include <ctime>

using namespace std;

class game
{
    public:
        game();
        virtual ~game();

        //void game_loop();
        bool end_of_game(int player);
        int winner();
        
        void updateBoard(const tabmove& m);

        board getBoard();

		int get_Player();
		void switch_player();
		int opposite_Player();        
		
		board b;
		int player;
		display disp;
		moves mo;
		//play p;
		

	private:
};

#endif // GAME_H
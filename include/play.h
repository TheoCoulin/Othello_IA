#ifndef PLAY_H
#define PLAY_H
#include <array>
#include "board.h"
#include "display.h"

class play
{

    public:
        play();
        virtual ~play();
        tabmove ask_move(tabmove& m);
        tabcount searchLineL(const tabmove& m, int player, board b) const;
        tabcount searchLineR(const tabmove& m, int player, board b) const;
        tabcount searchColD(const tabmove& m, int player, board b) const;
        tabcount searchColU(const tabmove& m, int player, board b) const;
        tabcount searchDiagRD(const tabmove& m, int player, board b) const;
        tabcount searchDiagLD(const tabmove& m, int player, board b) const;
        tabcount searchDiagRU(const tabmove& m, int player, board b) const;
        tabcount searchDiagLU(const tabmove& m, int player, board b) const;
        bool isValidMove(const tabmove& m, int player, board b) const;
        void updateBoard(board b, const tabmove& m, int player, display disp);

    protected:

    private:
};

#endif // PLAY_H

#include <iostream>
#include <string>
#include <vector>
#include "tic_tac_toe.h"

using std::string;
using std::vector;

#ifndef tic_tac_toe_4
#define tic_tac_toe_4
class TicTacToe4 : public TicTacToe{
    public:
        TicTacToe4() : TicTacToe(4){};
        void display_board() const override;
    private:
        bool check_column_win() override;
        bool check_row_win() override;
        bool check_diagonal_win() override;
};
#endif

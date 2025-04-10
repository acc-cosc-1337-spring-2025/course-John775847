#include <iostream>
#include <string>
#include <vector>
#include "tic_tac_toe.h"

using std::vector;
using std::string;

#ifndef tic_tac_toe_manager
#define tic_tac_toe_manager
class TicTacToeManager{
    public:
        void save_finished_game(TicTacToe game);
        void get_winner_total(int& x, int& o, int& t);
    private:
        vector<TicTacToe> games;
        int x_win = 0;
        int o_win = 0;
        int ties = 0;
        void update_winner_count(string winner);
};
#endif

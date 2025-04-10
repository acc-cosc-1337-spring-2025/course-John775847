#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

#ifndef tic_tac_toe
#define tic_tac_toe
class TicTacToe{
    public:
        bool game_over();
        void start_game(string first_player);
        bool mark_board(int position);
        string get_player() const{return player;};
        void display_board() const;
        string get_winner();
    private:
        bool check_column_win();
        bool check_row_win();
        bool check_diagonal_win();
        void set_winner();
        void set_next_player();
        bool check_board_full();
        void clear_board();
        vector<string> pegs{9, " "};
        string player;
        string winner = "none";
};
#endif

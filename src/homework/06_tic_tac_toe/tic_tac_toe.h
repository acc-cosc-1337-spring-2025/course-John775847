#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

#ifndef tic_tac_toe
#define tic_tac_toe
class TicTacToe{
    protected:
        vector<string> board;
        virtual bool check_column_win() = 0;
        virtual bool check_row_win() = 0;
        virtual bool check_diagonal_win() = 0;
    public:
        TicTacToe(size_t size) : board{size*size, " "} {
        }
        bool game_over();
        void start_game(string first_player);
        bool mark_board(int position);
        string get_player() const{return player;}
        virtual void display_board() const = 0;
        string get_winner();
    private:
        void set_winner();
        void set_next_player();
        bool check_board_full();
        void clear_board();
        string player;
        string winner = "none";
};
#endif

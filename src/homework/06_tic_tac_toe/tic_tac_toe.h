#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class TicTacToe{
    public:
        vector<string> pegs{9, " "};
        bool game_over();
        void start_game(string first_player);
        void mark_board(int position);
        string get_player() const{return player;};
        void display_board() const;
    private:
        void set_next_player();
        bool check_board_full();
        void clear_board();
        string player;
};

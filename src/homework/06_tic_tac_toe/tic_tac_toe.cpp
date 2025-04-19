#include <string>
#include "tic_tac_toe.h"

using std::string;

//-------------Public-------------//
bool TicTacToe::game_over(){
    if (check_column_win() || check_row_win() || check_diagonal_win()){
        set_winner();
        return true;
    }else if (check_board_full()){
        winner = "none";
        return true;
    }else{
        return false;
    }
}

void TicTacToe::start_game(string first_player){
    player = first_player;
    clear_board();
}

bool TicTacToe::mark_board(int position){
    if(board[position-1] == " "){
        board[position-1] = player;
        set_next_player();
        return true;
    }else{
        return false;
    }
}

string TicTacToe::get_winner(){
    return winner;
}

//-------------Private-------------//
void TicTacToe::set_winner(){
    if (player == "X"){
        winner = "O";
    }else{
        winner = "X";
    }
}

void TicTacToe::set_next_player(){
    if(player == "X" || player == "none"){
        player = "O";
    }else{
        player = "X";
    }
}

bool TicTacToe::check_board_full(){
    for(string& peg: board){
        if (peg == " "){
            return false;
        }
    }
    return true;
}

void TicTacToe::clear_board(){
    for(string& peg: board){
        peg = " ";
    }
}

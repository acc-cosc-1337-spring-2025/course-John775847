#include <iostream>
#include <string>
#include "tic_tac_toe.h"

using std::string;
using std::cout;

//-------------Public-------------//
bool TicTacToe::game_over(){
    if (TicTacToe::check_column_win() || TicTacToe::check_row_win() || TicTacToe::check_diagonal_win()){
        TicTacToe::set_winner();
        return true;
    }else if (TicTacToe::check_board_full()){
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
    if(pegs[position-1] == " "){
        pegs[position-1] = player;
        set_next_player();
        return true;
    }else{
        return false;
    }
}

void TicTacToe::display_board() const{
    cout<<"\n";
    cout<<pegs[0]<<" | "<<pegs[1]<<" | "<<pegs[2]<<"\n";
    cout<<"---------\n";
    cout<<pegs[3]<<" | "<<pegs[4]<<" | "<<pegs[5]<<"\n";
    cout<<"---------\n";
    cout<<pegs[6]<<" | "<<pegs[7]<<" | "<<pegs[8]<<"\n";
}

string TicTacToe::get_winner(){
    return winner;
}

//-------------Private-------------//
bool TicTacToe::check_column_win(){
    if (pegs[0] == pegs[3] && pegs[0] == pegs[6] && pegs[0] != " "){
        return true;
    }else if(pegs[1] == pegs[4] && pegs[1] == pegs[7] && pegs[1] != " "){
        return true;
    }else if(pegs[2] == pegs[5] && pegs[2] == pegs[8] && pegs[2] != " "){
        return true;
    }
    return false;
}

bool TicTacToe::check_row_win(){
    if (pegs[0] == pegs[1] && pegs[0] == pegs[2] && pegs[0] != " "){
        return true;
    }else if(pegs[3] == pegs[4] && pegs[3] == pegs[5] && pegs[3] != " "){
        return true;
    }else if(pegs[6] == pegs[7] && pegs[6] == pegs[8] && pegs[6] != " "){
        return true;
    }
    return false;
}

bool TicTacToe::check_diagonal_win(){
    if (pegs[0] == pegs[4] && pegs[0] == pegs[8] && pegs[0] != " "){
        return true;
    }else if(pegs[2] == pegs[4] && pegs[2] == pegs[6] && pegs[2] != " "){
        return true;
    }
    return false;
}

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
    for(string& peg: pegs){
        if (peg == " "){
            return false;
        }
    }
    return true;
}

void TicTacToe::clear_board(){
    for(string& peg: pegs){
        peg = " ";
    }
}

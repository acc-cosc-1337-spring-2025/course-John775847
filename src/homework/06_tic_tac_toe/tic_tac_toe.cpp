#include <iostream>
#include <string>
#include "tic_tac_toe.h"

using std::string;
using std::cout;

//-------------Public-------------//
bool TicTacToe::game_over(){
    return TicTacToe::check_board_full();
}

void TicTacToe::start_game(string first_player){
    player = first_player;
    clear_board();
}

void TicTacToe::mark_board(int position){
    pegs[position-1] = player;
    set_next_player();
}

void TicTacToe::display_board() const{
    // cout<<"\n";
    // for(int i = 0; i < 9; i += 3){
    //     for(int i2 = 0; i2 < 3; i2++){
    //         cout << pegs[i2+i] << " | ";
    //     }
    //     cout<<"\n"
    // }
    // cout<<"\n";

    cout<<"\n";
    cout<<pegs[0]<<" | "<<pegs[1]<<" | "<<pegs[2]<<"\n";
    cout<<"---------\n";
    cout<<pegs[3]<<" | "<<pegs[4]<<" | "<<pegs[5]<<"\n";
    cout<<"---------\n";
    cout<<pegs[6]<<" | "<<pegs[7]<<" | "<<pegs[8]<<"\n";
    //This looks better.
}

//-------------Private-------------//
void TicTacToe::set_next_player(){
    if(player == "X"){
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

#include <iostream>
#include "tic_tac_toe_3.h"

using std::cout;


bool TicTacToe3::check_column_win(){
    if (board[0] == board[3] && board[0] == board[6] && board[0] != " "){
        return true;
    }else if(board[1] == board[4] && board[1] == board[7] && board[1] != " "){
        return true;
    }else if(board[2] == board[5] && board[2] == board[8] && board[2] != " "){
        return true;
    }else{
        return false;
    }
}

bool TicTacToe3::check_row_win(){
    if (board[0] == board[1] && board[0] == board[2] && board[0] != " "){
        return true;
    }else if(board[3] == board[4] && board[3] == board[5] && board[3] != " "){
        return true;
    }else if(board[6] == board[7] && board[6] == board[8] && board[6] != " "){
        return true;
    }else{
        return false;
    }
}

bool TicTacToe3::check_diagonal_win(){
    if (board[0] == board[4] && board[0] == board[8] && board[0] != " "){
        return true;
    }else if(board[2] == board[4] && board[2] == board[6] && board[2] != " "){
        return true;
    }else{
        return false;
    }
}

void TicTacToe3::display_board() const{
    cout<<"\n";
    cout<<board[0]<<" | "<<board[1]<<" | "<<board[2]<<"\n";
    cout<<"---------\n";
    cout<<board[3]<<" | "<<board[4]<<" | "<<board[5]<<"\n";
    cout<<"---------\n";
    cout<<board[6]<<" | "<<board[7]<<" | "<<board[8]<<"\n";
}

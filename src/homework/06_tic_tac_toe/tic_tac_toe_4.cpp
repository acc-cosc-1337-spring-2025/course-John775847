#include <iostream>
#include "tic_tac_toe_4.h"

using std::cout;

bool TicTacToe4::check_column_win(){
    if (board[0] == board[4] && board[0] == board[8] && board[0] == board[12] && board[0] != " "){
        return true;
    }else if(board[1] == board[5] && board[1] == board[9] && board[1] == board[13] && board[1] != " "){
        return true;
    }else if(board[2] == board[6] && board[2] == board[10] && board[2] == board[14] && board[2] != " "){
        return true;
    }else if(board[3] == board[7] && board[3] == board[11] && board[3] == board[15] && board[3] != " "){
        return true;
    }else{
        return false;
    }
}

bool TicTacToe4::check_row_win(){
    if (board[0] == board[1] && board[0] == board[2] && board[0] == board[3] && board[0] != " "){
        return true;
    }else if(board[4] == board[5] && board[4] == board[6] && board[4] == board[7] && board[4] != " "){
        return true;
    }else if(board[8] == board[9] && board[8] == board[10] && board[8] == board[11] && board[8] != " "){
        return true;
    }else if(board[12] == board[13] && board[12] == board[14] && board[12] == board[15] && board[12] != " "){
        return true;
    }else{
        return false;
    }
}

bool TicTacToe4::check_diagonal_win(){
    if (board[0] == board[5] && board[0] == board[10] && board[0] == board[15] && board[0] != " "){
        return true;
    }else if(board[3] == board[6] && board[3] == board[9] && board[3] == board[12] && board[3] != " "){
        return true;
    }else{
        return false;
    }
}

void TicTacToe4::display_board() const{
    cout<<"\n";
    cout<<board[0]<<" | "<<board[1]<<" | "<<board[2]<<" | "<<board[3]<<"\n";
    cout<<"-------------\n";
    cout<<board[4]<<" | "<<board[5]<<" | "<<board[6]<<" | "<<board[7]<<"\n";
    cout<<"-------------\n";
    cout<<board[8]<<" | "<<board[9]<<" | "<<board[10]<<" | "<<board[11]<<"\n";
    cout<<"-------------\n";
    cout<<board[12]<<" | "<<board[13]<<" | "<<board[14]<<" | "<<board[15]<<"\n";
}

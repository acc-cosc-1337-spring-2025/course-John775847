#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"
#include<iostream>
#include<string>

using std::string;
using std::cin;
using std::cout;
using std::make_unique;
using std::unique_ptr;
using std::move;

int main() {
    unique_ptr<TicTacToe> game;
	TicTacToeManager manager;

	while(true){
        //ask for game type
        while(true){
            string tictactoe_type_choice;
            cout<<"Will you play tic tac toe 3x3 or 4x4? (3 or 4)\n";
            cin>>tictactoe_type_choice;

            if(tictactoe_type_choice == "4"){
                game = make_unique<TicTacToe4>();
                break;
            }else if(tictactoe_type_choice == "3"){
                game = make_unique<TicTacToe3>();
                break;
            }else{
                cout<<"Try again\n";
                continue;
            }
        }

        //ask for player type
        while(true){
            string question_X_or_O;
            cout<<"\nWill X or O take the first position? (X or O)\n";
            cin>>question_X_or_O;

            if (question_X_or_O == "X" || question_X_or_O == "x"){
                game->start_game("X");
                break;
            }else if(question_X_or_O == "O" || question_X_or_O == "o"){
                game->start_game("O");
                break;
            }else{
                cout<<"\nERROR: wrong letter. Must be X or O\n";
                continue;
            }
        }


        //play the game
        game->display_board();
		int board_size = game->get_board_size();
		while(true){
			int position;
			cout<<"\nEnter a position to mark on the board (1 to "<<board_size<<")\n";
			cin>>position;
            if (position < 1 && position > board_size){
                cout<<"\nERROR: wrong number. Muse be 1 to "<<board_size<<"\n";
                return 3;
            }

            if (!game->mark_board(position)){
                cout<<"\nPosition already taken\n";
                continue;
            }

            game->display_board();
            if (game->game_over()){
				break;
			}
		}
        //display winners
        game->display_board();
		int x_win, o_win, ties;
        manager.save_finished_game(move(game));
        manager.get_winner_total(x_win, o_win, ties);
		cout<<"\nX wins: "<<x_win<<"\nO wins: "<<o_win<<"\nties: "<<ties<<"\n";


        //game over, try again?
		char another_game;
		cout<<"\nAnother game? (Y or N)\n";
		cin>>another_game;
		if (another_game == 'n' || another_game == 'N'){
			break;
		}
		cout<<"\n";
	}

    //display stats
	string display_question;
	cout<<"\nWould you like to see your history of games? (Y or N)\n";
	cin>>display_question;
	if(display_question == "Y" || display_question == "y"){
		manager.display_games();
	}

	return 0;
}

#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"
#include<iostream>
#include<string>

using std::string;
using std::cin;
using std::cout;

int main() {
    std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe3>();
	TicTacToeManager manager;

	while(true){
		char question_X_or_O;
		cout<<"Will X or O take the first position? (X or O)\n";
		cin>>question_X_or_O;

		if (question_X_or_O == 'X' || question_X_or_O == 'x'){
            game->start_game("X");
		}else if(question_X_or_O == 'O' || question_X_or_O == 'o'){
            game->start_game("O");
		}else{
			cout<<"\nERROR: wrong letter. Must be X or O\n";
			return 1;
		}

        game->display_board();
		while(true){
			int position;
			cout<<"\nEnter a position to mark on the board (1 through 9)\n";
			cin>>position;
			if (position >= 1 && position <= 9){
				while(true){
                    if (game->mark_board(position)){ //The way this works is really funny to me.
						break;
					}else{
						cout<<"\nPosition already taken, try again (1 through 9)\n";
						cin>>position;
						if (!(position >= 1 && position <= 9)){
							cout<<"\nERROR: wrong number. Muse be 1 through 9\n";
							return 3;
						}
					}
				}
			}else{
				cout<<"\nERROR: wrong number. Muse be 1 through 9\n";
				return 3;
			}
            game->display_board();
            if (game->game_over()){
				break;
			}
		}
        game->display_board();
		int x_win, o_win, ties;
        manager.save_finished_game(std::move(game));
        manager.get_winner_total(x_win, o_win, ties);
		cout<<"\nX wins: "<<x_win<<"\nO wins: "<<o_win<<"\nties: "<<ties<<"\n";

		char another_game;
		cout<<"\nAnother game? (Y or N)\n";
		cin>>another_game;
		if (another_game == 'n' || another_game == 'N'){
			break;
		}
		cout<<"\n";
	}
	return 0;
}

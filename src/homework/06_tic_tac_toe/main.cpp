#include "tic_tac_toe.h"
#include<iostream>
#include<string>

using std::string;
using std::cin;
using std::cout;

int main() {
	TicTacToe game;

	while(true){
		char question_X_or_O;
		cout<<"Will X or O take the first position? (X or O)\n";
		cin>>question_X_or_O;

		if (question_X_or_O == 'X' || question_X_or_O == 'x'){
			game.start_game("X");
		}else if(question_X_or_O == 'O' || question_X_or_O == 'o'){
			game.start_game("O");
		}else{
			cout<<"\nERROR: wrong letter. Must be X or O\n";
			return 1;
		}

		game.display_board();
		while(!(game.game_over())){
			int position;
			cout<<"\nEnter a position to mark on the board (1 through 9)\n";
			cin>>position;
			if (position >= 1 && position <= 9){
				if (game.pegs[position-1] == " "){
					game.mark_board(position);
				}else{
					cout<<"\nERROR: position already taken.\n";
					return 2;
				}
			}else{
				cout<<"\nERROR: wrong number. Muse be 1 through 9\n";
				return 3;
			}
			game.display_board();
			char continue_the_game;
			cout<<"\nContinue? (Y or N)\n";
			cin>>continue_the_game;
			if (continue_the_game == 'n'){
				break;
			}
		}
		game.display_board();

		char another_game;
		cout<<"\nAnother game? (Y or N)\n";
		cin>>another_game;
		if (another_game == 'n'){
			break;
		}
		cout<<"\n";
	}
	return 0;
}

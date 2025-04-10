#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("check_board_full"){
	TicTacToe game;
	game.start_game("X");

	game.mark_board(3);
	REQUIRE(game.game_over() == false);
	game.mark_board(2);
	REQUIRE(game.game_over() == false);
	game.mark_board(4);
	REQUIRE(game.game_over() == false);
	game.mark_board(1);
	REQUIRE(game.game_over() == false);
	game.mark_board(5);
	REQUIRE(game.game_over() == false);
	game.mark_board(6);
	REQUIRE(game.game_over() == false);
	game.mark_board(8);
	REQUIRE(game.game_over() == false);
	game.mark_board(7);
	REQUIRE(game.game_over() == false);
	game.mark_board(9);
	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "none");
}

TEST_CASE("Test first player set to X"){
	TicTacToe game;
	game.start_game("X");
	REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test first player set to O"){
	TicTacToe game;
	game.start_game("O");
	REQUIRE(game.get_player() == "O");
}

TEST_CASE("Test win by first column"){
	TicTacToe game;
	game.start_game("X");
	game.mark_board(1);
	REQUIRE(game.game_over() == false);
	game.mark_board(2);
	REQUIRE(game.game_over() == false);

	game.mark_board(4);
	REQUIRE(game.game_over() == false);
	game.mark_board(5);
	REQUIRE(game.game_over() == false);

	game.mark_board(7);
	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by second column"){
	TicTacToe game;
	game.start_game("X");
	game.mark_board(2);
	REQUIRE(game.game_over() == false);
	game.mark_board(1);
	REQUIRE(game.game_over() == false);

	game.mark_board(5);
	REQUIRE(game.game_over() == false);
	game.mark_board(3);
	REQUIRE(game.game_over() == false);

	game.mark_board(8);
	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by third column"){
	TicTacToe game;
	game.start_game("X");
	game.mark_board(3);
	REQUIRE(game.game_over() == false);
	game.mark_board(1);
	REQUIRE(game.game_over() == false);

	game.mark_board(6);
	REQUIRE(game.game_over() == false);
	game.mark_board(2);
	REQUIRE(game.game_over() == false);

	game.mark_board(9);
	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by first row"){
	TicTacToe game;
	game.start_game("X");
	game.mark_board(1);
	REQUIRE(game.game_over() == false);
	game.mark_board(5);
	REQUIRE(game.game_over() == false);

	game.mark_board(2);
	REQUIRE(game.game_over() == false);
	game.mark_board(6);
	REQUIRE(game.game_over() == false);

	game.mark_board(3);
	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by second row"){
	TicTacToe game;
	game.start_game("X");
	game.mark_board(4);
	REQUIRE(game.game_over() == false);
	game.mark_board(1);
	REQUIRE(game.game_over() == false);

	game.mark_board(5);
	REQUIRE(game.game_over() == false);
	game.mark_board(2);
	REQUIRE(game.game_over() == false);

	game.mark_board(6);
	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by third row"){
	TicTacToe game;
	game.start_game("X");
	game.mark_board(7);
	REQUIRE(game.game_over() == false);
	game.mark_board(1);
	REQUIRE(game.game_over() == false);

	game.mark_board(8);
	REQUIRE(game.game_over() == false);
	game.mark_board(2);
	REQUIRE(game.game_over() == false);

	game.mark_board(9);
	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win diagonally from top left"){
	TicTacToe game;
	game.start_game("X");
	game.mark_board(1);
	REQUIRE(game.game_over() == false);
	game.mark_board(2);
	REQUIRE(game.game_over() == false);

	game.mark_board(5);
	REQUIRE(game.game_over() == false);
	game.mark_board(3);
	REQUIRE(game.game_over() == false);

	game.mark_board(9);
	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win diagonally from bottom left"){
	TicTacToe game;
	game.start_game("X");
	game.mark_board(7);
	REQUIRE(game.game_over() == false);
	game.mark_board(2);
	REQUIRE(game.game_over() == false);

	game.mark_board(5);
	REQUIRE(game.game_over() == false);
	game.mark_board(1);
	REQUIRE(game.game_over() == false);

	game.mark_board(3);
	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test Tic Tac Toe Manager"){
	TicTacToeManager manager;
	int x_win, o_win, ties;

	manager.get_winner_total(x_win, o_win, ties);
	REQUIRE(x_win == 0);
	REQUIRE(o_win == 0);
	REQUIRE(ties == 0);

	//Tie
	TicTacToe game;
	game.start_game("X");
	game.mark_board(3);
	REQUIRE(game.game_over() == false);
	game.mark_board(2);
	REQUIRE(game.game_over() == false);
	game.mark_board(4);
	REQUIRE(game.game_over() == false);
	game.mark_board(1);
	REQUIRE(game.game_over() == false);
	game.mark_board(5);
	REQUIRE(game.game_over() == false);
	game.mark_board(6);
	REQUIRE(game.game_over() == false);
	game.mark_board(8);
	REQUIRE(game.game_over() == false);
	game.mark_board(7);
	REQUIRE(game.game_over() == false);
	game.mark_board(9);
	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "none");

	manager.save_finished_game(game);
	manager.get_winner_total(x_win, o_win, ties);
	REQUIRE(x_win == 0);
	REQUIRE(o_win == 0);
	REQUIRE(ties == 1);

	//X
	game = TicTacToe{};
	game.start_game("X");
	game.mark_board(7);
	REQUIRE(game.game_over() == false);
	game.mark_board(2);
	REQUIRE(game.game_over() == false);
	game.mark_board(5);
	REQUIRE(game.game_over() == false);
	game.mark_board(1);
	REQUIRE(game.game_over() == false);
	game.mark_board(3);
	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");

	manager.save_finished_game(game);
	manager.get_winner_total(x_win, o_win, ties);
	REQUIRE(x_win == 1);
	REQUIRE(o_win == 0);
	REQUIRE(ties == 1);

	//O
	game = TicTacToe{};
	game.start_game("O");
	game.mark_board(1);
	REQUIRE(game.game_over() == false);
	game.mark_board(2);
	REQUIRE(game.game_over() == false);
	game.mark_board(5);
	REQUIRE(game.game_over() == false);
	game.mark_board(3);
	REQUIRE(game.game_over() == false);
	game.mark_board(9);
	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "O");

	manager.save_finished_game(game);
	// int x_win, o_win, ties;
	manager.get_winner_total(x_win, o_win, ties);
	REQUIRE(x_win == 1);
	REQUIRE(o_win == 1);
	REQUIRE(ties == 1);
}

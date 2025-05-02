#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"

#include <memory>

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("check_board_full"){
	unique_ptr<TicTacToe> game = std::make_unique<TicTacToe3>();
	game->start_game("X");

	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(4);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(6);
	REQUIRE(game->game_over() == false);
	game->mark_board(8);
	REQUIRE(game->game_over() == false);
	game->mark_board(7);
	REQUIRE(game->game_over() == false);
	game->mark_board(9);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "none");
}

TEST_CASE("Test first player set to X 3x3"){
	unique_ptr<TicTacToe> game = std::make_unique<TicTacToe3>();
	game->start_game("X");
	REQUIRE(game->get_player() == "X");
}

TEST_CASE("Test first player set to O 3x3"){
	unique_ptr<TicTacToe> game = std::make_unique<TicTacToe3>();
	game->start_game("O");
	REQUIRE(game->get_player() == "O");
}

TEST_CASE("Test first player set to X 4x4"){
	unique_ptr<TicTacToe> game = std::make_unique<TicTacToe4>();
	game->start_game("X");
	REQUIRE(game->get_player() == "X");
}

TEST_CASE("Test first player set to O 4x4"){
	unique_ptr<TicTacToe> game = std::make_unique<TicTacToe4>();
	game->start_game("O");
	REQUIRE(game->get_player() == "O");
}

TEST_CASE("Test win by first column 3x3"){
	unique_ptr<TicTacToe> game = std::make_unique<TicTacToe3>();
	game->start_game("X");
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);

	game->mark_board(4);
	REQUIRE(game->game_over() == false);
	game->mark_board(5);
	REQUIRE(game->game_over() == false);

	game->mark_board(7);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by second column 3x3"){
	unique_ptr<TicTacToe> game = std::make_unique<TicTacToe3>();
	game->start_game("X");
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);

	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);

	game->mark_board(8);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by third column 3x3"){
	unique_ptr<TicTacToe> game = std::make_unique<TicTacToe3>();
	game->start_game("X");
	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);

	game->mark_board(6);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);

	game->mark_board(9);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by first column 4x4"){
	unique_ptr<TicTacToe> game = std::make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);

	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(6);
	REQUIRE(game->game_over() == false);

	game->mark_board(9);
	std::cout<<"\n"<<game->get_board_size();
	game->display_board();
	REQUIRE(game->game_over() == false);
	game->mark_board(4);
	REQUIRE(game->game_over() == false);

	game->mark_board(13);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by second column 4x4"){
	unique_ptr<TicTacToe> game = std::make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);

	game->mark_board(6);
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);

	game->mark_board(10);
	REQUIRE(game->game_over() == false);
	game->mark_board(4);
	REQUIRE(game->game_over() == false);

	game->mark_board(14);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by third column 4x4"){
	unique_ptr<TicTacToe> game = std::make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);

	game->mark_board(7);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);

	game->mark_board(11);
	REQUIRE(game->game_over() == false);
	game->mark_board(4);
	REQUIRE(game->game_over() == false);

	game->mark_board(15);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by fourth column 4x4"){
	unique_ptr<TicTacToe> game = std::make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(4);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);

	game->mark_board(8);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);

	game->mark_board(12);
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);

	game->mark_board(16);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by first row 3x3"){
	unique_ptr<TicTacToe> game = std::make_unique<TicTacToe3>();
	game->start_game("X");
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(5);
	REQUIRE(game->game_over() == false);

	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(6);
	REQUIRE(game->game_over() == false);

	game->mark_board(3);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by second row 3x3"){
	unique_ptr<TicTacToe> game = std::make_unique<TicTacToe3>();
	game->start_game("X");
	game->mark_board(4);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);

	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);

	game->mark_board(6);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by third row 3x3"){
	unique_ptr<TicTacToe> game = std::make_unique<TicTacToe3>();
	game->start_game("X");
	game->mark_board(7);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);

	game->mark_board(8);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);

	game->mark_board(9);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by first row 4x4"){
	unique_ptr<TicTacToe> game = std::make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(5);
	REQUIRE(game->game_over() == false);

	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(6);
	REQUIRE(game->game_over() == false);

	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(7);
	REQUIRE(game->game_over() == false);

	game->mark_board(4);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by second row 4x4"){
	unique_ptr<TicTacToe> game = std::make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);

	game->mark_board(6);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);

	game->mark_board(7);
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);

	game->mark_board(8);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by third row 4x4"){
	unique_ptr<TicTacToe> game = std::make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(9);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);

	game->mark_board(10);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);

	game->mark_board(11);
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);

	game->mark_board(12);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by fourth row 4x4"){
	unique_ptr<TicTacToe> game = std::make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(13);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);

	game->mark_board(14);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);

	game->mark_board(15);
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);

	game->mark_board(16);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win diagonally from top left 3x3"){
	unique_ptr<TicTacToe> game = std::make_unique<TicTacToe3>();
	game->start_game("X");
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);

	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);

	game->mark_board(9);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win diagonally from bottom left 3x3"){
	unique_ptr<TicTacToe> game = std::make_unique<TicTacToe3>();
	game->start_game("X");
	game->mark_board(7);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);

	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);

	game->mark_board(3);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win diagonally from top left 4x4"){
	unique_ptr<TicTacToe> game = std::make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);

	game->mark_board(6);
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);

	game->mark_board(11);
	REQUIRE(game->game_over() == false);
	game->mark_board(4);
	REQUIRE(game->game_over() == false);

	game->mark_board(16);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win diagonally from bottom left 4x4"){
	unique_ptr<TicTacToe> game = std::make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(4);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);

	game->mark_board(7);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);

	game->mark_board(10);
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);

	game->mark_board(13);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test Tic Tac Toe Manager"){
	TicTacToeManager manager;
	int x_win, o_win, ties;

	manager.get_winner_total(x_win, o_win, ties);
	REQUIRE(x_win == 0);
	REQUIRE(o_win == 0);
	REQUIRE(ties == 0);

	//Tie
	unique_ptr<TicTacToe> game = std::make_unique<TicTacToe3>();
	game->start_game("X");
	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(4);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(6);
	REQUIRE(game->game_over() == false);
	game->mark_board(8);
	REQUIRE(game->game_over() == false);
	game->mark_board(7);
	REQUIRE(game->game_over() == false);
	game->mark_board(9);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "none");

	manager.save_finished_game(std::move(game));
	manager.get_winner_total(x_win, o_win, ties);
	REQUIRE(x_win == 0);
	REQUIRE(o_win == 0);
	REQUIRE(ties == 1);

	//X
	game = std::make_unique<TicTacToe3>();
	game->start_game("X");
	game->mark_board(7);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");

	manager.save_finished_game(std::move(game));
	manager.get_winner_total(x_win, o_win, ties);
	REQUIRE(x_win == 1);
	REQUIRE(o_win == 0);
	REQUIRE(ties == 1);

	//O
	game = std::make_unique<TicTacToe3>();
	game->start_game("O");
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(9);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "O");

	manager.save_finished_game(std::move(game));
	// int x_win, o_win, ties;
	manager.get_winner_total(x_win, o_win, ties);
	REQUIRE(x_win == 1);
	REQUIRE(o_win == 1);
	REQUIRE(ties == 1);
}

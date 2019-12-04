/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/


TEST(TicTacToeBoardTest, PlaceInBound)
{
	TicTacToeBoard board;

	ASSERT_EQ(board.placePiece(0, 0), X);
}


TEST(TicTacToeBoardTest, PlaceOutOfBounds)
{
	TicTacToeBoard board;

	ASSERT_EQ(board.placePiece(-1, -1), Invalid);
}


TEST(TicTacToeBoardTest, Player)
{
	TicTacToeBoard board;

	board.placePiece(0, 0);
	board.toggleTurn();
	board.getWinner();
	board.placePiece(0, 2);
	board.toggleTurn();
	board.getWinner();

	board.placePiece(1, 0);
	board.toggleTurn();
	board.getWinner();
	board.placePiece(1, 2);
	board.toggleTurn();
	board.getWinner();

	board.placePiece(2, 0);
	board.toggleTurn();
	ASSERT_EQ(board.getWinner(), X);
}


TEST(TicTacToeBoardTest, Player)
{
	TicTacToeBoard board;

	board.placePiece(0, 0);
	board.toggleTurn();
	board.getWinner();
	board.placePiece(0, 2);
	board.toggleTurn();
	board.getWinner();

	board.placePiece(1, 0);
	board.toggleTurn();
	board.getWinner();
	board.placePiece(1, 2);
	board.toggleTurn();
	board.getWinner();

	board.placePiece(2, 1);
	board.toggleTurn();
	ASSERT_EQ(board.getWinner(), Invalid);
}
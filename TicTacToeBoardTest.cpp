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


TEST(TicTacToeBoardTest, PlaceOutInBound)
{
	TicTacToeBoard board;

	ASSERT_EQ(board.placePiece(0, 0), X);
}


TEST(TicTacToeBoardTest, PlaceOutOfBounds)
{
	TicTacToeBoard board;

	ASSERT_EQ(board.placePiece(-1, -1), X);
}
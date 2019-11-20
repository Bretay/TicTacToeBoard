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

TEST(TicTacToeBoardTest, toggleX) {
  TicTacToeBoard ticcy;
  ASSERT_EQ(ticcy.toggleTurn(), Piece::O);
}

TEST(TicTacToeBoardTest, toggleY) {
  TicTacToeBoard ticcy;
  ticcy.toggleTurn();
  ASSERT_EQ(ticcy.toggleTurn(), Piece::X);
}

TEST(TicTacToeBoardTest, placeValidX) {
  TicTacToeBoard ticcy;
  ASSERT_EQ(ticcy.placePiece(0, 0), Piece::X);
}

TEST(TicTacToeBoardTest, placeValidO) {
  TicTacToeBoard ticcy;
  ticcy.placePiece(0, 0);
  ASSERT_EQ(ticcy.placePiece(1, 1), Piece::O);
}

TEST(TicTacToeBoardTest, placeInvalidLessX) {
  TicTacToeBoard ticcy;
  ASSERT_EQ(ticcy.placePiece(-1, -1), Piece::Invalid);
}

TEST(TicTacToeBoardTest, placeInvalidLessO) {
  TicTacToeBoard ticcy;
  ticcy.placePiece(0, 0);
  ASSERT_EQ(ticcy.placePiece(-1, -1), Piece::Invalid);
}

TEST(TicTacToeBoardTest, placeInvalidMoreX) {
  TicTacToeBoard ticcy;
  ASSERT_EQ(ticcy.placePiece(3, 3), Piece::Invalid);
}

TEST(TicTacToeBoardTest, placeInvalidMoreO) {
  TicTacToeBoard ticcy;
  ticcy.placePiece(0, 0);
  ASSERT_EQ(ticcy.placePiece(3, 3), Piece::Invalid);
}

TEST(TicTacToeBoardTest, placeOverX) {
  TicTacToeBoard ticcy;
  ticcy.placePiece(0, 0);
  ticcy.placePiece(1, 1);
  ASSERT_EQ(ticcy.placePiece(1, 1), Piece::O);
}

TEST(TicTacToeBoardTest, placeOverO) {
  TicTacToeBoard ticcy;
  ticcy.placePiece(0, 0);
  ASSERT_EQ(ticcy.placePiece(0, 0), Piece::X);
}

TEST(TicTacToeBoardTest, getValidX) {
  TicTacToeBoard ticcy;
  ticcy.placePiece(0, 0);
  ASSERT_EQ(ticcy.getPiece(0, 0), Piece::X);
}

TEST(TicTacToeBoardTest, getValidO) {
  TicTacToeBoard ticcy;
  ticcy.placePiece(0, 0);
  ticcy.placePiece(1, 1);
  ASSERT_EQ(ticcy.getPiece(1, 1), Piece::O);
}

TEST(TicTacToeBoardTest, getWinnerVerticalX0) {
  TicTacToeBoard ticcy;
  ticcy.placePiece(0, 0);
  ticcy.placePiece(1, 0);
  ticcy.placePiece(0, 1);
  ticcy.placePiece(1, 1);
  ticcy.placePiece(0, 2);
  ASSERT_EQ(ticcy.getWinner(), Piece::X);
}

TEST(TicTacToeBoardTest, getWinnerVerticalO1) {
  TicTacToeBoard ticcy;
  ticcy.placePiece(0, 0);
  ticcy.placePiece(1, 0);
  ticcy.placePiece(2, 1);
  ticcy.placePiece(1, 1);
  ticcy.placePiece(0, 2);
  ticcy.placePiece(1, 2);
  ASSERT_EQ(ticcy.getWinner(), Piece::O);
}

TEST(TicTacToeBoardTest, getWinnerHorizontalX0) {
  TicTacToeBoard ticcy;
  ticcy.placePiece(0, 0);
  ticcy.placePiece(0, 1);
  ticcy.placePiece(1, 0);
  ticcy.placePiece(1, 1);
  ticcy.placePiece(2, 0);
  ASSERT_EQ(ticcy.getWinner(), Piece::X);
}

TEST(TicTacToeBoardTest, getWinnerHorizontalO1) {
  TicTacToeBoard ticcy;
  ticcy.placePiece(0, 0);
  ticcy.placePiece(0, 1);
  ticcy.placePiece(1, 2);
  ticcy.placePiece(1, 1);
  ticcy.placePiece(0, 2);
  ticcy.placePiece(2, 1);
  ASSERT_EQ(ticcy.getWinner(), Piece::O);
}

TEST(TicTacToeBoardTest, getWinnerUnfinished) {
  TicTacToeBoard ticcy;
  ticcy.placePiece(0, 0);
  ticcy.placePiece(1, 1);
  ASSERT_EQ(ticcy.getWinner(), Piece::Invalid);
}

TEST(TicTacToeBoardTest, getWinnerCatsGame) {
  TicTacToeBoard ticcy;
  ticcy.placePiece(0, 0);
  ticcy.placePiece(0, 1);
  ticcy.placePiece(0, 2);
  ticcy.placePiece(1, 0);
  ticcy.placePiece(1, 1);
  ticcy.placePiece(2, 2);
  ticcy.placePiece(2, 1);
  ticcy.placePiece(2, 0);
  ticcy.placePiece(1, 2);
  ASSERT_EQ(ticcy.getWinner(), Piece::Blank);
}

#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if (turn == Piece::X) {
    turn = Piece::O;
  } else {
    turn = Piece::X;
  }
  return turn;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location.
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/
Piece TicTacToeBoard::placePiece(int row, int column)
{
  if (row >= BOARDSIZE || column >= BOARDSIZE || row < 0 || column < 0) {
    toggleTurn();
    return Invalid;
  } else if (getPiece(row, column) != Piece::Blank) {
    toggleTurn();
    return getPiece(row, column);
  } else {
    board[row][column] = turn;
    toggleTurn();
    return getPiece(row, column);
  }
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if (row >= BOARDSIZE || column >= BOARDSIZE || row < 0 || column < 0) {
    return Invalid;
  } else {
    return board[row][column];
  }
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  // Check for unfinished board
  for (int i = 0; i < BOARDSIZE; ++i) {
    for (int j = 0; j < BOARDSIZE; ++j) {
      if (getPiece(i, j) == Piece::Blank) {
        return Piece::Invalid;
      }
    }
  }
  // Check verticals
  for (int i = 0; i < BOARDSIZE, ++i) {
    Piece starter = getPiece(i, 0);
    bool cont = true;
    for (int j = 1; j < BOARDSIZE; ++j) {
      if (starter != getPiece(i, j)) {
        cont = false;
      }
    }
    if (cont) {
      return starter;
    }
  }
  // Check horizontals
  for (int i = 0; i < BOARDSIZE, ++i) {
    Piece starter = getPiece(0, i);
    bool cont = true;
    for (int j = 1; j < BOARDSIZE; ++j) {
      if (starter != getPiece(j, i)) {
        cont = false;
      }
    }
    if (cont) {
      return starter;
    }
  }
  // Check diagonals
  Piece starter = getPiece(0, 0)
  bool cont = true;
  for (int i = 1; i < BOARDSIZE; ++i) {
    if (starter != getPiece(i, i)) {
      cont = false;
    }
  }
  if (cont) {
    return starter;
  }
  starter = getPiece(0, BOARDSIZE);
  cont = true;
  for (int i = 1; i < BOARDSIZE; ++i) {
    if (starter != getPiece(i, BOARDSIZE - i)) {
      cont = false;
    }
  }
  if (cont) {
    return starter;
  }
  return Piece::Blank;
}

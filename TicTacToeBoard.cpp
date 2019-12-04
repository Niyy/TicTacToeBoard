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
  if(turn == X)
  {
    turn = O;
  }
  else
  {
    turn = X;
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
  
  if(getPiece(row, column) == Blank)
  {
    board[row][column] = turn;

    return turn;
  }

  return Invalid;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if((row >= 0 && row < BOARDSIZE) && (column >= 0 && column < BOARDSIZE))
  {
    return board[row][column];
  }

  return Invalid;
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  int toWin = 3;
  int filledBoard = 0;

  for(int y = 0; y < BOARDSIZE; y++)
  {
    toWin = 3;

    for(int x = 0; x < BOARDSIZE; x++)
    {
      if(turn == board[y][x])
      {
        toWin--;
        filledBoard++;
      }
      else
      {
        break;
      }
    }

    if(toWin == 0)
    {
      return turn;
    }
  }


  for(int x = 0; x < BOARDSIZE; x++)
  {
    toWin = 3;

    for(int y = 0; y < BOARDSIZE; y++)
    {
      if(turn == board[y][x])
      {
        toWin--;
        filledBoard++;
      }
      else
      {
        break;
      }
      
    }

    if(toWin == 0)
    {
      return turn;
    }
  }

  
  toWin = 3;

  for(int xy = 0; xy < BOARDSIZE; xy++)
  {
    if(turn == board[xy][xy])
    {
      toWin--;
      filledBoard++;
    }
    else
    {
      break;
    }

    if(toWin == 0)
    {
      return turn;
    }
  }

  toWin = 3;

  for(int xy = 3; xy < BOARDSIZE; xy--)
  {
    if(turn == board[xy][xy])
    {
      toWin--;
      filledBoard++;
    }
    else
    {
      break;
    }

    if(toWin == 0)
    {
      return turn;
    }
  }

  if(filledBoard == 4 && turn == O)
  {
    return Blank
  }

  return Invalid;
}

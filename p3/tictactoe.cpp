// tictactoe.cpp
// implementation file for the TicTacToe class

#include "tictactoe.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

TicTacToe::TicTacToe()
{
  xGamesWon = 0;
  oGamesWon = 0;
  ties = 0;
  
  board = new char*[SIZE];
  for (int i = 0; i < SIZE; i++) {
    board[i] = new char[SIZE];
  }
  
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      board[i][j] = SPACE;
    }
  }
}

TicTacToe::~TicTacToe() {
  for (int i = 0; i < SIZE; i++) {
    delete [] board[i];
  }
  delete [] board;
}

TicTacToe::TicTacToe(const TicTacToe &obj){
  board = new char*[SIZE];
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      board[i][j] = obj.board[i][j];
    }
  }
}

TicTacToe& TicTacToe::operator=(const TicTacToe &obj) {
  if (this != &obj){
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        board[i][j] = obj.board[i][j];
      }
    }
  }
  return *this;
}

void TicTacToe::displayBoard() {    
   cout << endl << endl;    
   for (int i = 0; i < COL_WIDTH - 1; i++)    
      cout << SPACE;    
   for (int i = 0; i < SIZE; i++)    
      cout << setw(COL_WIDTH) << i;    
   cout << endl;    
   for (int r = 0; r < SIZE; r++) {    
      cout << setw(COL_WIDTH) << r;    
      for (int c = 0; c < SIZE; c++)     
         cout << SPACE << board[r][c] << VERTICAL;    
      cout << endl;    
      for (int i = 0; i < SIZE; i++)    
         cout << SPACE;                 
      for (int d = 0; d < SIZE * COL_WIDTH; d++)    
         cout << DASH;                              
      cout << endl;       
   }                   
}

bool TicTacToe::placePiece(char piece, int row, int col) {
  // place piece & validate location (print msg is bad)
  if (board[row][col] == ' ') {
    board[row][col] = piece;
    return true;
  }else {
    cout << "Bad location, try again..." << endl << endl;
    return false;
  }
}

bool TicTacToe::winner(char piece) {
  // checks for winner
  int win;
  int i = 0;
  int j = 0;
  // rows
  while (j < SIZE){
    win = 0;
    for (int i = 0; i < SIZE; i++) {
      if (board[i][j] == piece)
        win++;
    }
    if (win == 3) {
      if (piece == 'X'){
        xGamesWon++;
      }else{
        oGamesWon++;
      }
      cout << piece << " won! Congratulations!" << endl;
      return true;
    }
    j++;
  }
  // columns
  while (i < SIZE){
    win = 0;
    for (int j = 0; j < SIZE; j++) {
      if (board[i][j] == piece)
        win++;
    }
    if (win == 3) {
      if (piece == 'X'){
        xGamesWon++;
      }else{
        oGamesWon++;
      }
      cout << piece << " won! Congratulations!" << endl;
      return true;
    }
    i++;
  }
  // left to right descending
  i = 0;
  j = 0;
  win = 0;
  while (i < SIZE) {
    if (board[i][j] == piece)
      win++;
    i++;
    j++;
  }
  if (win == 3) {
    if (piece == 'X'){
      xGamesWon++;
    }else{
      oGamesWon++;
    }
    cout << piece << " won! Congratulations!" << endl;
    return true;
  }
  // left to right ascending
  win = 0;
  for (int a = 0; a < SIZE; a++) {
    if (board[a][SIZE - 1 - a] == piece)
      win++;
  }
  if (win == 3) {
    if (piece == 'X'){
      xGamesWon++;
    }else{
      oGamesWon++;
    }
    cout << piece << " won! Congratulations!" << endl;
    return true;
  }
  return false;
}

void TicTacToe::resetBoard() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      board[i][j] = SPACE;
    }
  }
}

void TicTacToe::incrementTie() {
  ties++;
}  

void TicTacToe::displayStatistics() {
  cout << endl;
  cout << "Game Stats:" << endl;
  cout << "X has won " << xGamesWon << " games." << endl;
  cout << "O has won " << oGamesWon << " games." << endl;
  cout << "There have been " << ties << " tie games." << endl;
  cout << endl;
}

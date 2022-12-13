// tictactoe.h

#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe {
 public:
  TicTacToe();
  // default constructor
  // precondition: none
  // postcondition: creates a new 2d array for board and initializes board
  ~TicTacToe();
  // deconstructor
  // precondition: none
  // postcondition:
  TicTacToe(const TicTacToe &obj);
  // copy constructor
  // precondition: &obj
  // postcondition: creates a new object and initializes it with data
  //  from board
  TicTacToe& operator=(const TicTacToe &obj);
  // overloaded operator
  // precondition: &obj
  // postcondition: initializes board with data from an object of the
  // same class
  void displayBoard();                            // prints board to screen
  // displays the game board
  // precondition: none
  // postcondition: prints the game board to the screen with X and O
  //  characters or empty spaces depending on what spaces are taken up
  bool placePiece(char piece, int row, int col);  // places X or O on board
  // will place a character from user inpout into empty board spaces
  // precondition: piece, row, col
  // postcondition: changes a location chosen by user on the board array
  //  to the player's charater (X or O)
  bool winner(char piece);             // check rows, cols, diags for piece
  // checks if the game has been won
  // precondition: piece
  // postcondition: checks if there is 3 in a row in the 2d array to check
  //  for a winner
  void resetBoard();
  // resets the board for a new game
  // precondition: none
  // postcondition: resets the locations in the board array to prepare it
  //  for a new game
  void incrementTie();
  // increments ties for the statistics
  // precondition: none
  // postcondition: increments ties integer for game statistics
  void displayStatistics();                     // displays game statistics
  // displays the game statistics
  // precondition: none
  // postcondition: displays the game statistics to the screen
 private:
  char **board; // 2d board array
  static const char SPACE = ' '; // spacer to fill board with blank spaces
  static const char DASH = '-'; // dash for outline of board when printing
  static const int SIZE = 3; // max size of array
  static const int COL_WIDTH = 3; // max size of column for printing board
  static const char VERTICAL = '|'; // line for outline of board when printing
  int xGamesWon; // statistic for number of games X has won
  int oGamesWon; // statistic for number of games O has won
  int ties; // statistic for number of tie games
};

#endif

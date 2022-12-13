// hangman.cpp
// Implementation file for the Hangman class

#include "hangman.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

Hangman::Hangman()
{
   // TODO: initialize all private attributes on the class
   gamesWon = 0;
   gamesLost = 0;
   numWordsRead = 0;
   numWordsAvailable = 0;
   wrongGuesses = 0;
   correctCharacters = 0;

   srand (time(0));
   
   for (int i = 0; i < ALPHA_SIZE; i++){
      alphabet[i].letter = (char)(i+65);
      alphabet[i].isAvailable = true;
   }
   
   // initialize hangman body array
   body[0].firstLine = "    ----\n";                    
   body[1].firstLine = "    |  |\n";                            
   body[2].firstLine = "       |\n";                                  
   body[2].secondLine = "    O  |\n";                              
   body[3].firstLine = "       |\n";                                
   body[3].secondLine = "    |  |\n";                               
   body[4].firstLine = "       |\n";                                 
   body[4].secondLine = "   -|  |\n";                                 
   body[4].thirdLine = "   -|- |\n";                                   
   body[5].firstLine = "       |\n";                                      
   body[5].secondLine = "    |  |\n";                                 
   body[6].firstLine = "       |\n";                                 
   body[6].secondLine = "   /   |\n";                            
   body[6].thirdLine = "   / \\ |\n";                                    
   body[7].firstLine = "       |\n";                                   
   body[8].firstLine = "_______|___\n";                               
   
   // initially set displaySecond and displayThird to false for all body
   // parts. 
   // Note: The default body part printed for all pieces is "firstLine". 
   //       As bad guesses increase, we move down the body to print 
   //       "secondLine" or "thirdLine". 
   for (int i = 0; i < BODY_SIZE; i++){                                
      body[i].displaySecond = false; 
      body[i].displayThird = false;
   }
}

bool Hangman::initializeFile(string filename)
{
   // TODO: initalize file
   ifstream infile;
   // 1. open the file
   infile.open(filename);
   // 2. read the file
   // 3. populate the array of words (use numWordsRead)
   while (infile >> words[numWordsRead].word){
      words[numWordsRead].isAvailable = true;
      numWordsRead++;
   }
   numWordsAvailable = numWordsRead; 
   // 4. close file
   infile.close();
   // 5. return true or false (based on being able to open/read) 
   if (numWordsRead == 0){
      cout << "File problem...press enter to exit...";
      cin.get();
      return false;
   }else{
      return true;
   }
}

void Hangman::displayStatistics()
{
   cout << endl;
   // TODO: display the following statistics
   // - games won
   cout << "Number of games won: " << gamesWon << endl;
   // - games lost
   cout << "Number of games lost: " << gamesLost << endl;
   // - words read from file
   cout << "Number of words read: " << numWordsRead << endl;
   // - words available for play
   cout << "Number of words available for play: " << numWordsAvailable << endl;
   cout << endl;
}

bool Hangman::newWord()
{
   int randomNum;
   if (numWordsAvailable > 0) {
      // TODO: get a new word
      // 1. use random number generator to get an integer between 0-99
      randomNum = rand() % numWordsRead;
      if (words[randomNum].isAvailable == true){
         currentWord = words[randomNum].word;
         words[randomNum].isAvailable = false;
      }else{
         while (words[randomNum].isAvailable != true) {
            randomNum = rand() % numWordsRead;
            // 2. use that integer to get the corresponding index from
            // the word array
            // 3. check if word is available,
            //    - if so assign the word found to currentWord
            //    - if not, find new random integer
            if (words[randomNum].isAvailable == true){
               currentWord = words[randomNum].word;
               words[randomNum].isAvailable = false;
            }
         }
      }
      currentWordSize = currentWord.size();
      // 4. update numWordsAvailable
      numWordsAvailable--;
      
      // reset everything
      for (int i = 0; i < BODY_SIZE; i++){
         body[i].displaySecond = false;
         body[i].displayThird = false;
      }
      wrongGuesses = 0;
      correctCharacters = 0;
      
      for (int i = 0; i < ALPHA_SIZE; i++){
         alphabet[i].isAvailable = true;
      }
      return true;
   }else{
      return false;
   }
}

void Hangman::displayGame()
{
   // TODO: display game
   // 1. display the appropriate body parts (i.e. body array)
   //    - loop through body array
   //    - check if displayThird is true first, then if displaySecond is true
   //    - if neither are true, display firstLine
   cout << endl;
   for (int i = 0; i < BODY_SIZE; i++) {
      if (body[i].displayThird == true){
         cout << body[i].thirdLine;
      }else if (body[i].displaySecond == true) {
         cout << body[i].secondLine;
      }else{
         cout << body[i].firstLine;
      }
   }
   cout << endl;
   // 2. display the word (i.e. initially _ _ _), filling in the letters that
   //    are correctly guessed (i.e. C _ T)
   //    - hint: the number of _ is equal to the length of word
   bool usedLetter;
   char letter;
   cout << endl;
   for (unsigned i = 0; i < currentWord.size(); i++){
      letter = toupper(currentWord.at(i));
      usedLetter = false;
      // compare user input to currentword letters
      // if they are the same, print out letter
      for (int a = 0; a < ALPHA_SIZE; a++) {
         if ((letter == alphabet[a].letter) && (!alphabet[a].isAvailable)) {
           cout << letter << " ";
           usedLetter = true;
         }
      }
      // if the letter is wrong, print underscores
      if (!usedLetter) {
         cout << "_ ";
      }
   }
   cout << endl;
   //compare user input letter to current word letter
    
   // 3. display all letters, removing letters that have already been guessed
   //    i.e. if B, D, G, and T have been guessed, the alphabet should show
   //    A   C   E F   H I J K L M N O P Q R S   U V W X Y Z
   cout << endl;
   for (int i = 0; i < ALPHA_SIZE; i++){
      if (!alphabet[i].isAvailable){
         cout << " ";
      }else{
         cout << alphabet[i].letter;
      }
   }
   cout << endl << endl;
}

bool Hangman::guess(char letter, bool& done, bool& won)
{
   // TODO: check whether letter is in currentWord
   // - If so, reveal letters in the word (i.e. replace _ with letter)
   // - If not, update body array and display another body part
   letter = toupper(letter);
  
   int alphabetIndex;
   for (int i = 0; i < ALPHA_SIZE; i++)
      if (letter == alphabet[i].letter)
         alphabetIndex = i;

   if (!alphabet[alphabetIndex].isAvailable){
      return false;
   }else{
      alphabet[alphabetIndex].isAvailable = false;
   }
   correctGuess = false;
   for (unsigned i = 0; i < currentWord.size(); i++) {
      if (toupper(currentWord.at(i)) == letter) {
         correctCharacters++;
         correctGuess = true;
      }
   }
   if (!correctGuess){
      wrongGuesses++;
   }

   if (wrongGuesses == 1){
      body[2].displaySecond = true;
   }else if(wrongGuesses == 2){
      body[3].displaySecond = true;
   }else if(wrongGuesses == 3){
      body[4].displaySecond = true;
   }else if(wrongGuesses == 4){
      body[4].displayThird = true;
   }else if(wrongGuesses == 5){
      body[5].displaySecond = true;
   }else if(wrongGuesses == 6){
      body[6].displaySecond = true;
   }else if(wrongGuesses == 7){
      body[6].displayThird = true;
   }
  
   // if user guesses the word OR the user runs out of guesses 
   // (all body parts revealed before guessing the word), set done to true
  
   if (wrongGuesses == 7)
      done = true;
  
   // if user guessed the word before all body parts revealed,
   // set won to true
   if (correctCharacters == currentWordSize){
      won = true;
      done = true;
   }
	
   // TODO: update gamesWon and gamesLost
   if (done == true && won == true){
      gamesWon++;
   }else if(done == true){
      gamesLost++;
   }
   return true;
}

void Hangman::revealWord()
{
   // TODO: display currentWord
   cout << "The word was: " <<  currentWord << endl << endl;
}	

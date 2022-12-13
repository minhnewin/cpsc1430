// AUTHOR:   Minh Nguyen
// FILENAME: p1.cpp
// DATE:     04/16/2021
// PURPOSE:  The purpose of this program is to unravel a secret message
//           encoded in a file input from user. Each line of the file will
//           have one char and one nonnegative integer. Sorting the
//           nonnegative numbers which have characters associated with it
//           will spell out a secret message. The integer indicates the
//           position of the character within the message. Then the user is
//           asked if they want to try again. If not the program will end.
// INPUT:    Reads in data from user with each line of code containing
//           one char value and one nonnegative integer.
// PROCESS:  Ask the user for the name of the file. Check to see that the
//           file exists and contains some data. Open and read this file
//           exactly once. Unravel and display the message. Offer to do it
//           again on another file.
// OUTPUT:   Welcome message printed to screen. Asking for filename. Printed
//           secret message output to screen. Ask to try again. Repeat until
//           goodbye message.

#include <iostream>
#include <fstream>
#include <fstream>
using namespace std;

struct Node {
   char letter;           // character value is stored at this location
   int data;              // integer value is stored at this variable 
   Node * next;           // pointer variable pointing to next node for
                          // linked list
};

void welcome();
// displays a welcome message
// IN: none
// MODIFY: none
// OUT: prints welcome message to screen
void goodbye();
// displays a goodbye message
// IN: none
// MODIFY: none
// OUT: prints goodbye message to screen
void addInOrder(Node *&, int, char);
// inserts the integers and characters read from the file into a linked
// list in numerical order (from smallest to largest)
// IN: head (Node), data (int), letter (char)
// MODIFY: none
// OUT: ordered linked list
void printList(Node *);
// prints the complete list (on the same line) to the screen
// IN: head (Node)
// MODIFY: none
// OUT: Prints the data of the ordered linked list to screen 
void deleteList(Node *&);
// deletes all nodes in the list before ending the program
// IN: head (Node)
// MODIFY: none
// OUT: empty list (nothing is printed)

const char YES = 'y';     // initializes the while loop condition to be true

int main() {
   char letter;           // character value gathered from user input
   int data;              // integer data value gathered from user input
   ifstream infile;       // reads the file p1input.dat from user input
   string fileName;       // filename read in from user input
   char ans = YES;        // condition to continue while loop
   
   Node * head = nullptr; // initializes the linked list head pointing to
                          // nullptr
   
   welcome();

   while(tolower(ans) == YES) {
      cout << "Enter filename: ";
      cin >> fileName;

      infile.open(fileName);

      if(infile.fail()){
         cout << "File problem... exiting program...";
         cin.get();
      }

      cout << endl;
      cout << "Secret message:" << endl;
   
      // add to linked list
      while (infile.get(letter)) {
        infile >> data;
        infile.get();
        addInOrder(head, data, letter);
      }

      infile.close();

      // print list
      printList(head);

      // deallocate memory
      deleteList(head);

      cout << endl;
      cout << "Try again (y/n)? ";
      cin >> ans;
   }
   goodbye();
}

void deleteList(Node *&h) {
   Node * curr;
   while (h != nullptr) {
      curr = h;
      h = h->next;
      delete curr;
   }
}

void addInOrder(Node *&h, int d, char l) {
   Node * curr;
   Node * prev;
   Node * newNode = new Node;
   newNode->data = d;
   newNode->letter = l;

   if (h == nullptr) {
      h = newNode;
      newNode->next = nullptr;
   } else {
      prev = nullptr;
      curr = h;
      while (curr != nullptr && curr->data < d) {
         prev = curr;
         curr = curr->next;
      }
      // add to begining of list; otherwise, end or between nodes
      if (prev == nullptr) {
         h = newNode;
         newNode->next = curr;
      } else {
         prev->next = newNode;
         newNode->next = curr;
      }
   }
}

void printList(Node * h) {
   Node * curr = h;
   while (curr != nullptr) {
      cout << curr->letter;
      curr = curr->next;
   }
   cout << endl;
}

void welcome() {
   cout << endl;
   cout << "Welcome to the Secret Messages program." << endl;
   cout << "This program will decode a message from" << endl;
   cout << "a file input from the user (you)." << endl << endl;
}

void goodbye() {
   cout << "Thanks for using the Secret Messages program!" << endl << endl;
}

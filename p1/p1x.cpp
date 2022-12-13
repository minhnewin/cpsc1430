// AUTHOR:   Minh Nguyen
// FILENAME: p1x.cpp
// DATE:     04/16/2021
// PURPOSE:  The purpose of this program is to unravel two secret messages
//           encoded in two files input from user. Each line of the files will
//           have one char and one nonnegative integer. Sorting the
//           nonnegative numbers which have characters associated with it
//           will spell out a secret messages. The integer indicates the
//           position of the character within the message. The secret messages
//           will be printed each seperately at first but then will be sorted
//           word by word into one sorted secret message together. Then the
//           user is asked if they want to try again. If not the program
//           will end.
// INPUT:    Reads in two data files from user with each line of code
//           containing one char value and one nonnegative integer.
// PROCESS:  Ask the user for the name of the files. Check to see that the
//           file exists and contains some data. Open and read these files
//           exactly once. Unravel and display the messages. Offer to do it
//           again on more files.
// OUTPUT:   Welcome message printed to screen. Asking for filenames. Printed
//           secret messages output to screen. Ask to try again. Repeat until
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
void merge(Node *&, Node *&, Node *&);
// merges the two messages where the first parameter will be the first
// message, the second parameter will be the second message, and the
// third parameter will be the merged message
// In: head (Node), head (Node), head (Node)
// Modify: none
// Out: merged linked list

const char YES = 'y';     // initializes the while loop condition to be true

int main() {
   char letter;           // character value gathered from user input
   int data;              // integer data value gathered from user input
   ifstream infile1;      // reads the file from user input
   ifstream infile2;      // reads the file from user input
   string fileName1;      // filename read in from user input
   string fileName2;      // filename read in from user input
   char ans = YES;        // condition to continue while loop
   
   Node * head1 = nullptr; // initializes the linked list head1 pointing to
                           // nullptr
   Node * head2 = nullptr; // initializes the linked list head2 pointing to
                           // nullptr
   Node * head3 = nullptr; // initializes the linked list head3 pointing to
                           // nullptr
   
   welcome();

   while(tolower(ans) == YES) {
      cout << "Enter filename #1: ";
      cin >> fileName1;
      cout << "Enter filename #2: ";
      cin >> fileName2;

      // file 1
      infile1.open(fileName1);

      if(infile1.fail()){
         cout << "File problem... exiting program...";
         cin.get();
      }
   
      // add to linked list
      while (infile1.get(letter)) {
         infile1 >> data;
         infile1.get();
         addInOrder(head1, data, letter);
      }
      infile1.close();

      // file 2
      infile2.open(fileName2);

      if(infile2.fail()){
         cout << "File problem... exiting program...";
         cin.get();
      }
      
      // add to linked list
      while (infile2.get(letter)) {
         infile2 >> data;
         infile2.get();
         addInOrder(head2, data, letter);
      }
      infile2.close();

      // print linked lists 1 and 2
      cout << endl;
      cout << "Secret message 1:" << endl;
      printList(head1);
      cout << endl;
      cout << "Secret message 2:" << endl;
      printList(head2);

      // merge
      merge(head1, head2, head3);
      printList(head3);

      // deallocate memory
      deleteList(head1);
      deleteList(head2);
      deleteList(head3);
      
      // continue?
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

void merge(Node *& head1, Node *& head2, Node *& head3) {
   Node * curr;
   Node * prev;
   Node * tempNode1;
   Node * tempNode2;
   Node * newNode = new Node;
   tempNode1 = head1;
   tempNode2 = head2;
   
   while (head1 != nullptr && head2 != nullptr) {
       prev = nullptr;
       curr = head1;
       while (curr != nullptr && curr->letter != ) {
         prev = curr;
         curr = curr->next;
       }
       if (curr != head1 && curr->letter == "z") {
         prev = curr;
         tempNode1 = curr;
         curr = tempNode2;
       } else if (curr == head2 && curr->letter == "z") {
         prev = curr;
         tempNode2 = curr;
         curr = tempNode1;
       }
     }
   }
}

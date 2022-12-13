// queue.h

#ifndef QUEUE_H    
#define QUEUE_H    
    
class Queue {    
public:    
   Queue();
   // default constructor
   // precondition: none
   // postcondition: sets front and rear to nullptr and numItems to 0
   Queue(const Queue &);
   // copy constructor
   // precondition: none
   // postcondition: creates a new object and initializes it with data from obj
   Queue& operator=(const Queue &);
   // overloaded operator
   // precondition: &obj
   // postcondition: initializes board with data from an object
   ~Queue();
   // deconstructor
   // precondition: none
   // postcondition: dequeues linked list
   void enqueue(int);
   // adds integer values to rear of linked list
   // precondition: int
   // postcondition: updates linked list
   void dequeue();
   // removes integer values to front of linked list
   // precondition: none
   // postcondition: updates linked list
   int peek() const;
   // returns int value at the front of linked list
   // precondition: none
   // postcondition: returns int value at front of linked list
   bool empty() const;
   // returns numItems if linked list is empty
   // precondition: none
   // postcondition: returns numItems if linked list is empty
   int size() const;
   // returns size of linked list
   // precondition: none
   // postcondition: returns size of linked list
private:
   struct Node {
      int value; // integer value for linked list value   
      Node *next; // helper node to go through linked list
   };    
   Node *front; // helper node to mark front of queue
   Node *rear; // helper node to mark rear of queue
   int numItems; // integer value to keep track of elements in linked list
   void clear();
   // dequeues the linked list
   // precondition: none
   // postcondition: updates linked list
};    

#endif

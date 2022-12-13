// stack.h

#ifndef STACK_H
#define STACK_H

class Stack {
public:
   Stack(int);
   // default constructor
   // precondition: none
   // postcondition: creates a new array for cards to poppulate
   Stack(const Stack &);
   // copy constructor
   // precondition: &obj
   // postcondition: creates a new object and initializes it with data from obj
   Stack& operator=(const Stack &);
   // overloaded operator
   // precondition: &obj
   // postcondition: initializes board with data from an object
   ~Stack();
   // deconstructor
   // precondition: none
   // postcondition: deletes array
   void push(int);
   // pushes an integer value into the top of the array and increments top
   // precondition: int
   // postcondition: updates stack array
   void pop();
   // deletes the int value at the top of the stack and decrements top
   // precondition: none
   // postcondition: updates stack array
   int peek() const;
   // returns int value at the top of stack array
   // precondition: none
   // postcondition: returns int value at top of the stack array
   bool empty() const;
   // checks to see if array is empty
   // precondition: none
   // postcondition: returns -1 if top == -1
   int size() const;
   // returns top + 1
   // precondition: none
   // postcondition: returns top + 1
private:
   int *arr; // int array pointer for stack
   int capacity; // size of array
   int top; // top index of array
   void resize();
   // resizes array and copies old values onto new array, then deletes old array
   // precondition: none
   // postcondition: array size is doubled
};

#endif

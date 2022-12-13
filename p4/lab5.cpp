// lab5.cpp
// testing of integer stack & queue packages

#include <iostream>
#include "stack.h"
#include "queue.h"

using namespace std;

void testStack();
// tests all stack package methods

void testQueue();
// tests all queue package methods

int main() {
	cout << "\n** TESTING STACK OPERATIONS **\n";
  	testStack();
  	cout << endl;
 	cout << "\n** TESTING QUEUE OPERATIONS **\n";
  	testQueue();
	cout << endl;
  	return 0;
}

void testStack() {
  	int num;
  	// constructor
  	Stack s1(50);
  	// constructor with size
  	Stack s2(3);

	// initial sizes
	cout << "initial size of s1 is " << s1.size() << endl;
	cout << "initial size of s2 is " << s2.size() << endl;

  	// push to s1
  	cout << "\n-> Pushing 4 values onto stack, s1 (of capacity 50) " << endl;
  	for (int i = 0; i < 4; i++)
		s1.push(i);
	cout << "size of s1 (after pushing 4 values) is " << s1.size() << endl;

  	// copy constructor (s1 into s3)
  	cout << "\n-> Copying s1 into s3 (using copy constructor) " << endl;
  	Stack s3(s1);
	cout << "size of s3 (same size as s1) is " << s3.size() << endl;

  	// peek/pop from s1 until empty
  	cout << "\n-> Popping all values from s1 " << endl;
  	while (!s1.empty()) {
		num = s1.peek();
		s1.pop();
		cout << "popped " << num << " from s1" << endl;
  	}
	cout << "size of s1 (after all values popped) is " << s1.size() << endl; 
 
	// peek/pop from s3 until empty
	cout << "\n-> Popping all values from s3 (same values as s1) " << endl;
  	while (!s3.empty()) {
		num = s3.peek(); 	
  		s3.pop();
		cout << "popped " << num << " from s3" << endl;
	}
	cout << "size of s3 (after all values poppped) is " << s3.size() << endl;

  	// resize s2
  	cout << "\n-> Pushing 5 values onto stack s2 (of capacity 3) " << endl;
  	for (int i = 0; i < 5; i++) 
		s2.push(i);	
	cout << "size of s2 (after pushing 4 values) is " << s2.size() << endl;

  	// assignment operator (s2 into s1)
  	cout << "\n-> Copying s2 into s1 (using assignment operator) " << endl;
  	s1 = s2;
	cout << "size of s1 (same size as s2) is " << s1.size() << endl;

	// peek/pop from s2 until empty
	cout << "\n-> Popping all values from s2 " << endl;
  	while (!s2.empty()) {
		num = s2.peek();
		s2.pop();
		cout << "popped " << num << " from s2" << endl;
  	}
	cout << "size of s2 (after all values popped) is " << s2.size() << endl;

	// peek/pop from s1 until empty
  	cout << "\n-> Popping all values from s1 (same values as s2) " << endl;
  	while (!s1.empty()){
		num = s1.peek();
		s1.pop();
		cout << "popped " << num << " from s1" << endl;
  	}
	cout << "size of s1 (after all values popped) is " << s1.size() << endl;
}

void testQueue() {
  	int num;
  	// constructor
  	Queue q1, q2;

	// initial sizes
	cout << "initial size of q1 is " << q1.size() << endl;
	cout << "initial size of q2 is " << q2.size() << endl;

  	// enqueue to q1
  	cout << "\n-> Enqueuing 5 values to queue, q1" << endl;
  	for (int i = 3; i < 8; i++)
		q1.enqueue(i);
	cout << "size of q1 (after pushing 5 values) is " << q1.size() << endl; 

  	// copy constructor (q1 into q3)
  	cout << "\n-> Copying q1 into q3 (using copy constructor)" << endl;
  	Queue q3(q1);
	cout << "size of q3 (same size as q1) is " << q3.size() << endl; 

	// peek/dequeue from q1 until empty
  	cout << "\n-> Emptying all values from q1" << endl;
  	while (!q1.empty()) {
		num = q1.peek();
		q1.dequeue();
	  	cout << "dequeued " << num << " from q1" << endl;
  	}
	cout << "size of q1 (after all values dequeued) is " << q1.size() << endl;
  
  	// assignment operator
  	cout << "\n-> Copying q3 into q2 (using assignment operator)" << endl;
  	q2 = q3;
	cout << "size of q2 (same size as q3) is " << q2.size() << endl;  

	// peek/dequeue from q3 until empty 
	cout << "\n-> Emptying all values from q3" << endl; 
	while (!q3.empty()) {
		num = q3.peek();
		q3.dequeue();
		cout << "dequeued " << num << " from q3" << endl; 
	}
	cout << "size of q3 (after all values dequeued) is " << q3.size() << endl; 

	// peek/dequeue from q2 until empty
	cout << "\n-> Emptying all values from q2" << endl; 
	while (!q2.empty()) {
		num = q2.peek();
		q2.dequeue();
		cout << "dequeued " << num << " from q2" << endl;
	}
	cout << "size of q2 (after all values dequeued) is " << q2.size() << endl; 
}


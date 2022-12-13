// stack.cpp

#include "stack.h"
#include <assert.h>
using namespace std;

Stack::Stack(int cap) {
  arr = new int[cap];
  capacity = cap;
  top = -1;
}

Stack::~Stack() {
  delete [] arr;
}

Stack::Stack(const Stack &obj) {
  capacity = obj.capacity;
  arr = new int[capacity];
  for (int i = 0; i < capacity; i++)
    arr[i] = obj.arr[i];
  top = obj.top;
}

Stack& Stack::operator=(const Stack &obj) {
  if (this != &obj) {
    capacity = obj.capacity;
    delete [] arr;
    arr = new int[capacity];
    for(int i = 0; i < capacity; i++)
      arr[i] = obj.arr[i];
    top = obj.top;
  }
  return *this;
}

void Stack::push(int num) {
  if (top + 1 == capacity)
    resize();
  top++;
  arr[top] = num;
}

void Stack::pop() {
  assert(!empty());
  top--;
}

int Stack::peek() const {
  assert(!empty());
  return arr[top];
}

bool Stack::empty() const {
  return top == -1;
}

int Stack::size() const {
  return top + 1;
}

void Stack::resize() {
  capacity *= 2;
  int * temp = new int[capacity];
  for (int i = 0; i <= top; i++)
    temp[i] = arr[i];
  delete [] arr;
  arr = temp;
}

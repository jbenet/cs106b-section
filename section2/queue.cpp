#include <iostream>
#include <string>
#include "simpio.h"
#include "queue.h"
#include "stack.h"
using namespace std;

#ifdef SOLUTIONS
#include "solutions.cpp"
#else

void reverseQueue(Queue<string> & queue) {

  Stack<string> stack;

  while (!queue.isEmpty()) {
    stack.push(queue.dequeue());
  }

  while (!stack.isEmpty()) {
    queue.enqueue(stack.pop());
  }
}

#endif

template <class T>
void printQueue(Queue<T> queue) {

  while (!queue.isEmpty())
    cout << queue.dequeue() << " ";
  cout << endl;
}


int main() {

  Queue<string> queue;

  for (char c = 'A'; c <= 'Z'; c++) {
    stringstream ss;
    ss << c;
    queue.enqueue(ss.str());
  }

  printQueue<string>(queue);

  reverseQueue(queue);
  printQueue(queue);
}


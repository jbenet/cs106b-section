#include <iostream>
#include <cctype>
#include <string>

#include "simpio.h"
#include "grid.h"
#include "queue.h"
#include "stack.h"
#include "strlib.h"
#include "lexicon.h"

using namespace std;


// Problem 1

int countNearbyMines(Grid<bool> & mines, int row, int col) {
  int numMines = 0;
  for (int r = -1; r <= 1; r++) {
    for (int c = -1; c <= 1; c++) {

      if (!mines.inBounds(row + r, col + c))
        continue;

      if (mines[row + r][col + c])
        numMines++;
    }
  }

  return numMines;
}



void fixCounts(Grid<bool> & mines, Grid<int> & counts) {
  int rows = mines.numRows();
  int cols = mines.numCols();
  counts.resize(rows, cols);

  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      counts[r][c] = countNearbyMines(mines, r, c);
    }
  }

}



// Problem 2

void reverseQueue(Queue<string> & queue) {
  Stack<string> stack;

  while (!queue.isEmpty())
    stack.push(queue.dequeue());

  while (!stack.isEmpty())
    queue.enqueue(stack.pop());
}


// Problem 4

string reverse(string str) {
  string rev;
  for (int i = str.length() - 1; i >= 0; i--) {
    rev += str[i];
  }
  return rev;
}

bool isPalindrome(string str) {
  return str == reverse(str);
}

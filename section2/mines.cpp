#include <iostream>
#include <string>
#include "simpio.h"
#include "grid.h"
using namespace std;

template <class T> void printGrid(Grid<T> & locations);

#ifdef SOLUTIONS
#include "solutions.cpp"
#else



int countNearbyMines(Grid<bool> & mines, int row, int col) {
  int countOfMines = 0;
  for (int r = row -1; r <= row + 1; r++) {

    for (int c = col -1; c <= col + 1; c++) {

      if (mines.inBounds(r, c)) {

        if (mines[r][c]) {
          countOfMines++;
        }
      }
    }
  }
  return countOfMines;
}


void fixCounts(Grid<bool> & mines, Grid<int> & counts) {

  counts.resize(mines.numRows(), mines.numCols());

  for (int r = 0; r < mines.numRows(); r++) {
    for (int c = 0; c < mines.numCols(); c++) {
      counts[r][c] = countNearbyMines(mines, r, c);
    }
  }
}


#endif



int main() {
  Grid<bool> mineLocations(6, 6);
  Grid<int> mineCounts;

  Grid<int> mineCounts2 = mineCounts;


  mineLocations[0][0] = true;
  mineLocations[0][5] = true;
  mineLocations[1][5] = true;
  mineLocations[2][0] = true;
  mineLocations[2][1] = true;
  mineLocations[2][3] = true;
  mineLocations[2][5] = true;
  mineLocations[3][0] = true;
  mineLocations[4][2] = true;

  fixCounts(mineLocations, mineCounts);

  cout << " locations:" << endl;
  printGrid(mineLocations);

  cout << " counts:" << endl;
  printGrid(mineCounts);

}




template <class T>
void printGrid(Grid<T> & locations) {
  int rows = locations.numRows();
  int cols = locations.numCols();
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      cout << ' ' << locations[r][c];
    }
    cout << endl;
  }
  cout << endl;
}

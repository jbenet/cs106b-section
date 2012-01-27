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
  return 0;
}



void fixCounts(Grid<bool> & mines, Grid<int> & counts) {

}


#endif



int main() {
  Grid<int> mineCounts(6, 6);
  Grid<bool> mineLocations(6, 6);

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

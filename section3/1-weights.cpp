#include <iostream>
#include <string>
#include <cctype>

#include "simpio.h"
#include "vector.h"
#include "strlib.h"

using namespace std;

// #define SOLUTIONS true


#ifdef SOLUTIONS
#include "solutions.cpp"
#else


bool isMeasurable(int target, Vector<int> &weights) {
  if (weights.isEmpty()) {
    return target == 0;
  }

  int first = weights[0];
  Vector<int> rest = weights;
  rest.removeAt(0);
  return isMeasurable(target, rest)
      || isMeasurable(target - first, rest)
      || isMeasurable(target + first, rest);
}

#endif

#undef main
int main(int argc, char **argv) {
  argc--; argv++;

  if (!argc) {
    cout << "Error: no weights." << endl;
    return -1;
  }

  Vector<int> sampleWeights;
  // sampleWeights += 1, 3;

  cout << "Using sample weights:";
  for(; argc--; argv++) {
    string weight = *argv;
    cout << " " << weight;
    sampleWeights.add(stringToInteger(weight));
  }
  cout << endl << endl;

  while (true) {

    string entered = getLine("Enter Weight: ");
    if (entered.length() == 0) {
      return 0;
    }

    int target = stringToInteger(entered);
    if (target < 0) {
      cout << "Come on, now..." << endl;
      continue;
    }

    cout << target << " is";
    if (!isMeasurable(target, sampleWeights)) {
      cout << " NOT";
    }
    cout << " measurable." << endl;
  }

}
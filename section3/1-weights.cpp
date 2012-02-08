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

bool isMeasurable(int target, Vector<int> weights) {
  if (target == 0)
    return true;

  if (weights.size() == 0)
    return false;

  int w = weights[0];
  weights.removeAt(0);


  return isMeasurable(target - w, weights)
      || isMeasurable(target,     weights)
      || isMeasurable(target + w, weights);

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
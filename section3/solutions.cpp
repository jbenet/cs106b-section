#include <iostream>
#include <cctype>
#include <string>

#include "simpio.h"
#include "vector.h"
#include "strlib.h"
#include "lexicon.h"

using namespace std;


// Problem 1

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



// Problem 2


// Problem 4

static int kMinWordLength = 4;
bool findAnagramWithFixedPrefix(string prefix,
                                string rest,
                                Lexicon &lex,
                                Vector<string> & words) {

  if (!lex.containsPrefix(prefix))
    return false;

  if (lex.contains(prefix) && prefix.length() >= kMinWordLength) {
    if (rest == "" || findAnagramWithFixedPrefix("", rest, lex, words)) {
      words.add(prefix);
      return true;
    }
  }

  for (int i = 0; i < rest.length(); i++) {
    string others = rest.substr(0, i) + rest.substr(i + 1);
    if (findAnagramWithFixedPrefix(prefix + rest[i], others, lex, words))
      return true;
  }

  return false;
}

bool findAnagram(string letters, Lexicon &lex, Vector<string> & words) {
  return findAnagramWithFixedPrefix("", letters, lex, words);
}

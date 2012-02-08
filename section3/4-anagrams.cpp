#include <iostream>
#include <string>

#include "simpio.h"
#include "vector.h"
#include "lexicon.h"
#include "strlib.h"

using namespace std;

static int kMinWordLength = 4;

bool findAnagram(string letters, Lexicon &lex, Vector<string> & words);

#ifdef SOLUTIONS
#include "solutions.cpp"
#else


#endif


#undef main
int main(int argc, char **argv) {
  if (argc > 1) {
    kMinWordLength = stringToInteger(string(argv[1]));
  }
  cout << "minimum word length: " << kMinWordLength << endl;

  Lexicon english("EnglishWords.dat");

  while (true) {

    string entered = getLine("Enter phrase: ");
    if (entered.length() == 0) {
      return 0;
    }

    for (int i = 0; i < entered.length(); i++) {
      if (entered[i] == ' ') {
        entered = entered.substr(0, i) + entered.substr(i + 1);
        i--;
      }
    }

    if (entered.length() == 0) {
      cout << "Come on, now..." << endl;
      continue;
    }

    Vector<string> words;
    findAnagram(entered, english, words);

    if (words.size() == 0) {
      cout << "no anagram found :(" << endl;
      continue;
    }

    foreach (string word in words) {
      cout << word << " ";
    }
    cout << endl;

  }

}



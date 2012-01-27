#include <iostream>
#include <string>
#include <cctype>
#include "strlib.h"
#include "lexicon.h"
using namespace std;


#ifdef SOLUTIONS
#include "solutions.cpp"
#else

bool isPalindrome(string str) {
  return false;
}

#endif

int main() {
  cout << "English Palindromes:" << endl;
  Lexicon english("EnglishWords.dat");

  foreach (string word in english) {
   if (isPalindrome(word))
     cout << word << endl;
  }
}
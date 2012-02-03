#include <iostream>
#include <string>
#include <cctype>
#include "stack.h"
#include "lexicon.h"
using namespace std;

// #define SOLUTIONS true


#ifdef SOLUTIONS
#include "solutions.cpp"
#else

string reverseString(string str) {

  Stack<char> stack;

  for (int i = 0; i < str.length(); i++) {
    stack.push(str[i]);
  }

  str = "";

  while (!stack.isEmpty()) {
    str += stack.pop();
  }
  return str;
}


bool isPalindrome(string str) {
  return str == reverseString(str);
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
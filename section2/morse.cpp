#include <iostream>
#include <string>
#include "error.h"
#include "map.h"
#include "strlib.h"
using namespace std;

string lettersToMorse(string line);
string morseToLetters(string line);


const Map<string, string> LETTERS_TO_MORSE = createMorseCodeMap();
const Map<string, string> MORSE_TO_LETTERS = invertMap(LETTERS_TO_MORSE);

int main() {
  cout << "Morse code translator" << endl;

  while (true) {
    string line;
    cout << "> ";
    getline(cin, line);
    if (line == "")
      break;

    line = toUpperCase(line);
    if (line[0] == '.' || line[1] == '-') {
      cout << morseToLetters(line) << endl;
    } else {
      cout << lettersToMorse(line) << endl;
    }
  }
  return 0;
}
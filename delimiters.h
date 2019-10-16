#ifndef delimiters_H
#define delimiters_H
#include "GenStack.h"
#include <iostream>
#include <fstream>

using namespace std;

class delimiters{
public:
  delimiters();
  delimiters(int lc, char delimValue);
  ~delimiters();
  char findMatchingPair(char delimValue);
  int delimLC;
  char delimVal;
  char matchingPair;
  bool foundMatch;
  int charCount;

};
#endif

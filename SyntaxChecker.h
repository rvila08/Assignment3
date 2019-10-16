#include "delimiters.h"

using namespace std;

class SyntaxChecker{
public:
  int countDelims();
  void unmatchedDelim();
  void printError(char delim, int lineNum);
  void popStack();
  void storeDelim(char letters, int lineCount);
  bool quotePairCheck(char letters);
  GenStack<delimiters*> dS;
  string readFile(string fileName);
  SyntaxChecker();
  ~SyntaxChecker();
private:
  GenStack<delimiters*> delimStack;
  ifstream fileStream;
  bool QuotePair = false;
  int lineCount = 0;


};

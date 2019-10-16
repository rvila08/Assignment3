#include "delimiters.h"
#include "SyntaxChecker.h"


int main(int argc, char const *argv[]) {

  SyntaxChecker s;
  s.readFile("test.txt");
  s.countDelims();
  
  return 0;
}

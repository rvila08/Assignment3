#include "delimiters.h"
#include "SyntaxChecker.h"


int main(int argc, char **argv) {

  string fileName;
  if(argc==2){
    fileName = argv[1];
  }

  SyntaxChecker s;
  s.readFile(fileName);
  s.countDelims();

  return 0;
}

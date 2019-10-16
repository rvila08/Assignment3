#include "delimiters.h"
#include "SyntaxChecker.h"


int main(int argc, char **argv) {

  string fileName;
  string userinput;
  bool restart = true;
  while(restart){
    if(argc==2){
      fileName = argv[1];
    }

    SyntaxChecker s;
    s.readFile(fileName);
    s.countDelims();

    cout << "Would you like to exit the program? (y/n) \n";
    cin >> userinput;
    if(userinput == "no" || userinput == "n"){
      break;
    }
    cout << "Enter another file name\n";
    cin >> fileName;
  }
  return 0;
}

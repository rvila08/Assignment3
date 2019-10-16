#include "SyntaxChecker.h"
#include <fstream>

using namespace std;

SyntaxChecker::SyntaxChecker(){
    delimStack = GenStack<delimiters*>(); //stack of pointers to delimiters created
}

SyntaxChecker::~SyntaxChecker(){

}

int SyntaxChecker::countDelims(){

    for(int i=0; i<=delimStack.top; ++i){   //iterate through delimiter stack
      delimiters *curr = delimStack.myArray[i]; //set curr to delimiter pointer object
      if(curr->foundMatch == true){
        continue;                 //if it already has a matched pair, skip it
      }

      else if(curr->delimVal == ']' || curr->delimVal == ')' || curr->delimVal == '}'){ //if its a closed bracket, skip it - because all closed brackets
        continue;                                                     //will already be paired with open brackets
      }

      for(int j=i; j<=delimStack.top; ++j){ //now iterate through the rest of the stack to check for matching delimeters
        delimiters *next = delimStack.myArray[j]; //created variable which points to all delimiters after the current delimiter
        if(next->foundMatch == true){
          continue;             //skip the delimiter if it is already true
        }
        if(curr->delimVal == next->matchingPair){ //if the matching pair is found, set foundMatch = true on both delimiters
          curr->foundMatch = true;
          next->foundMatch = true;
          break;
        }
      }
    }

    for(int i=0; i<=delimStack.top; ++i){ //iterate through the stack
      delimiters *curr = delimStack.myArray[i];
      if(curr->foundMatch == false){      //if any of the delimiters do not have a match - return print error
        printError(curr->delimVal, curr->delimLC);
        errorFound = true;
        exit(EXIT_FAILURE);
      }
    }
    if(errorFound == false){
      cout << "No syntax errors found. Good job!" << endl;
      exit(0);
    }
}

void SyntaxChecker::storeDelim(char letters, int lineCount){


  if(letters == '[' && quotePairCheck(letters) == false){
    delimiters *d = new delimiters(lineCount, letters);
    delimStack.push(d);
           //push open delimiters onto openD stack
          //and also check whether the delimiter is in quotes or not
  }

  else if(letters == '{' && quotePairCheck(letters) == false){
    delimiters *d = new delimiters(lineCount, letters);
    delimStack.push(d);

  }

  else if(letters == '(' && quotePairCheck(letters) == false){
    delimiters *d = new delimiters(lineCount, letters);
    delimStack.push(d);

  }
  else if(letters == ']' && quotePairCheck(letters) == false){
    delimiters *d = new delimiters(lineCount, letters);
    delimStack.push(d);

  }
  else if(letters == '}' && quotePairCheck(letters) == false){
    delimiters *d = new delimiters(lineCount, letters);
    delimStack.push(d);

  }
  else if(letters == ')' && quotePairCheck(letters) == false){
    delimiters *d = new delimiters(lineCount, letters);
    delimStack.push(d);

  }
}

string SyntaxChecker::readFile(string fileName){ //this functions reads the file name then stores all delimeters into a stack
  string line = "";
  int lineCount = 0;
  fileStream.open(fileName);
  if(fileStream.is_open()){ //if the file is open


    while(getline(fileStream, line)){ //while there are still lines in the text file
        lineCount++; //increment lineCount to keep track of what line we are on
        for(char letters : line){
          storeDelim(letters, lineCount); //store the delimiters with the line count
        }
      }
  }
  return " ";
}

bool SyntaxChecker::quotePairCheck(char letters){

  if(letters == '\'' || letters == '\"'){ //if within a single or double quote
    if(QuotePair == false){ //QuotePair is first set to false
      QuotePair = true;    //once the first quote is seen, it will be set to true
    }                      //once the next quote pair is seen, it will be set to false
    if(QuotePair == true){ // this way it alternates between true and false
      QuotePair = false;
    }
  }


  return QuotePair;
}

void SyntaxChecker::printError(char delim, int lineNum){
  string message = "Unmatched "+ string(1,delim) + " on line number " + to_string(lineNum);
  throw runtime_error(message);
}

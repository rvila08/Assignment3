#include "delimiters.h"

using namespace std;

delimiters::delimiters(int lc, char delimValue){
  this ->foundMatch = false;                      //member variables which keep track of a delimiter object's
  this ->delimLC = lc;                    //line count, delimiter value, matching pair delim value, and whether it has a pair
  this ->delimVal = delimValue;
  this ->matchingPair = findMatchingPair(delimValue);
}
delimiters::delimiters(){

}
delimiters::~delimiters(){

}

char delimiters::findMatchingPair(char delim){  //stores each delimiters matching pair in a member variable
  if(delim == ']'){                       // in each delimiter object
    return '[';
  }
  else if(delim == '['){
    return ']';
  }
  else if(delim == '('){
    return ')';
  }
  else if(delim == ')'){
    return '(';
  }
  else if(delim == '{'){
    return '}';
  }
  else if(delim == '}'){
    return '{';
  }
}

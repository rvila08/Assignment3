#ifndef GenStack_H
#define GenStack_H
#include <iostream>

using namespace std;

template <class T>
class GenStack{
  public:
    T* myArray;
    int top;
    int size;

    GenStack(){
      //init of default values
      myArray = new T[128];
      size = 128;
      top = -1;
    }

    GenStack(int maxSize){
        myArray = new T[maxSize];
        size = maxSize;
        top = -1;
    }

    ~GenStack(){
        delete myArray;
    }

    void push(T data){
      
      if(isFull()){
        T* newArray = new T[size*2];
        for(int i =0;i<size-1;++i){
          newArray[i] = myArray[i];
        }
        myArray = newArray;
      }
      myArray[++top] = data;
    }

    T pop(){
        //error checking, make sure its not isEmpty
        if(isEmpty()){
          throw runtime_error("Stack is empty. Sorry.");
        }

        return myArray[top--];
    }

    T peek(){
        //check if empty
        if(isEmpty()){
          throw runtime_error("Stack is empty. Sorry.");
        }
        return myArray[top];
    }

    bool isFull(){
        return(top == size-1);
    }

    bool isEmpty(){
        return(top == -1);
    }              //at compile time - placeholder for array until initialized
};
#endif

#include "Stack.h"

//default constructor
template <class T> // found on https://www.geeksforgeeks.org/templates-cpp/ (template <class T> is declared before every class to broaden input types)
Stack<T>::Stack(){ // Stack <T> - <T> represents template and will take in not just one data type but all appropiate primitives
  myArray = new T[128];
  mSize = 128;
  top = -1;
}

template <class T>
Stack<T>::Stack(int maxSize){
  myArray = new T[maxSize];
  mSize = maxSize;
  top = -1;
}

template <class T>
Stack<T>::~Stack(){
  delete myArray;
}

template <class T>
void Stack<T>::push(T data){ //char becomes T
//check if stack/array is full before proceeding
  if(isFull()){
    cout << "ERROR: Stack is full" << endl;
  }
  myArray[++top] = data;
}

template <class T>
T Stack<T>::pop(){
  //check if empty before proceeding
  if(isEmpty()){
    cout << "ERROR: Stack is empty" << endl;
    return 0;
  }
  return myArray[top--];
}

template <class T>
T Stack<T>::peek(){
  return myArray[top];
}

template <class T>
bool Stack<T>::isFull(){
  return (top == mSize - 1);
}

template <class T>
bool Stack<T>::isEmpty(){
  return (top == -1);
}

template <class T>
int Stack<T>::getSize(){
  return (top + 1);
}

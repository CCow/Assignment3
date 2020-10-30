//header file Stack.h
#include <iostream>
using namespace std;

template <class T> //https://www.geeksforgeeks.org/templates-cpp/ (template <class T>)
class Stack{
  public:
    Stack();//default
    Stack(int maxSize);//overloader
    ~Stack();//deconstructor

    void push(T data); //char becomes T

    T pop(); //chars become T to be able to read all different languages (Template) ^^
    T peek(); //same story as above

    bool isFull();
    bool isEmpty();

    int getSize();

  private:
    T *myArray;

    int top;
    int mSize;
};

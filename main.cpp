#include "SyntaxChecker.h"
#include "Stack.h"
#include <iostream>
#include <fstream>
//syntax checker should have one instance of the stack
using namespace std;

int main (int argc, char **argv){
  SyntaxChecker sc;
  string input;
  cout << "Input File for Syntax Checking: " << endl;
  cin >> input;

  ifstream readInput(input);
  sc.CheckSyntax();
}

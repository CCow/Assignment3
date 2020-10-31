#include "SyntaxChecker.h"
#include "Stack.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

SyntaxChecker::SyntaxChecker(){

}

SyntaxChecker::~SyntaxChecker(){

}

void SyntaxChecker::CheckSyntax(){ //Method to check file input's syntax
  delimiter = 0; //counts how many delimiters the user is off by -3 = 3 too many delimiters; +2 = 2 delimiters missing
  lineCount = 0; //returns the line number
  char fixThisCode; //rename if fixes problem
  char yesNo;

  //fixThisCode.Stack = stack; //tried many different ways to create an instance of the stack but maybe I have too many classes
  //stack = new Stack<char>*;
  Stack <char> stack; //Error printed from this line: SyntaxChecker.cpp:(.text+0x6f): undefined reference to `Stack<char>::Stack()'
  string line; //http://www.cplusplus.com/forum/lounge/52458/ for this line, the next if/else statement and next while loop
  ifstream source;
  source.open(fileInput);

  if(source.is_open()){ //Acting as my try/catch - Try part
    while(source.good()){
      getline(source, line); //http://www.cplusplus.com/forum/lounge/52458/
      lineCount++;
      for(int x; x < line.length(); ++x){
        char y = line[x];
        if(y == '(' || y == '{'||y == '['){
          if(stack.isFull()){
            //resize Method
          }
          else{
            stack.push(y);
            delimiter++;
          }
        }

        else if(y == ')' || y == '}'||y == ']'){
          if(stack.isEmpty() == false){
            if(y == ')' && stack.peek() != '('){
              cout << "ERROR: ')' MISSING ON LINE: " << lineCount << endl;
              //stack.~Stack;
              source.close();
            }

            else if(y == '}' && stack.peek() != '{'){
              cout << "ERROR: '}' MISSING ON LINE: " << lineCount << endl;
              //stack.~Stack;
              source.close();
            }

            else if(y == ']' && stack.peek() != '['){
              cout << "ERROR: ']' MISSING ON LINE: " << lineCount << endl;
              //stack.~Stack;
              source.close();
            }

            else{
              stack.pop();
              delimiter--;
            continue;
            }
          }

          else{
            cout << "FILE IS MISSING OPENING DELIMITERS" << endl;
            cout << "RECHECK FILE AND RESTART" << endl;
            source.close();
          }
        }
      }
    }
    if(stack.isEmpty()){
      cout << "SYNTAX CHECK COMPLETE, DELIMITER SYNTAX IS CORRECT" << endl;
      cout << "( +/- ) Delimiters: " << delimiter << endl;
      cout << "Would you like to check another file (y/n): ";
      cin >> yesNo;
      if(yesNo == 'y' || yesNo == 'Y'){
        CheckSyntax();
      }
      else if(yesNo == 'n' || yesNo == 'N'){
        //stack.~Stack;
        source.close();
      }
    }

    else{
      cout << "REACHED END OF FILE: MISSING '}' DELIMITER" << endl;
      cout<< "( +/- ) Delimiters: " << delimiter << endl;
      //stack.~Stack();
      source.close();
    }
  }

  else{ //"Catch" end of try/catch
    cout << "COULD NOT OPEN FILE" << endl;
    cout << "RESTART WITH DIFFERNT FILE INPUT" << endl;
    source.close();
  }
}

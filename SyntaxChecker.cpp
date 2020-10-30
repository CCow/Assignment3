#include "SyntaxChecker.h"
#include "Stack.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

SyntaxChecker::SyntaxChecker(){
  //vacant space atm
}

SyntaxChecker::~SyntaxChecker(){
  //  delete nothing
}

void SyntaxChecker::CheckSyntax(){
  delimiter = 0;
  lineCount = 0;

  stack = new Stack<char>*; //cplusplus.com
  string line; //http://www.cplusplus.com/forum/lounge/52458/ for this line, the next if/else statement and next while loop
  ifstream source;
  source.open(fileInput);

  if(source.is_open()){ //Acting as a try/catch - Try part
    while(source.good()){ ////http://www.cplusplus.com/forum/lounge/52458/
      getline(source, line); //http://www.cplusplus.com/forum/lounge/52458/
      lineCount++;
      for(int x; x < line.length(); ++x){
        char y = line[x];
        if(y == '(' || y == '{'||y == '['){
          stack.push(y);
          delimiter++;
        }

        else if(y == ')' || y == '}'||y == ']'){
          if(stack.isEmpty() == false){
            if(y == ')' && stack.peek() != '('){
              cout << "ERROR: ')' MISSING ON LINE: " << lineCount << endl;
              source.close();
            }

            else if(y == '}' && stack.peek() != '{'){
              cout << "ERROR: '}' MISSING ON LINE: " << lineCount << endl;
              source.close();
            }

            else if(y == ']' && stack.peek() != '['){
              cout << "ERROR: ']' MISSING ON LINE: " << lineCount << endl;
              source.close();
            }

            else{
            stack.pop();
            delimiter--;
            continue;
            }
          }

          else{
            cout << "FILE HAS NO OPENING DELIMITERS" << endl;
          }
        }
      }
    }
    if(stack.isEmpty()){
      cout << "SYNTAX CHECK COMPLETE, DELIMITER SYNTAX IS CORRECT" << endl;
      cout << "( +/- ) Delimiters: " << delimiter << endl;
      stack.~Stack();
      source.close();
    }

    else{
      cout << "REACHED END OF FILE: MISSING '}' DELIMITER" << endl;
      cout<< "( +/- ) Delimiters: " << delimiter << endl;
      stack.~Stack();
      source.close();
    }
  }

  else{ //"Catch" end of try/catch
    cout << "COULD NOT OPEN FILE" << endl;
    cout << "RESTART WITH DIFFERNT FILE INPUT" << endl;
  }
}

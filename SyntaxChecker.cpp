#include "SyntaxChecker.h"
#include "Stack.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

SyntaxChecker::SyntaxChecker(){


}

SyntaxChecker::~SyntaxChecker(){
  //  delete;
}

void SyntaxChecker::CheckSyntax(){
  delimiter = 0;
  lineCount = 0;

  Stack <char> stack;
  string line; //http://www.cplusplus.com/forum/lounge/52458/ for this line, the next if/else statement and next while loop
  ifstream source;
  source.open(fileInput);
  if(source.is_open()){ //Acting as a try/catch - Try part
    while(source.good()){
      getline(source, line);
      lineCount++;
      for(int x; x < line.length(); ++x){
        char y = line[x];
        if(y == '(' || y == '{'||y == '['){
          stack.push(y);
          delimiter++;
        }
        else if(y == ')' || y == '}'||y == ']'){
          if(stack.isEmpty() == false){
            /*if(){
            }
            else{
              delimiter--;
              source.close();
            }*/
          }
          else{
            cout << "FILE IS MISSING OPENING DELIMITERS" << endl;
          }

        }
        else{


        }

      }
    }
  }
  else{ //"Catch" end of try/catch
    cout << "COULD NOT OPEN FILE" << endl;
    cout << "RESTART WITH DIFFERNT FILE INPUT" << endl;
  }
  source.close();
}

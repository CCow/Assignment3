#include <iostream>
#include <string>

using namespace std;

class SyntaxChecker{
  public:
    SyntaxChecker();
    ~SyntaxChecker();

    void CheckSyntax();

  private:
    string fileInput;

    int lineCount;
    int delimiter;

};

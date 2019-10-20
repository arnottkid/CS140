#include <string>
using namespace std;

class Stacknode {
  public:
    string s;
    Stacknode *next;
};

class Stack {
  public:
    Stack();
    ~Stack();
    int Empty();
    void Push(string s);
    string Pop();
  protected:
    Stacknode *top;
};

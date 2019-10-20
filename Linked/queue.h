#include <string>
using namespace std;

class Qnode {
  public:
    string s;
    Qnode *ptr;
};

class Queue {
  public:
    Queue();
    ~Queue();
    int Empty();
    int Size();
    void Push(string s);
    string Pop();
  protected:
    Qnode *first;
    Qnode *last;
    int size;
};

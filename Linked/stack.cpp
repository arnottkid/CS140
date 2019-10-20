#include <iostream>
#include <cstdlib>
#include "stack.h"
using namespace std;

Stack::Stack()
{
  top = NULL;
}


Stack::~Stack()
{
  Stacknode *next;

  while (top != NULL) {
    next = top->next;
    delete top;
    top = next;
  }
}



int Stack::Empty()
{
  return (top == NULL);
}


void Stack::Push(string s)
{
  Stacknode *newnode;

  newnode = new Stacknode;
  newnode->s = s;
  newnode->next = top;
  top = newnode;
}

string Stack::Pop()
{
  string rv;
  Stacknode *oldtop;

  if (top == NULL) {
    cerr << "Error: pop() called on an empty stack\n";
    exit(1);
  }

  oldtop = top;
  top = oldtop->next;
  rv = oldtop->s;
  delete oldtop;
  return rv;
}

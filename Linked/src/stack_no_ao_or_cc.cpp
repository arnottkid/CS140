#include <iostream>
#include <cstdlib>
#include "stack_no_ao_or_cc.hpp"
using namespace std;

/* This code is the same as src/stack.cpp, except there is no assignment overload
   or copy constructor. */

Stack::Stack()
{
  top = NULL;
  size = 0;
}

void Stack::Clear()
{
  Stacknode *next;

  while (top != NULL) {
    next = top->next;
    delete top;
    top = next;
  }
  
  size = 0;
}

Stack::~Stack()
{
  Clear();
}

bool Stack::Empty() const
{
  return (size == 0);
}

size_t Stack::Size() const
{
  return size;
}

void Stack::Push(const string &s)
{
  Stacknode *newnode;

  newnode = new Stacknode;
  newnode->s = s;
  newnode->next = top;
  top = newnode;
  size++;
}

string Stack::Pop()
{
  string rv;
  Stacknode *oldtop;

  if (top == NULL) throw((string) "Stack::Pop() called on an empty stack");

  oldtop = top;
  top = oldtop->next;
  rv = oldtop->s;
  delete oldtop;

  size--;
  return rv;
}


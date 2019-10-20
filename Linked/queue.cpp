#include "queue.h"
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

Queue::Queue()
{
  size = 0;
  first = NULL;
  last = NULL;
}

Queue::~Queue()
{
  Qnode *ptr;

  while (first != NULL) {
    ptr = first->ptr;
    delete first;
    first = ptr;
  }
}

int Queue::Empty()
{
  return (size == 0);
}


int Queue::Size()
{
  return size;
}


void Queue::Push(string s)
{
  Qnode *newnode;

  newnode = new Qnode;
  newnode->s = s;
  newnode->ptr = NULL;

  if (last == NULL) {
    first = newnode;  
  } else {
    last->ptr = newnode;
  }
  last = newnode;

  size++;
}


string Queue::Pop()
{
  Qnode *oldfirst;
  string rv;

  if (size == 0) {
    cerr << "Error: pop() called on an empty queue\n";
    exit(1);
  }

  rv = first->s;

  oldfirst = first;
  first = oldfirst->ptr;
  delete oldfirst;

  if (first == NULL) last = NULL;

  size--;

  return rv;
}


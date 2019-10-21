#include <iostream>
#include <cstdlib>
#include "stack.hpp"
using namespace std;

/* An empty stack has top pointing to NULL and a zero size.
   Otherwise, the "top" of the stack is the last node pushed,
   and each node points to the next node on the stack.
   The last, "bottom" element points to NULL. 

   The Clear() method deletes all of the nodes on the stack,
   and then resets the top to NULL and the size to zero.
   For that reason, the destructor simply calls clear().
 */

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

/* Empty and Size are simple methods, returning information about the stack's size. */

bool Stack::Empty() const
{
  return (size == 0);
}

size_t Stack::Size() const
{
  return size;
}

/* Push allocates a new node, whose pointer points to the current top of the stack.
   Then, it sets the top of the stack to this new node. */

void Stack::Push(const string &s)
{
  Stacknode *newnode;

  newnode = new Stacknode;
  newnode->s = s;
  newnode->next = top;
  top = newnode;
  size++;
}

/* Pop "unhooks" the top node from the stack, sets s to the string on top,
   and then deletes it.  It throws an exception if the stack is empty.
   That is because it's the user of the stack making a mistake, and throwing
   the exception is a clean way of handling the error. */

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

/* The assignment overload is tricky.  Since we can only traverse the stack
   from top to bottom, what we do is create a temporary stack, which has nodes in 
   reverse order, and then we pop all of its nodes, and push them onto our
   returning stack. */

Stack& Stack::operator= (const Stack &s)
{
  Stack tmp;
  Stacknode *sn;

  /* We need to set these, because the regular constructor is not called, so their
     values are uninitialized.  This is a hard bug to find, btw. */

  size = 0;
  top = NULL;

  for (sn = s.top; sn != NULL; sn = sn->next) tmp.Push(sn->s);
  while (!tmp.Empty()) Push(tmp.Pop());
  return *this;
}

/* The copy constructor simply calls the assignment overload. */

Stack::Stack(const Stack &s)
{
  *this = s;
}

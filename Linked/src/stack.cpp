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

  /* First, clear out any previous stack that you are holding. */
  Clear();

  /* Now copy he stack. */
  for (sn = s.top; sn != NULL; sn = sn->next) tmp.Push(sn->s);
  while (!tmp.Empty()) Push(tmp.Pop());
  return *this;
}

/* We're going to use the assignment overload to implement the copy constructor,
   but remember, when the copy constructor is called, all of the member variables
   (size and top) are uninitialized.  So, we need to set up enough of
   the member variables for the assignment overload to work.  The first thing
   that it does is call Clear(), and you'll note that the only member variable
   that Clear() accesses is top.  So, setting up top to be NULL is the only
   thing that we need to do before calling the assignment overload. */

Stack::Stack(const Stack &s)
{
  top = NULL;
  *this = s;
}

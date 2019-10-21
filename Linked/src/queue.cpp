#include "queue.hpp"
#include <iostream>
using namespace std;

/* The way that queues work is as follows:

   - There are pointers to the first and last nodes.  If the queue is empty, these are NULL.
   - Each node points to the node behind it in the queue.  That way, when you delete the
     first element on the queue, you can find the next element and set "first" to be that
     element.  When you push, you have the last element point to the new element, and then
     update the "last" pointer.
 */

/* Simple Constructor. */

Queue::Queue()
{
  size = 0;
  first = NULL;
  last = NULL;
}

/* As with stacks, the destructor calls clear. */
Queue::~Queue()
{
  Clear();
}

/* Also like stacks, we don't implement Clear() by repeatedly calling Pop().
   Instead, we traverse the nodes, deleting each one, and then at the end
   reset size, first and last. */

void Queue::Clear()
{
  Qnode *ptr;

  while (first != NULL) {
    ptr = first->ptr;
    delete first;
    first = ptr;
  }
  size = 0;
  last = NULL;
}

/* Empty and Size are both straightforward: */

bool Queue::Empty() const
{
  return (size == 0);
}


size_t Queue::Size() const
{
  return size;
}

/* As mentioned above, Push() creates a new node and then puts it at the end
   of the last, by having the last node point to it.  We need special case
   code for when the queue is empty. */

void Queue::Push(string s)
{
  Qnode *newnode;

  newnode = new Qnode;      // Create the new node. 
  newnode->s = s;
  newnode->ptr = NULL;

  if (last == NULL) {       // If the queue is empty, set first to be this new node. 
    first = newnode;  
  } else {                  // If the queue is non-empty, set the pointer of the last node to be this new node. 
    last->ptr = newnode; 
  }


  last = newnode;           // Finally, set last to point to the new node, and increment size.

  size++;
}

/* Pop is actually very similar to the stack code.  You save the first string,
   save a pointer to the first node, set "first" to point to the next node,
   and delete the first node. */

string Queue::Pop()
{
  Qnode *oldfirst;
  string rv;

  if (size == 0) throw((string) "Queue::Pop() called on an empty queue");


  /* Move "first" to point to the next node, store the return value, and
    delete the previous first node. */

  rv = first->s;
  oldfirst = first;            
  first = oldfirst->ptr;
  delete oldfirst;

  /* Handle the empty queue. */

  if (first == NULL) last = NULL;

  /* Update size and return. */

  size--;
  return rv;
}

/* The assignment overload traverses the nodes and pushes each one. */

Queue& Queue::operator= (const Queue &q)
{
  Qnode *tmp;
  Clear();
  for (tmp = q.first; tmp != NULL; tmp = tmp->ptr) Push(tmp->s);
  return *this;
}

Queue::Queue(const Queue &q)
{
  *this = q;
}

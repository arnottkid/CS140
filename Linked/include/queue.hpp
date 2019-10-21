#pragma once
#include <string>

/* This defines the nodes of the queue.  It's only used internally to
   the queue, but we have to define it here.  */

class Qnode {
  public:
    std::string s;
    Qnode *ptr;
};

/* Here's the Queue class. */

class Queue {
  public:

    /* Constructors, Destructor, Assignment Overload */

    Queue();
    Queue(const Queue &q);
    Queue& operator= (const Queue &q);
    ~Queue();

    /* Same operators as stacks. */

    void Clear();
    bool Empty() const;
    size_t Size() const;

    /* Push puts the string on the end of the queue, 
       and Pop removes the string from the beginning of the queue. */

    void Push(std::string s);
    std::string Pop();

  protected:
    Qnode *first;           // Pointer to the first node on the queue.
    Qnode *last;            // Pointer to the last node on the queue.
    int size;               // The queue's size.
};

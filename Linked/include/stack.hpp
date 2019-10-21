#pragma once
#include <string>

/* The "stacknode" class is how we implement the stack.  It is an unfortunate matter
   that this needs to be in the header file, because it is unnecessary (and perhaps
   bad) for users of the Stack class to see its internals.  Later, I will show you
   how to get rid of it, but I don't want to confuse matters now. */

class Stacknode {
  public:
    std::string s;
    Stacknode *next;
};

/* Here is the stack class.  This is a data structure that holds strings in a
  "Last in, first out" manner.  */

class Stack {
  public:
 
    Stack();                               // Regular constructor
    Stack(const Stack &s);                 // Copy constructor
    Stack& operator= (const Stack &s);     // Assignment overload
    ~Stack();                              // Destructor
    void Clear();                          // Clear it out

    void Push(const std::string &s);   // This puts a string on the stack.
    std::string Pop();                 // This removes a string from the stack.
    
    bool Empty() const;                // These return information about the stack.
    size_t Size() const;
  protected:
    Stacknode *top;                    // This is how the stack is implemented.
    size_t size;
};

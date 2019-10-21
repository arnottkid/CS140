#pragma once
#include <string>

/* This is identical to stack.hpp, except I have deleted the assignment overload
   and copy constructor. */

class Stacknode {
  public:
    std::string s;
    Stacknode *next;
};

class Stack {
  public:
 
    Stack();                               
    ~Stack();                               
    void Clear();                          

    void Push(const std::string &s);   
    std::string Pop();                 
                                       
    bool Empty() const;                
    size_t Size() const;
  protected:
    Stacknode *top;                    
    size_t size;
};

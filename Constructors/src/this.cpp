/* A program to demonstrate "this" */

#include <iostream>
#include <cstdio>
using namespace std;

class Person {
  public:
    string Name;
    int Age;
    void Print(); 
};

/* Print_Person() take a pointer to a person, and prints out
   the person with some formatting. */

void Print_Person(Person *p)
{
  printf("Person: %s - Age = %d\n", p->Name.c_str(), p->Age);
}

/* The Print() method uses Print_Person() -- this is a pointer
   to the instance which is calling Print(). */

void Person::Print()
{
  Print_Person(this);
}

/* In main(), we read in pairs of (name,age), and then use the
   Print() method of the Person class to print the person. */

int main()
{
  Person p;
  
  while (cin >> p.Name >> p.Age) p.Print();
  return 0;
}

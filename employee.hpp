#ifndef employee_h
#define employee_h

#include "book.hpp"
#include "person.hpp"

class Employee: public Person
{
  public:

  Employee(std::string = "-", std::string = "-", double = 0);
  ~Employee();

  friend std::ostream& operator << (std::ostream&, Employee&);
  Employee& operator= (Employee &e2);
};

#endif

#ifndef employee_h
#define employee_h

#include "book.hpp"
#include "person.hpp"

class Employee: public Person
{
  double salary;
  public:

  Employee(std::string = "-", std::string = "-", double = 0, double = 0);
  ~Employee();
  double get_salary() {return salary;}
  void set_salary(double sal) {salary = sal;}

  friend std::ostream& operator << (std::ostream&, Employee&);
  Employee& operator= (Employee &e2);
};

#endif

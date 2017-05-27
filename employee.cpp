#include"employee.hpp"

Employee::Employee(std::string n, std::string s, double m): Person(n, s, m)
{
  D(std::cout<<"Zatrudniamy pracownika"<<std::endl;)
}

Employee::~Employee()
{
  D(std::cout<<"Zwalniamy pracownika."<<std::endl;)
}

std::ostream& operator<< (std::ostream &os, Employee &e)
{
  os<<e.get_name()<<" "<<e.get_surname()<<" "<<e.get_money()<<"zl"<<std::endl; return os;
}

Employee& Employee::operator= (Employee &e2)
{
  this->name = e2.get_name();
  this->surname = e2.get_surname();
  this->money = e2.get_money();
  return *this;
}

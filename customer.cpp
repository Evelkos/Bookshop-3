#include "customer.hpp"

Customer::Customer(std::string n, std::string s, double m): Person(n, s, m)
{
  D(std::cout<<"Tworzymy klienta"<<std::endl;)
}

Customer::~Customer()
{
  D(std::cout<<"Usuwamy kilenta"<<std::endl;)
}

std::ostream& operator<<(std::ostream &os, Customer &c)
{
  os << c.get_name()<<" "<<c.get_surname() <<" "<<c.get_money()<<std::endl;
  return os;
}

//operator przypisania - nie likwiduje listy ksiazek klienta, ktorego dane ulegly zmianie (w programie nie jest to potrzebne)
Customer& Customer::operator = (Customer &c2)
{
  this->name = c2.get_name();
  this->surname = c2.get_surname();
  this->money = c2.get_money();
  return *this;
}
/*
void Customer::buy(Book &bo)
{
  int i;

  if(this->get_money() >= bo.b->get_price())
  {
    this->set_money(this->get_money() - bo.b->get_price());
    bo.n--;
  }

  else
    std::cout<<"-Mam zbyt malo pieniedzy. Nie moge kupic tej ksiazki"<<std::endl;
}*/

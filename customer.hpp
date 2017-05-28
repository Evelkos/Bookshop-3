#ifndef customer_h
#define customer_h

#include<vector>
#include "book.hpp"
#include "person.hpp"

class Customer : public Person
{
  public:
  Customer(std::string = "Klient", std::string = "Ksiegarni", double = 0);
  ~Customer();

  void buy(Book&);
  void work();

  void operator +=(double m) {this->set_money(this->get_money() + m);}
  friend std::ostream& operator<< (std::ostream&, Customer&);
  Customer& operator= (Customer &c2);
};

#endif

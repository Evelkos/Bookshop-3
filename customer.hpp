#ifndef customer_h
#define customer_h

#include<vector>
#include "book.hpp"
#include "person.hpp"

class Customer : public Person
{
  std::vector<Book*> coll;  //wektor wskazan na ksiazki

  public:
  Customer(std::string = "-", std::string = "-", double = 0);
  ~Customer();

  void add_book(Book*);
  void show_b();
  void buy(Book&);


  void operator +=(double m) {this->set_money(this->get_money() + m);}
  friend std::ostream& operator<< (std::ostream&, Customer&);
  Customer& operator= (Customer &c2);
};

#endif

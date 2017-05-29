#ifndef owner_hpp
#define owner_hpp

#include "bookshop.hpp"
#include "person.hpp"
#include "functions.hpp"

class Owner: public Person
{
  std::vector<Bookshop*> bs;

  public:
  Owner(std::string = "Wlasciciel", std::string = "Ksiegarni", double = 0.0);
  ~Owner();
  unsigned get_size() {return bs.size();}
  Bookshop* get_bs(unsigned n) {return bs[n];}

  void show_bs();
  void add_bs();
  void add_bs(char*, char*, unsigned, double);
  void show_order(Bookshop*);
  void delete_bs(unsigned);
  void delete_bs();
  void accept(Bookshop*);
  void get_cash(Bookshop*);
};

#endif // owner_hpp

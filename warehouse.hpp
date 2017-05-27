#ifndef warehouse_hpp
#define warehouse_hpp

#include "building.hpp"

class Warehouse: public Building
{
  public:

  std::vector<Bookn> bo;
  void show_books();

  Warehouse(std::string n, std::string l, unsigned int a): Building(n, l, a) {};
};

#endif // warehouse_hpp

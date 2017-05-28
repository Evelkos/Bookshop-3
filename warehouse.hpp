#ifndef warehouse_hpp
#define warehouse_hpp

#include "building.hpp"

class Warehouse: public Building
{
  protected:
  std::vector<Bookn> bo;

  public:
  Warehouse(std::string n, std::string, int);
  ~Warehouse();
  virtual void show();                  //wyswietla liste ksiazek znajdujacych sie w magazynie
  virtual void reset();                 //"resetuje" liczbe ksiazek w magazynie (ustawia wszystkie na okreslona liczbe)
  void add(int, int, Book*);            //dodaje nowa (juz utworzona) ksiazke do magazynu
  void add_all(int, std::vector<Book*>&);//dodaje do magazynu wszystkie ksiazki z wektora ksiazek

  Warehouse(std::string n = "Magazyn", std::string l = "Miasto", unsigned int a = 100): Building(n, l, a) {};
  friend std::ostream& operator << (std::ostream&, Warehouse&);
};

#endif // warehouse_hpp

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

  unsigned get_bo_size() {return bo.size();}
  Book* get_bo_b(unsigned n) {n%=bo.size(); return bo[n].b;}
  Bookn* get_bo(unsigned n) {n%=bo.size(); return &(bo[n]);}

  virtual void show();                  //wyswietla liste ksiazek znajdujacych sie w magazynie
  virtual void reset();                 //"resetuje" liczbe ksiazek w magazynie (ustawia wszystkie na okreslona liczbe)
  void add(unsigned, Book*);            //dodaje nowa (juz utworzona) ksiazke do magazynu
  void add_all(unsigned, std::vector<Book*>&);//dodaje do magazynu wszystkie ksiazki z wektora ksiazek
  void delete_b(unsigned n);
  void delete_b();

  Warehouse(std::string n = "Magazyn", std::string l = "Miasto", unsigned int a = 100): Building(n, l, a) {};
  friend std::ostream& operator << (std::ostream&, Warehouse&);
};

#endif // warehouse_hpp

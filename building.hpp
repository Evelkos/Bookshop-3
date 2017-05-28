#ifndef building_hpp
#define building_hpp

#include <vector>  //bo potrzebny w klasach pochodnych (wszystkich)
#include "book.hpp"

const unsigned int factor = 5; //wspolczynnik: na ilu metrach kwadratowych miesci sie jeden rodzaj ksiazek

class Building
{
  protected:
  std::string name, loc;
  unsigned int area;  //powiazane z iloscia ksiazek jakie mozna trzymac na danej powierzchni


  public:
  Building(std::string n, std::string l, unsigned int a): name(n), loc(l), area(a) {}
  std::string get_name() {return name;}
  std::string get_loc() {return loc;}
  unsigned int get_area() {return area;}
  void set_name(std::string n) {name = n;}
  void set_loc(std::string l) {loc = l;}
  void set_area(unsigned int a) {area = a;}

  void virtual show() = 0;
  void virtual reset() = 0;
};

#endif // buildinh_hpp

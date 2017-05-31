#ifndef building_hpp
#define building_hpp

#include <vector>  //bo potrzebny w klasach pochodnych (wszystkich)
#include "book.hpp"

const unsigned int factor = 5; //wspolczynnik: na ilu metrach kwadratowych miesci sie jeden rodzaj ksiazek
const unsigned int factor1 = 20; //wspolczynnik: na ilu metrach kwadratowych moze minimalnie mieszkac jeden mieszkaniec

class Building
{
  protected:
  std::string name, loc;
  unsigned int area;  //powiazane z iloscia ksiazek jakie mozna trzymac na danej powierzchni


  public:
  Building(std::string n, std::string l, unsigned int a): name(n), loc(l), area(a) {}
  virtual ~Building() {};
  std::string get_name() {return name;}
  std::string get_loc() {return loc;}
  unsigned int get_area() {return area;}
  void set_name(std::string n) {name = n;}
  void set_loc(std::string l) {loc = l;}
  void set_area(unsigned int a) {area = a;}

  void virtual show() = 0;
  void virtual reset() = 0;
  //friend std::ostream& operator<< (std::ostream&, Building&);
};

//std::ostream& operator<< (std::ostream &os, Building &b)
//{
//  os<<b.get_name()<<" "<<b.get_loc()<<" "<<b.get_area()<<std::endl;
  //return os;
//}

#endif // buildinh_hpp

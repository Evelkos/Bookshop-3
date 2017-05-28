#ifndef house_h
#define house_h

#include "building.hpp"
#include "customer.hpp"
#include "employee.hpp"
#include <vector>

template<typename Per>          //osoba
class House: public Building   //dom, w ktorym mieszka jedna rodzina
{
  public:
  std::vector<Per> inhab;       //mieszkancy domu
  std::vector<Book*> shelf;     //polka na ksiazki

  House<Per>(std::string n = "Dom", std::string l = "Miasto", unsigned int a = 100): Building(n, l, a) {};
  friend std::ostream& operator << (std::ostream& os, House<Per>& h)     //wyswietla wszystkich mieszkancow domu
  {
    unsigned int i;
    for(i = 0 ; i < (h.inhab).size() ; i++)
      os<<h.inhab[i].get_name()<<" "<<h.inhab[i].get_surname()<<" "<<h.inhab[i].get_money()<<std::endl;
    return os;
  }
  void add(Book *bn, int pos);
  void virtual show();
  void virtual reset();
};

//wirtualna funkcja show - wyswietlanie ksiazek znajdujacych sie na polce
template<typename Per>
void House<Per>::show()
{
  unsigned int i;
  for(i = 0 ; i < shelf.size() ; i++)
    std::cout<<*(shelf[i]);
}

//wirtualnia funkcja reset - usuniecie wszystkich ksiazek z polki
template<typename Per>
void House<Per>::reset()  {  shelf.clear();  }

//wstawianie nowo zakupionych ksiazek na polke
template<typename Per>
void House<Per>::add(Book *bn, int pos)
{
  if(shelf.size() < shelf.max_size() && area > shelf.size()/factor)
    shelf.insert(shelf.begin()+pos, 1, bn);
}

#endif // house_h

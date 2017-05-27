#ifndef house_h
#define house_h

#include "customer.hpp"
#include "employee.hpp"
#include <vector>

template<typename Per>          //osoba
class House                     //dom, w ktorym mieszka jedna rodzina
{
  public:
  std::vector<Per> inhab;       //mieszkancy domu
  std::vector<Bookn> shelf;     //polka na ksiazki

  friend std::ostream& operator << (std::ostream& os, House<Per>& h)     //wyswietla wszystkich mieszkancow domu
  {
    unsigned int i;
    for(i = 0 ; i < (h.inhab).size() ; i++)
      os<<h.inhab[i].get_name()<<" "<<h.inhab[i].get_surname()<<" "<<h.inhab[i].get_money()<<std::endl;
    return os;
  }
  void virtual show();
};

template<typename Per>
void House<Per>::show()
{
  unsigned int i;
  for(i = 0 ; i < shelf.size() ; i++)
    std::cout<<*(shelf[i].b)<<std::endl;
}

#endif // house_h

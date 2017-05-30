#ifndef house_h
#define house_h

#include "building.hpp"
#include "customer.hpp"
#include "employee.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>

template<typename Per>          //osoba
class House: public Building    //dom, w ktorym mieszka jedna rodzina
{
  std::vector<Per*> inhab;       //mieszkancy domu
  std::vector<Book*> shelf;     //polka na ksiazki

  public:
  House<Per>(std::string = "Dom", std::string = "Miasto", unsigned int = 100);
  ~House<Per>();
  void add(Book *bn, int pos);
  void add_inhab(unsigned int, std::vector<std::string*>&, std::vector<std::string*>&);
  Per* get_inhab(unsigned n) {n%=inhab.size(); return inhab[n];};
  void virtual show();
  void virtual reset();

  friend std::ostream& operator << (std::ostream& os, House<Per>& h)     //wyswietla wszystkich mieszkancow domu
  {
    for(unsigned i = 0 ; i < h.inhab.size() ; i++){os<<h.inhab[i]->get_name()<<" "<<h.inhab[i]->get_surname()<<" "<<h.inhab[i]->get_money()<< "   ";}
    os<<std::endl;
    return os;
  }
};

template<typename Per>
House<Per>::House(std::string n, std::string l, unsigned int a): Building(n, l, a)
{
  D(std::cout<<"Tworze dom"<<std::endl;)
}

template<typename Per>
House<Per>::~House()
{
  Per *p;
  shelf.clear();
  while(!inhab.empty())
  {
    p = inhab[inhab.size()-1];
    inhab.pop_back();
    delete p;
  }
  D(std::cout<<"Usuwamy dom"<<std::endl;)
}

//wirtualna funkcja show - wyswietlanie ksiazek znajdujacych sie na polce
template<typename Per>
void House<Per>::show()
{
  unsigned int i;
  if(shelf.size() > 0)
  {
    std::cout<<"Lista ksiazek rodziny:"<<std::endl;
    for(i = 0 ; i < shelf.size() ; i++)
      std::cout<<*(shelf[i]);
  }

  else
    std::cout<<"Nie ma jeszcze zanych ksiazek"<<std::endl;
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

template<typename Per>
void House<Per>::add_inhab(unsigned int n, std::vector<std::string*> &names, std::vector<std::string*> &surnames)
{
  unsigned int i;
  Per *pe;
  std::string sur, nam;

  if(!surnames.empty())
  {
    i = rand()%(surnames.size());
    sur = *surnames[i];
  }
  else      sur = "Kowalski";

  srand(time(NULL));
  while(n > 0 && area/factor1 > this->inhab.size())
  {
    if(!names.empty())
    {
      i = rand()%(names.size());
      nam = *names[i];
    }
    else    nam = "Jan";
    i = rand()%20000+5000;
    pe = new Per(nam, sur, i/100);
    this->inhab.push_back(pe);
    n--;
  }
}

#endif // house_h

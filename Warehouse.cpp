#include "warehouse.hpp"
#include "functions.hpp"

Warehouse::Warehouse(std::string n, std::string l, int a): Building(n, l, a){}

std::ostream& operator << (std::ostream &os, Warehouse &w)
{
  os<<w.name<<"  "<<w.loc<<"  "<<w.area<<std::endl;
  return os;
}

void Warehouse::show()
{
  unsigned int i;
  if(bo.empty())
    std::cout<<"Nie ma jeszcze zadnych ksiazek"<<std::endl;
  else
    for(i = 0 ; i < bo.size() ; i++)
      std::cout<<*(bo[i].b);
}

//cotygodniowe uzupelnianie magazynu
void Warehouse::reset()
{
  unsigned int i;
  for(i = 0 ; i < bo.size() ; i++)
  bo[i].n = 10;
}

//dodawanie pojedynczej ksiazki do magazynu - ma isc w parze z tworzeniem nowej ksiazki
void Warehouse::add(int n, int pos, Book *bn)
{
  Bookn boo;
  boo.b = bn;
  boo.n = 0;

  if(bo.size() < bo.max_size() && area > bo.size()/factor)
    bo.insert(bo.begin()+pos, 1, boo);
}

//dodawanie ksiazek do magazynu na poczatku dzialania programu - dodaje wszystkie ksiazki
void Warehouse::add_all(int n, std::vector<Book*> &books)
{
  unsigned int i;
  Bookn boo;
  boo.n = n;

  for(i = 0 ; i < books.size() ; i++)
  {
    boo.b = books[i];
    if(bo.size() < bo.max_size() && area > bo.size()/factor)
      bo.push_back(boo);
    else
      break;
  }
}

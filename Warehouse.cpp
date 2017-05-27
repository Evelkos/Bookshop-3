#include "warehouse.hpp"

void Warehouse::show_books()
{
  unsigned int i;
  if(bo.empty())
    std::cout<<"Nie ma jeszcze zadnych ksiazek"<<std::endl;
  else
    for(i = 0 ; i < bo.size() ; i++)
      std::cout<<*(bo[i].b);
}

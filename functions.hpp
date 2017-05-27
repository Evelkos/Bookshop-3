#ifndef functions_hpp
#define functions_hpp

#include <vector>
#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include "book.hpp"

char* load(char*, int);
double load_n();
void data(std::vector<Book*>&, std::vector<std::string*>&, std::vector<std::string*>&);
void delete_data(std::vector<Book*>&, std::vector<std::string*>&, std::vector<std::string*>&);

template<typename T>
void show_vec(std::vector<T> &vec)
{
  unsigned int i;
  for(i = 0 ; i < vec.size() ; i++)
    std::cout<<vec[i];
}

template<typename T>
int position(std::vector<T*>& vec, T *ob)
{
  unsigned int i = 1;
  if(vec.empty() || *ob < *(vec[i]) || *ob == *(vec[i])){
    i = 1;
    std::cout<<"Tu dziala - pos"<<std::endl;}
  else
  {
    while(i < vec.size())
    {
      if(*ob < *(vec[i]))
        break;
      i++;
    }
  }
  return i-1;
}


#endif // functions_hpp

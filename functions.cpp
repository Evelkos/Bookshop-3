#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include "book.hpp"

template<typename T>
int position(std::vector<T>& vec, T& ob)
{
  unsigned int i = 0;
  if(vec.empty() == true || ob < vec[i] || ob == vec[i])
    i = 1;
  else
  {
    while(i+1 <= vec.size())
    {
      if(ob > vec[i])
        break;
      i++;
    }
  }
  return i;
}

//wczytuje ciag wyrazow, dlugosc ciagu ograniczona
char* load(char *words, int length){
	char *result;
	char *wEnd;  //koniec ciagu wyrazow
	result = fgets(words, length, stdin);
	if(words != NULL){
		wEnd = strchr(words, '\n');
		if(wEnd != NULL)
			*wEnd = '\0';
		else{
			while(getchar() != '\n');
		}
	}
	return result;
}

//wczytuje liczbe
double load_n(){
  char number[10];
  unsigned int i, j = 0;
  double result = 0;

  load(number, 10);
  for(i = 0 ; i < strlen(number) ; i++)
  {
    if((number[i] - '0') >= 0 && (number[i] - '0') <=9)  //wczytywanie cyfr, pomijanie innych znakow (poza '.')
      result = result*10+(number[i] - '0');
    else if(number[i] == '.')                          //wystapil znak '.' => liczba bedzie miala czesc dziesietna
    {
      for(i++; i < strlen(number) ; i++)
      {
        if(number[i] - '0' >= 0 && number[i] - '0' <=9 && j == 0)  //wystapienie pierwszej cyfry po kropce
        {
          result += 0.1*(number[i] - '0');
          j++;
        }
        else if(number[i] - '0' >= 0 && number[i] - '0' <=9 && j == 1)  //wystapienie drugiej cyfry po kropce
          {
            result += 0.01*(number[i] - '0');
            break;
          }
      }
      break;
    }
  }
  return result;
}


void data(std::vector<Book> &books, std::vector<std::string> &names, std::vector<std::string> &surnames)
{
  int n = 0;
  Book bo;
  std::string line;
  int y, pag;

  srand(time(NULL));


  std::ifstream file;
  file.open( "data.txt" );

  if(file.good() == false)
    std::cout<<"BLAD: blad podczas odczytu bliku"<<std::endl;
  else
  {
    while(!file.eof())
    {
      getline(file, line);
      if(line[0] == '#' && books.size() < books.max_size())      //wczytujemy ksiazke
      {
        getline(file, line);
        bo.set_name(line);
        getline(file, line);
        bo.set_author(line);
        getline(file, line);
        bo.set_publisher(line);
        y = rand()%50+1967;
        bo.set_year(y);
        pag = rand()%400+154;
        bo.set_pages(pag);
        n = position(books, bo);
//        books.insert(books.begin() + n -1 , 1 , bo);
      }
      else if(line[0] == '%')
      {
        getline(file, line);
        while(line[0] != '%')
        {
          if(names.size() < names.max_size())
            names.push_back(line);
        }
      }
      else if(line[0] == '*')
      {
        getline(file, line);
        while(line[0] != '*')
        {
          if(surnames.size() < surnames.max_size())
            surnames.push_back(line);
        }
      }
      else
        continue;
    }
  }
}


template<typename T>
void show_vec(std::vector<T> &vec)
{
  unsigned int i;
  for(i = 0 ; i < vec.size() ; i++)
    std::cout<<vec[i];
}

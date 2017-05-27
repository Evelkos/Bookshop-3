#ifndef book_h
#define book_h

#include "debug_head.hpp"
#include <iostream>
#include <cstdlib>

enum category
{
  fantasy,
  dokument,
  komiks
};

class Book
{
  std::string name, author, publisher;
  float price;
  unsigned int year, pages;
 // category cat;

  public:
  Book(std::string = "-", std::string = "-", std::string = "-", float = 0.0, int = 0, int = 0);
  ~Book();

  std::string get_name()            {return name;}
  std::string get_author()          {return author;}
  std::string get_publisher()       {return publisher;}
  float get_price()                 {return price;}
  unsigned int get_year()           {return year;}
  unsigned int get_pages()          {return pages;}
//  category get_cat()                {return cat;}

  void set_name(std::string n)      {name = n;}
  void set_author(std::string a)    {author = a;}
  void set_publisher(std::string p) {publisher = p;}
  void set_price(float pr)          {price = pr;}
  void set_year(int y)              {year = y;}
  void set_pages(int pag)           {pages = pag;}
//  void stt_category(category c)     {cat = c;}

  friend std::ostream& operator<<  (std::ostream &os, Book &b);
  friend std::istream& operator >> (std::istream&, Book&);
  Book& operator = (Book &b2);
  bool operator > (Book &b2);
  bool operator < (Book &b2);
  bool operator == (Book& o);
};

//ma byc jedna lista ksiazek - u klienta/w ksiegarni - tylko wskazanie na wybrany tytul
struct Bookn
{
  Book *b;
  unsigned int n;       //ilosc ksiazek "na stanie"
};

float quantity_pr(int, int);

#endif

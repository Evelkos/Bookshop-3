#include"book.hpp"

Book::Book(std::string n, std::string a, std::string p, float pr, int y, int pag): name(n), author(a), publisher(p), price(pr), year(y), pages(pag)
{
  D(std::cout <<"Tworze ksiazke"<<std::endl;)
}


Book::~Book()
{
  D(std::cout<<"Usuwamy ksiazke!"<<std::endl;)
}


std::ostream& operator << (std::ostream &os, Book &b)
{
  os<<b.name<<"  "<<b.author<<"  "<<b.publisher<<"  "<<2*(b.price)<<"  "<<b.year<<"  "<<b.pages<<"  "<<std::endl;
  return os;
}


std::istream& operator >> (std::istream &is, Book &b)
{
  is>>b.name>>b.author>>b.publisher>>b.price>>b.year>>b.pages;
  return is;
}


Book& Book::operator = (Book &b2)
{
  this->name = b2.get_name();
  this->author = b2.get_author();
  this->publisher = b2.get_publisher();
  this->price = b2.get_price();
  this->year = b2.get_year();
  this->pages = b2.get_pages();
//  this->cat = b2.get_cat();
  return *this;
}

bool Book::operator > (Book &b2)
{
  bool f;
  if(this->name > b2.get_name())
    f = true;
  else
  {
    if(this->author > b2.get_author())
      f = true;
    else
    {
      if(this->publisher > b2.get_publisher())
        f = true;
      else
        f = false;
    }
  }
  return f;
}

bool Book::operator<(Book &b2)
{
  bool f;
  if(this->name < b2.get_name())
    f = true;
  else
  {
    if(this->author < b2.get_author())
      f = true;
    else
    {
      if(this->publisher < b2.get_publisher())
        f = true;
      else
        f = false;
    }
  }
  return f;
}

bool Book::operator == (Book& o)
{
  bool i = false;
  if(this->get_name() == o.get_name() && this->get_author() == o.get_author() && this->get_publisher() == o.get_publisher())
    i = true;
  return i;
}

//wylicza cene hurtowa ksiazki
float quantity_pr(int year, int pages)
{
    return year*pages/44000;
}

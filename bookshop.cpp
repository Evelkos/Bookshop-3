#include "bookshop.hpp"
#include <ctime>

int Bookshop::numBookshops = 0;

//konstruktor
Bookshop::Bookshop(std::string n, std::string l, unsigned int a, double b): Warehouse(n, l , a), budget(b)
{
  numBookshops++;
  D(std::cout <<"Tworze ksigarnie"<<std::endl;)
}

//destruktor
Bookshop::~Bookshop()
{
  House<Customer> *c;
  House<Employee> *e;

  numBookshops--;

  while(cust.size() > 0)
  {
    std::cout<<"AAAAAAAAAAAA - usuwanie klientow?"<<std::endl;
    c = cust[cust.size()-1];
    cust.pop_back();
    delete c;
  }
  while(emp.size() > 0)
  {
    std::cout<<"BBBBBBBBBBB - usuwanie pracownikow?"<<std::endl;
    e = emp[emp.size()-1];
    emp.pop_back();
    delete e;
  }
  D(std::cout <<"Niszcze ksigarnie"<<std::endl;)
}

//przeciazenie operatora przypisania, ord, emp, cust - nie kopiuja sie
Bookshop& Bookshop::operator = (Bookshop &b2)
{
  this->set_name(b2.get_name());
  this->set_loc(b2.get_loc());
  this->set_budget(b2.get_budget());
  this->ord.clear();
  this->emp.clear();
  this->cust.clear();
  return *this;
}

//przeciazenie operatora wyjscia
std::ostream& operator << (std::ostream &os, Bookshop &b)
{
  os<<b.get_name()<<" "<<b.get_loc()<<" "<<b.get_budget()<<std::endl;
  return os;
}

//wyswietla liste klientow ksiegarni
void Bookshop::show_customers()
{
  unsigned int i;
  if(cust.empty())
    std::cout<<"Nie ma jeszcze zadnych klientow"<<std::endl;
  else
  {
    std::cout<<"Lista klientow:"<<std::endl;
    for(i = 0 ; i < cust.size() ; i++)
      std::cout<<*(cust[i]);
  }
}

//wyswietla liste pracownikow, zwraca ich liczbe
void Bookshop::show_employees()
{
  unsigned int i;
  if(emp.empty())
    std::cout<<"Nie ma jeszcze zaznych pracownikow"<<std::endl;
  else
  {
    std::cout<<"Lista pracownikow:"<<std::endl;
    for(i = 0 ; i < emp.size() ; i++)
      std::cout<<*(emp[i]);
  }
}

//wyswietla aktywne zamowienie
void Bookshop::show_ord()
{
  unsigned int i;
  if(ord.empty())
    std::cout<<"Zadne zamowienie nie jest aktualnie zlozone"<<std::endl;
  else
  {
    std::cout<<"Zamowienie:"<<std::endl;
    for(i = 0 ; i < ord.size() ; i++)
      std::cout<<*(ord[i].b);
  }
}


//tworzy nowa rodzine - klientow
//podajemy: liczbe czlonkow rodziny, nazwe budynku, jego lokalizacje, powierzchnie oraz dwa wektory: imion i nazwisk
void Bookshop::add_customers(unsigned n, std::string na, std::string l, unsigned a, std::vector<std::string*> &names, std::vector<std::string*> &surnames)
{
  House<Customer> *h;
  if(cust.size() < cust.max_size())
  {
   h = new House<Customer>(na, l, a);
   h->add_inhab(n, names, surnames);
   cust.push_back(h);
  }
}

//tworzy nowego pracownika
void Bookshop::add_employee(std::string na, std::string l, unsigned a, std::vector<std::string*> &names, std::vector<std::string*> &surnames)
{
  House<Employee> *h = nullptr;
  if(emp.size() < emp.max_size())
  {
   h = new House<Employee>(na, l, a);
   h->add_inhab(1, names, surnames);
   emp.push_back(h);
  }
}

/*
//wyswietla liste kandydatow
void Bookshop::choose_emp(names, surnames)
{
  int n[10];
  unsigned i;


  if(names.size() <= 0)   {  names.resize(10);     names.push_back("Jan");  }
  if(surnames.size() <= 0){  surnames.resize(10);  surnames.push_back("Kowalski")}

  for(i = 0 ; i < 5 ; i++)
  {
    srand(time(NULL));
    if(names.size() < names.max_size())
      n[i] = rand()%(names.size());
    if(surnames.size() < surnames.max_size())
      n[i+1] = rand()%(surnames.size());
    std::cout<<i<<". "<<names[i]<<" "<<surnames[i+1]<<std::endl;
  }

  std::cout<<"Wybierz numer kandydata: ";
}*/

/*
//wysylanie zamowienia (w domysle: przez pracownika)
void Bookshop::order_e()
{
  int n, number;  //number - ilosc egzemplarzy danej ksiazki w ksiegarni
  List<Book> *curr = firstB;

  if(firstB != NULL)
  {
    std::cout<<"Tworzenie zamowienia:"<<std::endl;
    do
    {
      n = -1;
      std::cout<<"\""<<curr->get_obj()->get_name()<<"\"  "<<curr->get_obj()->get_author()<<"  "<<curr->get_obj()->get_publisher()<<std::endl;
      std::cout<<"Ilosc potrzebnych egzemplarzy: "<<curr->get_obj()->get_nOrd()<<std::endl;

      while(n < curr->get_obj()->get_nOrd()){std::cout<<"Zamow: ";  n = load_n();}
      if(n > 0)
      {
        number = curr->get_obj()->get_number();
        curr->get_obj()->set_number(n);               //ustawianie odpowiedniego zamawianych ezemplarzy
        order = new_o(order, *(curr->get_obj()));
        curr->get_obj()->set_number(number);          //powrot do odpowiedniej liczby egzemplarzy w ksiegarni
        curr->get_obj()->set_nOrd(0);
      }
      curr = curr->get_next();
    }while(curr != firstB);

    if(this->get_order() != NULL)
    {
      std::cout<<"Zlozono zamowienie: "<<std::endl;
      show_l(order);
      this->set_oA(1);
    }
  }
}
*/
//usuwa ksiazke o zadanym numerze, zwraca do budzetu 30% ceny hurtowej egzemplarzy
void Bookshop::delete_book(int n){ bo.erase(bo.begin()+n); }

//usuwa klienta, ktorego numer zostal dany
void Bookshop::delete_customers(int n){ cust.erase(cust.begin()+n); }

//usuwa pracownika, ktorego numer zostal dany
void Bookshop::delete_employee(int n){ emp.erase(emp.begin()+n); }

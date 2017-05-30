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
    std::cout<<std::endl<<"Lista klientow:"<<std::endl;
    for(i = 0 ; i < cust.size() ; i++)
      std::cout<<i+1<<". "<<*(cust[i]);
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
    std::cout<<std::endl<<"Lista pracownikow:"<<std::endl;
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

void Bookshop::add_customers(std::vector<std::string*> &names, std::vector<std::string*> &surnames)
{
  unsigned n, a;
  std::cout<<"Podaj liczbe czlonkow nowej rodziny: ";
  n = load_n();
  std::cout<<"Podaj metraz domu danej rodziny: ";
  a = load_n();
  add_customers(n, "Dom", loc, a, names, surnames);
}

//tworzy nowego pracownika
void Bookshop::add_employee(std::string na, std::string l, unsigned a, std::vector<std::string*> &names, std::vector<std::string*> &surnames)
{
  double sal;
  House<Employee> *h = nullptr;
  if(emp.size() < emp.max_size())
  {
   h = new House<Employee>(na, l, a);
   h->add_inhab(1, names, surnames);
   std::cout<<"Podaj pensje pracownika: ";
   sal = load_n();
   h->get_inhab(0)->set_salary(sal);
   emp.push_back(h);
  }
}

//wyplata pencji pracownikom
void Bookshop::payment()
{
  unsigned i;
  if(emp.size() > 0)
  {
    for(i = 0 ; i < emp.size() ; i++)
    {
      budget -= (emp[i]->get_inhab(0)->get_salary());
      emp[i]->get_inhab(0)->set_money(emp[i]->get_inhab(0)->get_money()+emp[i]->get_inhab(0)->get_salary());
      if(budget < 0)
      {
        std::cout<<"BANKRUCTWO!"<<std::endl;
        exit(0);
      }
    }
  }
  else
    std::cout<<"Nie ma komu wyplacic pensji"<<std::endl;
}

//UWAGA TRZEBA WZIAC POD UWAGE POWIEKSZONE N!! AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA

//wyswietla liste ksiazek, pobiera numer, usuwa ksiazke o zadanym numerze, zwraca czesc kosztow
void Bookshop::delete_book()
{
  if(bo.size() > 0)
  {
    unsigned n;
    this->show();
    n = load_n();
    n%=bo.size();
    (*this)+(bo[n].b->get_price()*(bo[n].n));
    this->delete_b(n);
  }
  else
    std::cout<<"Brak ksiazek do usuniecia"<<std::endl;
}

//usuwa klienta, ktorego numer zostal dany
void Bookshop::delete_customers(unsigned n)
{
  House<Customer> *b;
  if(cust.size() > 0)
  {
    b = cust[n];
    cust.erase(cust.begin()+n);
    delete b;
  }
  else
    std::cout<<"Brak klientow do usuniecia"<<std::endl;
}

//wyswietla liste klientow, pobiera numer i usuwa klientow o zadanym numerze
void Bookshop::delete_customers()
{
  unsigned n;
  if(cust.size())
  {
    this->show_customers();
    std::cout<<"Usun: ";
    n = load_n();
    n--;
    n%=cust.size();
    this->delete_customers(n);
  }
  else
    std::cout<<"Brak klientow do usuniecia"<<std::endl;
}

//usuwa pracownika, ktorego numer zostal dany
void Bookshop::delete_employee(unsigned n)
{
  House<Employee> *h;
  if(emp.size() > 0)
  {
    h = emp[n];
    emp.erase(emp.begin()+n);
    delete h;
  }
  else
    std::cout<<"Brak pracownikow do usuniecia"<<std::endl;
}

//wyswietla liste pracownikow, pobiera numer i usuwa pracownika o zadanym numerze
void Bookshop::delete_employee()
{
  unsigned n;
  if(emp.size() > 0)
  {
    this->show_employees();
    std::cout<<"Usun: ";
    n = load_n();
    n--;
    n%=emp.size();
    this->delete_employee(n);
  }
  else
    std::cout<<"Brak pracownikow do usuniecia"<<std::endl;
}

//skladanie zamowienia - po 5 sztuk danej ksiazki na kazda pozycje
void Bookshop::order(Warehouse &w)
{
  unsigned n;
  Bookn boo;
  boo.n = 5;
  if(w.get_bo_size() > 0)
  {
    std::cout<<"Lista ksiazek dostepnych w magazynie"<<std::endl;
    w.show();
    std::cout<<"Podaj ktore pozycje chcesz zamowic (zamowionych zostanie 5 sztuk kazdej wybranej pozycji). Wpisz 0, aby zakonczyc zamowienie"<<std::endl;
    n = load_n();
    while(n != 0)
    {
      n--;
      n%=w.get_bo_size();
      boo.b = w.get_bo_b(n);

      if(ord.size() < ord.max_size())
        ord.push_back(boo);
      else
      {
        std::cout<<"Nie mozna dodac kolejnej ksiazki do zamowienia"<<std::endl;
        break;
      }
      n = load_n();
    }
  }
  else
    std::cout<<"W magazynie nie ma zadnych ksiazek"<<std::endl;
}

Employee* Bookshop::choose_emp()
{
  Employee *e = nullptr;
  unsigned n;
  if(emp.size() > 0)
  {
    show_employees();
    std::cout<<"Wybierz numer pracownika: ";
    n = load_n();
    n--;
    n%=emp.size();
    e = emp[n]->get_inhab(n);
  }
  else
    std::cout<<"Nie ma jeszcze zadnych pracownikow"<<std::endl;
  return e;
}

House<Customer>* Bookshop::choose_cust()
{
  House<Customer> *h = nullptr;
  unsigned n;
  if(cust.size() > 0)
  {
    show_customers();
    std::cout<<"Wybierz numer rodziny klientow: ";
    n = load_n();
    n--;
    n%=cust.size();
    h = cust[n];
  }
  else
    std::cout<<"W ksiegarni nie ma jeszcze zadnych klientow"<<std::endl;
  return h;
}

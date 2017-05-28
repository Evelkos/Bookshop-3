#ifndef bookshop_h
#define bookshop_h

#include "house.hpp"
#include "warehouse.hpp"

extern char* load(char*, int length);
extern double load_n();

class Bookshop : public Warehouse
{
  double budget;
  std::vector<Bookn> ord;               //zamowienie
  std::vector<House<Employee>*> emp;     //wektor wskaznikow na domy pracownikow
  std::vector<House<Customer>*> cust;    //wektor domow klientow

  protected:
  static int numBookshops;              //liczba ksiegarni ogolem

  public:
  Bookshop(std::string = "Ksiegarnia", std::string = "Miasto", unsigned int = 0, double = 0);
  ~Bookshop();
  static int get_numBookshops(){return numBookshops;}

  double get_budget() {return budget;}
  void set_budget(double b) {budget = b;}

  void add_book();
  void add_employee();
  void add_customer();

  void delete_book(int n);
  void delete_employee(int n);
  void delete_customer(int n);

  void show_customers();
  void show_employees();
  void show_ord();
  int show_books_c();

  friend std::ostream& operator<< (std::ostream&, Bookshop*);
  Bookshop& operator= (Bookshop &b2);
  void operator +(float p){this->budget+=p;}
  void  operator -(float n) { this->budget-=n;}
};

#endif

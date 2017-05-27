#ifndef bookshop_h
#define bookshop_h

#include "house.hpp"
#include "warehouse.hpp"

extern char* load(char*, int length);
extern double load_n();

class Bookshop : public Warehouse
{
  int num;                              //suma egzemplarzy w ksiegarni (nie trzeba bedzie zliczac za kazdym razem)
  double budget;
  std::vector<Bookn> ord;               //zamowienie
  std::vector<House<Employee>> emp;     //wektor domow pracownikow
  std::vector<House<Customer>> cust;    //wektor domow klientow

  protected:
  static int numBookshops;              //liczba ksiegarni ogolem

  public:
  Bookshop(std::string = "-", std::string = "-", unsigned int = 0, double = 0);
  ~Bookshop();
  static int get_numBookshops(){return numBookshops;}

  double get_budget() {return budget;}
  void set_budget(double b) {budget = b;}

  void new_book();
  void new_employee();
  void new_customer();

  void delete_book(int n);
  void delete_employee(int n);
  void delete_customer(int n);

//  List<Book>* find_book(std::string t, std::string a, std::string p);

  void show_customers();
  void show_employees();
  int show_books_c();

  void order_e();     //do pracownika
  void show_order();  //do pracownika

  friend std::ostream& operator<< (std::ostream&, Bookshop*);
  Bookshop& operator= (Bookshop &b2);
  void operator +(float p){this->budget+=p;}
  void  operator -(float n) { this->budget-=n;}
};

#endif

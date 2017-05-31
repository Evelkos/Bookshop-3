#ifndef bookshop_h
#define bookshop_h

#include "house.hpp"
#include "warehouse.hpp"

extern char* load(char*, int length);
extern double load_n();

class Bookshop : public Warehouse
{
  //public:
  double budget;
  std::vector<Bookn*> ord;               //zamowienie
  std::vector<House<Employee>*> emp;    //wektor wskaznikow na domy pracownikow
  std::vector<House<Customer>*> cust;   //wektor domow klientow

  protected:
  static int numBookshops;              //liczba ksiegarni ogolem

  public:
  Bookshop(std::string = "Ksiegarnia", std::string = "Miasto", unsigned int = 0, double = 0);
  ~Bookshop();

  static int get_numBookshops(){return numBookshops;}
  unsigned get_ord_size() {return ord.size();}
  unsigned get_emp_size() {return emp.size();}
  unsigned get_cust_size() {return cust.size();}
  Bookn* get_ord_n(unsigned n) {return ord[n];}
  House<Customer>* get_cust_n(unsigned n) {return cust[n];}
  double get_budget() {return budget;}
  void set_budget(double b) {budget = b;}

  void clear_ord() {ord.clear();}

  void add_employee(std::string, std::string, unsigned, std::vector<std::string*>&, std::vector<std::string*>&);
  void add_customers(unsigned, std::string, std::string, unsigned, std::vector<std::string*>&, std::vector<std::string*>&);
  void add_customers(std::vector<std::string*>&, std::vector<std::string*>&);
  void show_customers();
  void show_employees();
  void show_ord();
  void delete_book(unsigned n);
  void delete_book();
  void delete_employee(unsigned n);
  void delete_employee();
  void delete_customers(unsigned n);
  void delete_customers();
  void payment();
  void order(Warehouse &w);
  Employee* choose_emp();
  House<Customer>* choose_cust();
  void f_shopping(unsigned);

  friend std::ostream& operator<< (std::ostream&, Bookshop&);
  Bookshop& operator= (Bookshop &b2);
  void operator +(float p){this->budget+=p;}
  void  operator -(float n) { this->budget-=n;}
};

#endif

#ifndef person_h
#define person_h

class Person
{
  protected:

  std::string name;
  std::string surname;
  double money;

  public:

  Person(std::string n = "-", std::string s = "-", double m = 0.00): name(n), surname(s), money(m) {};

  std::string get_name() {return name;}
  std::string get_surname() {return surname;}
  double get_money() {return money;}

  void set_name(std::string n) {name = n;}
  void set_surname(std::string s) {surname = s;}
  void set_money(double m) {money = m;}
};

#endif

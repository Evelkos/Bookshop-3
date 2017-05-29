#include "owner.hpp"

Owner::Owner(std::string n, std::string s, double b): Person(n, s, b) {D(std::cout<<"Tworze wlasciciela."<<std::endl;)}

Owner::~Owner()
{
  Bookshop *b;
  while(bs.size() > 0)
  {
    b = bs[bs.size()-1];
    bs.pop_back();
    delete b;
  }
  D(std::cout<<"Niszcze wlasciciela."<<std::endl;)
}

//pokazuje liste ksiegarni
void Owner::show_bs()
{
  unsigned int i;
  if(bs.empty())
    std::cout<<"Nie ma jeszcze zaznych ksiegarni"<<std::endl;
  else
  {
    std::cout<<"Lista ksiegarni:"<<std::endl;
    for(i = 0 ; i < bs.size() ; i++)
      std::cout<<*(bs[i]);
  }
}

//tworzy nowa ksiegarnie
void Owner::add_bs()
{
  int a;
  char n[20], c[20];
  double b;
  Bookshop *nbs;

  std::cout<<std::endl<<"Nowa ksiegarnia: "<<std::endl;
  std::cout<<"Nazwa: ";         load(n, MAX_L);
  std::cout<<"Miasto: ";        load(c, MAX_L);
  std::cout<<"Budzet: ";        b = load_n();
  std::cout<<"Powierzchnia: ";  a = load_n();
  money -= b;

  if(money < 0) {std::cout<<"BANKRUCTWO!"<<std::endl;  exit(0);}

  if(bs.size() < bs.max_size())
  {
    nbs = new Bookshop(n, c, a, b);
    bs.push_back(nbs);
  }
  else
    std::cout<<"Nie mozna dodac kolejnej ksiegarni"<<std::endl;
}

void Owner::add_bs(char n[MAX_L], char c[MAX_L], unsigned a, double b)
{
  Bookshop *nbs;
  money -= b;
  if(money < 0) {std::cout<<"BANKRUCTWO!"<<std::endl;  exit(0);}

  if(bs.size() < bs.max_size())
  {
    nbs = new Bookshop(n, c, a, b);
    bs.push_back(nbs);
  }
  else
    std::cout<<"Nie mozna dodac kolejnej ksiegarni"<<std::endl;
}

//usuwa ksiegarnie o zadanym numerze (aktualnie na liscie)
void Owner::delete_bs(unsigned n)  { Bookshop *b; n%=bs.size(); b = bs[n-1]; bs.erase(bs.begin() + n -1); delete b;}

void Owner::delete_bs() {unsigned n; this->show_bs(); std::cout<<"Usun: "; n = load_n();  this->delete_bs(n);}

void Owner::get_cash(Bookshop* b)
{
  double mon;
  std::cout<<*b<<"Podaj o ile chcesz pomniejszyc budzet ksiegarni: ";
  do  {  mon = load_n();  } while(mon < 0 || mon > b->get_budget());
  *b - mon;
  money += mon;
}

/*
//wyswietlanie zlozonego przez pracownikow zamowienia
void Owner::show_order(Bookshop *current)
{
  if(current->get_oA() == 0)
    std::cout<<"Zadne zamowienie nie jest aktualnie zlozone"<<std::endl;
  else
    show_l(current->get_order());
}*/

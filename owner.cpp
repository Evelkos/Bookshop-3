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
void Owner::delete_bs(int n)  { Bookshop *b; b = bs[n-1]; bs.erase(bs.begin() + n -1); delete b;}

/*
//akceptowanie zlozonego zamowienia
void Owner::accept(Bookshop *b)
{
  List<Book> *curr, *f;
  Book *currB;
  char choice[2];
  choice[0] = '0';

  if(b->get_oA() == 0)
    std::cout<<std::endl<<"Aktualnie nie ma zlozonych zadnych zamowien"<<std::endl;
  else if((curr = b->get_order()) != NULL)
  {
    show_order(b);
    std::cout<<std::endl<<"Czy akceptujesz zamowienie?"<<std::endl<<"1. Tak"<<std::endl<<"2. Nie"<<std::endl;
    load(choice, 2);
    if(choice[0] == '1')
    {
      do
      {
        f = find_o(*(curr->get_obj()), b->get_firstB());  //wyszukiwanie zamowionej ksiazki na liscie w ksiegarni
        if(f != NULL)
        {
          currB = f->get_obj();
          if((b->get_budget() - curr->get_obj()->get_number()*quantity_pr(currB->get_year(), currB->get_pages())) >= 0)  //bo ilosc stron i rok sa takie same
          {
            *b - curr->get_obj()->get_number()*quantity_pr(currB->get_year(), currB->get_pages());
            currB->set_number(currB->get_number()+curr->get_obj()->get_number());
          }
          else
            break;
        }
        curr = curr->get_next();
      }while(curr != b->get_order());
    }
    while(b->get_order() != NULL)
      b->set_order(delete_o(1, b->get_order()));
    b->set_oA(0);
  }
}

//wyswietlanie zlozonego przez pracownikow zamowienia
void Owner::show_order(Bookshop *current)
{
  if(current->get_oA() == 0)
    std::cout<<"Zadne zamowienie nie jest aktualnie zlozone"<<std::endl;
  else
    show_l(current->get_order());
}

void Owner::get_cash(Bookshop *bs)
{
  double number;
  std::cout<<bs;
  std::cout<<"Podaj o ile chcesz pomniejszyc budzet ksiegarni: ";
  do
  {
    number = load_n();
  }while(number < 0 || number > bs->get_budget());
  *bs - number;
  budget += number;
}*/

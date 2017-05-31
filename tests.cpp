#include "owner.hpp"

extern void supply(Owner&, Warehouse&);
extern void shopping(Owner&);

void test_ow()
{
  unsigned i;
  std::cout<<"TEST KLASY WLASCICIEL"<<std::endl;
  std::cout<<"Na potrzeby testu tworzymy obiekt automatycznie"<<std::endl;
  Owner o("Ewelina", "Chmielewska", 99999.99);

  std::cout<<std::endl<<"Dodawanie ksiegarni:"<<std::endl<<"Ze wzgledu na specyfikacje fnkcji prosze o podanie potrzebych danych"<<std::endl;
  for(i = 0 ; i < 3 ; i++)
    o.add_bs();

  std::cout<<std::endl<<"Wyswietlanie ksiegarni:"<<std::endl;
  o.show_bs();

  std::cout<<std::endl<<"Zbieranie utargu:"<<std::endl;
  std::cout<<"W tym wypadku z ksiegarni bedacej pierwszej na liscie"<<std::endl;
  std::cout<<"Ksiegarnia przed: "<<*(o.get_bs(0));
  if(o.get_size() > 0)
    o.get_cash(o.get_bs(0));
  std::cout<<"Ksiegarnia po: "<<*(o.get_bs(0));

  std::cout<<std::endl<<"Usuwanie ksiegarni:"<<std::endl;
  std::cout<<"Ze wzgledu na specyfikacje funkcji prosze o podanie potrzebych danych"<<std::endl;
  o.delete_bs();
  std::cout<<"Usuwamy dodatkowo jedna ksiegarnie"<<std::endl;
  if(o.get_size() > 0)
    o.delete_bs(1);
  std::cout<<std::endl<<std::endl<<"Po usunieciu dwoch ksiegarni mamy:"<<std::endl;
  o.show_bs();

  std::cout<<"Po zakonczonym tescie usuwany jest wlasciciel. Wywolanie destruktora usuwa pozostale ksieganie."<<std::endl;
}

void test_bs(std::vector<Book*> &books, std::vector<std::string*> &names, std::vector<std::string*> &surnames)
{
  unsigned i;
  std::cout<<"TEST KLASY KSIEGARNIA"<<std::endl;
  std::cout<<"Na potrzeby testu tworzymy obiekty automatycznie (wlasciciel oraz magazyn)"<<std::endl;
  Owner o("Ewelina", "Chmielewska", 99999.99);
  Warehouse w("Magazyn", "Pomocniczy", 100);

  std::cout<<std::endl<<"Tworzymy ksiegarnie"<<std::endl;
  std::cout<<"Ze wzgledu na specyfikacje funkcji prosze o podanie potrzebnych danych"<<std::endl;
  o.add_bs();

  Bookshop &bs = *(o.get_bs(0));

  std::cout<<std::endl<<"Dodajemy ksiazki do magazynu"<<std::endl;
  try
  {
    w.add_all(10, books);
    if(w.get_bo_size() <= 0){std::string ex = "Nie udalo sie dodac do magazynu zadnych ksiazek"; throw ex;}
    std::cout<<"Zamawianie ksiazek i wyswietlanie zamowien:"<<std::endl;
    std::cout<<"Ze wzgledu na specyfikacje funkcji prosze o podanie potrzebnych danych"<<std::endl;
    bs.order(w);
    bs.show_ord();
    std::cout<<"Jesli zamowiono towar - zostanie on teraz dostarczony do ksiegarni"<<std::endl;
    std::cout<<"Przed dostarczeniem:"<<std::endl<<bs;
    bs.show();                                          //metoda odziedziczona po klasie magazyn
    supply(o, w);
    std::cout<<"Po dostarczeniu:"<<std::endl<<bs;
    bs.show();
  }
  catch(std::string ex)  {std::cout<<"Blad: "<<ex;}

  std::cout<<std::endl<<"Dodawanie i wyswietlanie klientow:"<<std::endl;
  std::cout<<"Ze wzgledu na specyfikacje funkcji prosze o podanie potrzebnych danych"<<std::endl;
  for(i = 0 ; i < 3 ; i++) bs.add_customers(names, surnames);
  bs.show_customers();

  std::cout<<std::endl<<"Usuwanie klientow:"<<std::endl;
  std::cout<<"Ze wzgledu na specyfikacje funkcji prosze o podanie potrzebnych danych"<<std::endl;
  for(i = 0 ; i < 2 ; i++)  bs.delete_customers();
  bs.show_customers();

  std::cout<<std::endl<<"Dodawanie i wyswietlanie pracownikow:"<<std::endl;
  std::cout<<"Ze wzgledu na specyfikacje funkcji prosze o podanie potrzebnych danych";
  for(i = 0 ; i < 3 ; i++) bs.add_employee("Dom pracownika", "Miasto", 20, names, surnames);
  bs.show_employees();

  std::cout<<std::endl<<"Wyplaty dla pracownikow:"<<std::endl;
  std::cout<<"Przed wyplatami: "<<bs;
  bs.payment();
  std::cout<<"Po wyplatach: "<<bs;

  std::cout<<std::endl<<"Usuwanie pracownikow:"<<std::endl;
  std::cout<<"Ze wzgledu na specyfikacje funkcji prosze o podanie potrzebnych danych"<<std::endl;
  for(i = 0 ; i < 2 ; i++)  bs.delete_employee();
  bs.show_employees();

  std::cout<<"Po zakonczonym tescie wywoluja sie destruktory utworzonych obiektow:"<<std::endl;
}

void test_sh(std::vector<Book*> &books, std::vector<std::string*> &names, std::vector<std::string*> &surnames)
{
  unsigned i;
  House<Customer> *h;

  std::cout<<"TEST DOKONYWANIA ZAKUPOW:"<<std::endl;
  std::cout<<"Zanim dokonamy wlasciwego testu:"<<std::endl;
  std::cout<<"Tworzymy wlasciciela oraz magazyn:"<<std::endl;
  Owner o("Ewelina", "Chmielewska", 9999999999.99);
  Warehouse w("Magazyn", "Pomocniczy", 100);
  std::cout<<"Tworzymy pomocniczą ksiegarnie (podac duzy budzet)"<<std::endl;
  o.add_bs();
  Bookshop &bs = *(o.get_bs(0));
  std::cout<<"Dodajemy do niej klientow:"<<std::endl;
  bs.add_customers(names, surnames);
  std::cout<<"Dodajemy do niej pracownika (bez pracownika niemozliwe sa zakupy):"<<std::endl;
  bs.add_employee("Dom Pracownika", "Ciechanow", 20, names, surnames);

  std::cout<<"Test wlasciwy:"<<std::endl;
  std::cout<<"1. Dodajemy ksiazki do magazynu"<<std::endl;
  try
  {
    w.add_all(10, books);
    if(w.get_bo_size() <= 0){std::string ex = "Nie udalo sie dodac do magazynu zadnych ksiazek"; throw ex;}
    std::cout<<"2. Zamawiamy ksiazki do ksiegarni:"<<std::endl;
    std::cout<<"Ze wzgledu na specyfikacje funkcji prosze o podanie potrzebnych danych"<<std::endl;
    bs.order(w);
    std::cout<<"3. Dostarczenie ksiazek do ksiegarni:"<<std::endl;
    supply(o, w);
    bs.show();
  }
  catch(std::string ex)  {std::cout<<"Blad: "<<ex<<std::endl;}

  try
  {
    if(bs.get_bo_size() <= 0){std::string ex = "Opcja zakupow niedostepna. Brak ksiazek w ksiegarni"; throw ex;}
    std::cout<<"4. Mijanie kolejnych dni i zakup kolejnych ksiazek"<<std::endl;
    for(i = 0 ; i < 5 ; i++)
    {
      shopping(o);
      std::cout<<"Dzien "<<i+1<<":"<<std::endl;
      if(bs.get_cust_size() > 0) h = bs.get_cust_n(0); else{std::string ex = "Nie ma zadnych klientow"; throw ex;}
      if( h!= nullptr) h->show();
    }
  }
  catch(std::string ex)  {std::cout<<"Blad: "<<ex<<std::endl;}

  std::cout<<"Po zakonczonym tescie wywoluja sie destruktory utworzonych obiektow:"<<std::endl;
}

#include "interface.hpp"

//menu glowne
void main_menu(Owner &ow, Warehouse &w, std::vector<std::string*>&names, std::vector<std::string*>&surnames)
{
  char choice1[2];
  choice1[0] = '0';

  while(choice1[0] != '6'){
    std::cout<<std::endl<<"Wybierz osobe"<<std::endl;
    std::cout<<"1. Wlasciciel"<<std::endl;
    std::cout<<"2. Pracownik"<<std::endl;
    std::cout<<"3. Klient"<<std::endl;
    std::cout<<"4. Magazyn"<<std::endl;
    std::cout<<"5. Testy"<<std::endl;
    std::cout<<"6. Koniec"<<std::endl;
    load(choice1, 2);
    switch (choice1[0])
    {
      case '1':     ow_menu1(ow, w, names, surnames);                                   break;
      case '2':     em_menu1(ow, w);                                                    break;
      case '3': //klient
        break;
      case '4': //testy
        break;
      case '5':
        break;
      case '6':
        break;
      default:
        std::cout<<"Nie ma takiej mozliwosci"<<std::endl;
        break;
    }
  }
}

//menu wlasciciela ksiegarni - ogolne
void ow_menu1(Owner &ow, Warehouse &w, std::vector<std::string*>&names, std::vector<std::string*>&surnames)
{
  char choice1[2];
  choice1[0] = '0';

  while(choice1[0] != '5'){
    std::cout<<std::endl<<"Wlasciciel: "<<ow;
    std::cout<<"1. wyswietl liste ksiegarni"<<std::endl;
    std::cout<<"2. stworz nowa ksiegarnie"<<std::endl;
    std::cout<<"3. usun ksiegarnie"<<std::endl;
    std::cout<<"4. zarzadzaj ksiegarnia"<<std::endl;
    std::cout<<"5. wyjscie"<<std::endl;
    load(choice1, 2);
    switch(choice1[0])
    {
      case '1':     ow.show_bs();                                                       break;
      case '2':     ow.add_bs();                                                        break;
      case '3':     ow.delete_bs();                                                     break;
      case '4':     ow_menu2(ow, w, names, surnames);                                   break;
      case '5':                                                                         break;
      default:      std::cout<<"Nie ma takiej mozliwosci"<<std::endl;                   break;
    }
  }
}

//menu wlasciciela ksiegarni - konkretna ksiegarnia
void ow_menu2(Owner &ow, Warehouse &w, std::vector<std::string*>&names, std::vector<std::string*>&surnames)
{
  Bookshop *bs;
  char choice1[2];
  unsigned i = 0;
  choice1[0] = '0';

  if(ow.get_size() > 0)
    {
    while(choice1[0] != '7')
    {
      bs = ow.get_bs(i);
      std::cout<<std::endl<<"Ksiegarnia "<<(*bs)<<std::endl;
      std::cout<<"1. Wyswietl liste pracownikow"<<std::endl;
      std::cout<<"2. Zatrudnij nowego pracownika"<<std::endl;
      std::cout<<"3. Zwolnij pracownika"<<std::endl;
      std::cout<<"4. Wyplac pensje pracownikom"<<std::endl;
      std::cout<<"5. Odbierzu utarg"<<std::endl;
      std::cout<<"6. Nastepna ksiegarnia"<<std::endl;
      std::cout<<"7. Wyjscie"<<std::endl;
      load(choice1, 2);

      switch(choice1[0])
      {
        case '1':     bs->show_employees();                                               break;
        case '2':     bs->add_employee("D", bs->get_loc(), 20, names, surnames);          break;
        case '3':     bs->delete_employee();                                              break;
        case '4':     bs->payment();                                                      break;
        case '5':     ow.get_cash(bs);                                                    break;
        case '6':     if(i < ow.get_size()) i++; else i = 0;                              break;
        case '7':                                                                         break;
        default:      std::cout<<"Nie ma takiej mozliwosci"<<std::endl;                   break;
      }
    }
  }
}

//menu pracownika - ogolne
void em_menu1(Owner &ow, Warehouse &w)
{
  Bookshop *bs;
  char choice[2];
  unsigned i = 0;
  choice[0] = '0';

  bs = ow.get_bs(i);

  while(choice[0] != '3')
  {
    std::cout<<"PRACOWNIK"<<std::endl;
    std::cout<<"1. Wybierz pracownika"<<std::endl;
    std::cout<<"2. Przejdz do nastepnej ksiegarni"<<std::endl;
    std::cout<<"3. Wyjscie"<<std::endl;
    load(choice, 2);

    switch(choice[0])
    {
      case '1':     em_menu2((bs->choose_emp()), bs, w);                                break;
      case '2':     if(i < ow.get_size()) i++; else i = 0;                              break;
      case '3':                                                                         break;
      default:      std::cout<<"Nie ma takiej mozliwosci."<<std::endl;                  break;
    }
  }
}

//menu pracownika - konkretny pracownik
void em_menu2(Employee *em, Bookshop *bs, Warehouse &w)
{
  char choice[2];
  choice[0] = '0';
  if(em != nullptr)
  {
    while(choice[0] != '5'){
      std::cout<<std::endl<<"Pracownik "<<(*em)<<std::endl;
      std::cout<<"\"Hmm... co by tu zrobic?\""<<std::endl;
      std::cout<<"1. Pokaz liste wszystkich ksiazek"<<std::endl;
      std::cout<<"2. Zloz zamowienie"<<std::endl;
      std::cout<<"3. Wyswietl aktualne zamowienie"<<std::endl;
      std::cout<<"4. Wycofaj ksiazke z ksiegarni"<<std::endl;
      std::cout<<"5. Stan za kasa i czekaj na klientow"<<std::endl;
      load(choice, 2);
      switch(choice[0])
      {
        case '1':       bs->show();                                                     break;
        case '2':       bs->order(w);                                                   break;
        case '3':       bs->show_ord();                                                 break;
        case '4':       bs->delete_book();                                              break;
        case '5':                                                                       break;
        default:        std::cout<<"Nie ma takiej mozliwosci."<<std::endl<<std::endl;   break;
      }
    }
  }
  else std::cout<<"Blad: w tej ksiegarni nie ma jeszcze zadnych pracownikow"<<std::endl;
}

//menu klienta - ogolne
void cu_menu1(Owner &ow, std::vector<std::string*> &names, std::vector<std::string*> &surnames)
{
  Bookshop *bs;
  char choice[2];
  unsigned i = 0;
  choice[0] = '0';

  if(ow.get_size() > 0)     //mozna zamienic ze statyczna liczba wszystkich ksiegarni!
  {
    bs = ow.get_bs(i);

    while(choice[0] != '6')
    {
      bs = ow.get_bs(i);
      std::cout<<std::endl<<"KLIENT - ksiegarnia "<<*bs<<std::endl;
      std::cout<<"1. Wyswietl liste klientow"<<std::endl;
      std::cout<<"2. Stworz rodzine nowych klientow"<<std::endl;
      std::cout<<"3. Usun rodzine klientow"<<std::endl;
      std::cout<<"4. Obejrzyj zbior ksiazek rodziny"<<std::endl;
      std::cout<<"5. Przejdz do nastepnej ksiegarni"<<std::endl;
      std::cout<<"6. Wyjscie"<<std::endl;
      load(choice, 2);

      switch (choice[0])
      {
        case '1':       bs->show_customers();                                           break;
        case '2':       bs->add_customers(names, surnames);                             break;
        case '3':       bs->delete_customers();                                         break;
        case '4':       std::cout<<"Jeszcze nic tu nie ma"<<std::endl;                  break;
        case '5':       if(i < ow.get_size()) i++; else i = 0;                          break;
        case '6':       bs->choose_cust()->show();                                      break;
        default:        std::cout<<"Nie ma takiej mozliwosci."<<std::endl;              break;
      }
    }
  }
  else
    std::cout<<"Nie istnieje zadna ksiegarnia. Nie moze byc zadnych klientow"<<std::endl;
}

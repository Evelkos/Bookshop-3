#include "interface.hpp"


//menu glowne
void main_menu(Owner &ow, std::vector<std::string*>&names, std::vector<std::string*>&surnames)
{
  char choice1[2];
  choice1[0] = '0';

  while(choice1[0] != '5'){
    std::cout<<std::endl<<"Wybierz osobe"<<std::endl;
    std::cout<<"1. Wlasciciel"<<std::endl;
    std::cout<<"2. Pracownik"<<std::endl;
    std::cout<<"3. Klient"<<std::endl;
    std::cout<<"4. Testy"<<std::endl;
    std::cout<<"5. Koniec"<<std::endl;
    load(choice1, 2);
    switch (choice1[0])
    {
      case '1':     ow_menu1(ow, names, surnames);                                            break;
      case '2': //pracownik
        break;
      case '3': //klient
        break;
      case '4': //testy
        break;
      case '5':
        break;
      default:
        std::cout<<"Nie ma takiej mozliwosci"<<std::endl;
        break;
    }
  }
}

//menu wlasciciela ksiegarni - ogolne
void ow_menu1(Owner &ow, std::vector<std::string*>&names, std::vector<std::string*>&surnames)
{
  char choice1[2];
  choice1[0] = '0';

  while(choice1[0] != '5'){
    std::cout<<std::endl<<"Wlasciciel: ";
    std::cout<<"1. wyswietl liste ksiegarni"<<std::endl;
    std::cout<<"2. stworz nowa ksiegarnie"<<std::endl;
    std::cout<<"3. usun ksiegarnie"<<std::endl;
    std::cout<<"4. zarzadzaj ksiegarnia"<<std::endl;
    std::cout<<"5. wyjscie"<<std::endl;
    load(choice1, 2);
    switch(choice1[0])
    {
      case '1':     ow.show_bs();                                           break;
      case '2':     ow.add_bs();                                            break;
      case '3':     ow.delete_bs();                                         break;
      case '4':     ow_menu2(ow, names, surnames);
      case '5':                                                             break;
      default:      std::cout<<"Nie ma takiej mozliwosci"<<std::endl;       break;
    }
  }
}

//menu wlasciciela ksiegarni - ksiegarnia
void ow_menu2(Owner &ow, std::vector<std::string*>&names, std::vector<std::string*>&surnames)
{
  Bookshop *bs;
  char choice1[2];
  unsigned i = 0;
  choice1[0] = '0';

  while(choice1[0] != '7'){
    bs = ow.get_bs(i);
    std::cout<<std::endl<<"Ksiegarnia "<<std::endl;
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
      case '1':     bs->show_employees();                                       break;
      case '2':     bs->add_employee("D", bs->get_loc(), 20, names, surnames);  break;
      case '3':     bs->delete_employee();                                      break;
      case '4':     bs->payment();                                              break;
      case '5':     ow.get_cash(bs);                                            break;
      case '6':     if(i < ow.get_size()) i++; else i = 0;                      break;
      case '7':                                                                 break;
      default:      std::cout<<"Nie ma takiej mozliwosci"<<std::endl;           break;
    }
  }
}

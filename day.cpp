#include "owner.hpp"


//zakupy dokonywane przez klientow we wszystkich sklepach kazdego dnia
void shopping(Owner &ow)
{
  Bookshop *b;
  unsigned i, j;
  if(ow.get_size() > 0)
  {
    for(i = 0 ; i < ow.get_size() ; i++)            //ksiegarnia
    {
      b = ow.get_bs(i);
      for(j = 0 ; j < b->get_cust_size() ; j++)     //dom (przypisany do ksiegarni)
        b->f_shopping(j);
    }
  }
}

//dostawy do sklepow
void supply(Owner &ow, Warehouse &w)
{
  Bookshop *b;
  unsigned i, j;
  if(ow.get_size() > 0)
  {
    for(i = 0 ; i < ow.get_size() ; i++)            //ksiegarnie
    {
      b = ow.get_bs(i);
      for(j = 0 ; j < b->get_ord_size() ; j++)      //pozycje z zamowienia
      {
        if(b->get_ord_n(j)->n >= 5)
        {
          if(b->get_budget() > 5*(b->get_ord_n(j)->b->get_price()))
          {
            *b - 5*(b->get_ord_n(j)->b->get_price());   //zaplata
            b->get_ord_n(j)->n -= 5;                    //odjecie 5 egzemplarzy z magazynu
            b->add(5, b->get_ord_n(j)->b);              //dodanie 5 egzemplarzy do ksiegarni ("na nowa kupke")
          }
          else
            break;
        }
      }
      b->clear_ord();
    }
  }
}

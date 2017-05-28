#include <iostream>
#include "bookshop.hpp"
#include "functions.hpp"
using namespace std;

extern void data(vector<Book*>&, vector<string*>&, vector<string*>&);
extern const unsigned int factor;


int main()
{
  vector<Book*> books;          //tablica ksiazek (oddzielna, w wypadku gdyby mialo byc kilka roznych magazynow)
  vector<string*> names;        //tablica imion do tworzenia klientow/pracownikow
  vector<string*> surnames;     //tablica nazwisk do tworzenia klientow/pracownikow
  Warehouse mag;                //magazyn - wspolny dla wszystkich ksiegarni
//  House<Customer> h;
  Bookshop b("Ksiegarnia", "Ciechanow", 100, 999);
  data(books, names, surnames); //wczytywanie danych z pliku tekstowego data.txt do tablic
  cout<<endl<<b<<endl;

  b.add(10, 0, books[0]);
  b.add(10, 1, books[1]);
  b.show();

  b.add_customers(2, "Dom", "Ciechanow", 100, names, surnames);
  cout<<endl<<b<<endl;
  b.show_customers();

  delete_data(books, names, surnames);  //usuwanie tablic
  cout<<endl;
  return 0;
}

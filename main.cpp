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
  House<Customer> h;

  data(books, names, surnames); //wczytywanie danych z pliku tekstowego data.txt do tablic
  mag.add_all(10, books);       //dodawanie do magazynu wszystkich (w zalozeniu) ksiazek
  mag.show();
  h.add(books[0], 0);
  h.add(books[1], 1);
  h.show();

  delete_data(books, names, surnames);  //usuwanie tablic
  cout<<endl;
  return 0;
}

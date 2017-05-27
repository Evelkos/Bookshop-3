#include <iostream>
#include "bookshop.hpp"
#include "book.hpp"
using namespace std;

template<typename T>
extern void show_vec(vector<T>&);
extern void data(vector<Book>&, vector<string>&, vector<string>&);


int main()
{
  vector<Book> books;
  vector<string> names;
  vector<string> surnames;
  data(books, names, surnames);

  show_vec(books);
  cout<<endl;

  return 0;
}

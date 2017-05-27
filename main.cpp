#include <iostream>
#include "bookshop.hpp"
#include "book.hpp"
#include "functions.hpp"
using namespace std;

extern void data(vector<Book*>&, vector<string*>&, vector<string*>&);


int main()
{
  vector<Book*> books;
  vector<string*> names;
  vector<string*> surnames;
  cout<<"Tu dziala 1"<<endl;
  data(books, names, surnames);
  cout<<"Tu dziala 2"<<endl;
  show_vec(books);
  show_vec(names);
  show_vec(surnames);
  cout<<"Tu dziala 3"<<endl;
  delete_data(books, names, surnames);
  cout<<"Tu dziala 4"<<endl;
  cout<<endl;

  return 0;
}

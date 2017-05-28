#include "functions.hpp"

//wczytuje ciag wyrazow, dlugosc ciagu ograniczona
char* load(char *words, int length){
	char *result;
	char *wEnd;  //koniec ciagu wyrazow
	result = fgets(words, length, stdin);
	if(words != NULL){
		wEnd = strchr(words, '\n');
		if(wEnd != NULL)
			*wEnd = '\0';
		else{
			while(getchar() != '\n');
		}
	}
	return result;
}

//wczytuje liczbe
double load_n(){
  char number[10];
  unsigned int i, j = 0;
  double result = 0;

  load(number, 10);
  for(i = 0 ; i < strlen(number) ; i++)
  {
    if((number[i] - '0') >= 0 && (number[i] - '0') <=9)  //wczytywanie cyfr, pomijanie innych znakow (poza '.')
      result = result*10+(number[i] - '0');
    else if(number[i] == '.')                          //wystapil znak '.' => liczba bedzie miala czesc dziesietna
    {
      for(i++; i < strlen(number) ; i++)
      {
        if(number[i] - '0' >= 0 && number[i] - '0' <=9 && j == 0)  //wystapienie pierwszej cyfry po kropce
        {
          result += 0.1*(number[i] - '0');
          j++;
        }
        else if(number[i] - '0' >= 0 && number[i] - '0' <=9 && j == 1)  //wystapienie drugiej cyfry po kropce
          {
            result += 0.01*(number[i] - '0');
            break;
          }
      }
      break;
    }
  }
  return result;
}


void data(std::vector<Book*> &books, std::vector<std::string*> &names, std::vector<std::string*> &surnames)
{
  int n = 0;
  Book *bo;
  std::string line, *l;
  int y, pag;

  srand(time(NULL));


  std::ifstream file;
  file.open( "data.txt" );

  if(file.good() == false)
    std::cout<<"BLAD: blad podczas odczytu bliku"<<std::endl;
  else
  {
    while(!file.eof())
    {
      getline(file, line);
      if(line[0] == '#' && books.size() < books.max_size())     //wczytujemy ksiazke
      {
        bo = new Book();
        getline(file, line);        bo->set_name(line);
        getline(file, line);        bo->set_author(line);
        getline(file, line);        bo->set_publisher(line);
        y = rand()%50+1967;         bo->set_year(y);
        pag = rand()%400+154;       bo->set_pages(pag);

        n = position(books, bo);
        if(books.size() < books.max_size())
          books.insert(books.begin() + n, bo);
      }
      else if(line[0] == '%' )                                  //wczytujemy imie
      {
        getline(file, line);
        while(line[0] != '%')
        {
          l = new std::string(line);
          if(names.size() < names.max_size())
            names.push_back(l);
          getline(file, line);
        }
      }
      else if(line[0] == '*')                                   //wczytujemy nazwisko
      {
        getline(file, line);
        while(line[0] != '*')
        {
          l = new std::string(line);
          if(surnames.size() < surnames.max_size())
            surnames.push_back(l);
          getline(file, line);
        }
      }
      else
        continue;
    }
    file.close();
  }
}

void delete_data(std::vector<Book*> &books, std::vector<std::string*> &names, std::vector<std::string*> &surnames)
{
  Book *b;
  std::string *s;
  std::cout<<std::endl<<"Czyszczenie danych"<<std::endl;
  while(!books.empty())
  {
    b = books[books.size()-1];
    books.pop_back();
    delete b;
  }
  while(!names.empty())
  {
    s = names[names.size()-1];
    names.pop_back();
    delete s;
    D(std::cout<<"Usuwanie imion"<<std::endl;);
  }
  while(!surnames.empty())
  {
    s = surnames[surnames.size()-1];
    surnames.pop_back();
    delete s;
    D(std::cout<<"Usuwanie nazwisk"<<std::endl;);
  }
}

void new_book(std::vector<Book*> &books)
{
  Book *nb;
  char word[MAX_L];
  unsigned int n;

  nb = new Book();
  srand(time(NULL));

  std::cout<<"TYTUL: ";
  nb->set_name(load(word, MAX_L));
  std::cout<<"AUTOR: ";
  nb->set_author(load(word, MAX_L));
  std::cout<<"WYDAWCA: ";
  nb->set_publisher(load(word, MAX_L));
  n = rand()%50+1967;
  nb->set_year(n);
  n = rand()%400+154;
  nb->set_pages(n);

  n = position(books, nb);
  books.insert(books.begin() + n, nb);
}

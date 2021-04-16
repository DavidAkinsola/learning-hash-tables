#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <sstream>

#include <string>
#include <list>
#include <chrono>

#include "hash.cpp"
#include "Book.h"


Hash hash;

void Book::removeBook(){
    std::string title;
    std::cout<<"Enter the title of the book you have removed: ";
    std::cin>>title;

    hash.removeBook(title);

    return;
}
void Book::addBook(){
  std::string title, author;
  int isbn, qty;
  std::cout<<"Enter the title of the book: ";
  std::cin>>title;
  std::cout<<"Enter the author(s) of the book: ";
  std::cin>>author;
  std::cout<<"Enter the ISBN number of the book: ";
  std::cin>>isbn;
  std::cout<<"How many copies of this book do you have?: ";
  std::cin>>qty;

  hash.add(title, author, isbn, qty);
  std::cout<<"book added to table!";

  return;

}
void Book::searchBook(){
  std::string title;
  std::cout<<"Enter the title of the book youre searching for: ";
  std::cin>>title;

  hash.findAuthor(title);

  return;


}
void Book::getBooks(){
  hash.PrintTable();

  return;

}

void Book::start(){
  int choice;
  std::cout<<"Library search system \n";
  std::cout<<"Please select your option \n";
  std::cout<<"1 = ADD BOOK \n";
  std::cout<<"2 = SEARCH FOR BOOK \n";
  std::cout<<"3 = PRINT DATA STRUCTURE \n";
  std::cout<<"4 = REMOVE BOOK \n";
  std::cout<<"0 = EXIT \n";

  std::cin>>choice;

  switch(choice){
    case 1:
    addBook();
    start();
    break;

    case 2:
    searchBook();
    start();
    break;

    case 3:
    getBooks();
    start();
    break;

    case 4:
    removeBook();
    start();
    break;

    case 0:
    return;
    break;

    default:
      std::cout<<"Library search system \n";
      std::cout<<"Please select your option \n";
      std::cout<<"1 = ADD BOOK \n";
      std::cout<<"2 = SEARCH FOR BOOK \n";
      std::cout<<"3 = PRINT DATA STRUCTURE \n";
      std::cout<<"4 = REMOVE BOOK \n";
      std::cout<<"0 = EXIT \n";

      std::cin>>choice;
      break;
  }
}


int main () {

   Book b;
   b.start();
    return 0;

}

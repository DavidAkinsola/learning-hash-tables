#include <iostream>
#include <fstream>
#include <string>
#include <list>

#include "hash.cpp"
#include "Book.h"



Book::Book(std::string title, std::string author, int ISBN, int quantity ){
  this->title = title;
  this->author = author;
  this->ISBN = ISBN;
  this->quantity = quantity;

}


void Book::addBook(){

}


void Book::searchBook(){

}


void Book::removeBook(){

}
/*
int main () {
  
  return 0;
}
*/
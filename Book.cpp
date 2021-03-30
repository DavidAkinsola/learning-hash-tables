#include <iostream>
#include <fstream>
#include <string>
#include <list>

#include "hash.cpp"
#include "Book.h"


template<class T>
Book<T>::Book(T title, T author, int ISBN, int quantity ){
  this->title = title;
  this->author = author;
  this->ISBN = ISBN;
  this->quantity = quantity;

}

template<class T>
T Book<T>::addBook(){

}

template<class T>
void Book<T>::searchBook(){

}

template<class T>
T Book<T>::removeBook(){

}

int main () {
  
  return 0;
}

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <sstream>

#include <string>
#include <list>
#include <chrono>

//#include "hash.cpp"
//#include "Book.h"



/*
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


struct book{
  std::string title;
  std::string author;
  int ISBN;
  int quantity;
};

*/

struct book{
  std::string title;
  std::string author;
  std::string ISBN;
  int qty;
};

void printStock(){
    std::ifstream file("books.txt");
    book i;
    if(file.is_open()){
      while(file>>i.title>>i.author>>i.ISBN>>i.qty){
          std::cout<<i.title<<" "<<i.author<<" "<<i.ISBN<<" "<<i.qty<<"\n";
      }
    }else{
      std::cout<<"file is close \n";
    }
    return;
}

void test(std::string name){
  std::cout<<"hello "<<name<<std::endl;
}

int main () {
/*
auto start = std::chrono::steady_clock::now();
test("david");
test("da");
test("david a");

auto end = std::chrono::steady_clock::now();

double elapsed = double (std::chrono::duration_cast <std::chrono::nanoseconds> (end - start).count());

std::cout <<"time: "<<elapsed/1e9<<std::endl;
*/

  std::string text;
  std::ifstream infile("books");
  while(getline(infile, text)){

    std::istringstream iss(text);
    std::string title, author, ISBN, qty;
    int isbn, quant;
    getline(iss, title, '\t');
    getline(iss, author, '\t');
    getline(iss, ISBN, '\t');
    getline(iss, qty, '\t');

    std::istringstream(ISBN)>>isbn;
    std::istringstream(qty)>>quant;

    std::cout<<"title: "<<title<<"\n";
    std::cout<<"author: "<<author<<"\n";
    std::cout<<"isbn: "<<isbn<<"\n";
    std::cout<<"quantity: "<<quant<<"\n";
  }
  
 
    system("pause");
   
    return 0;

}

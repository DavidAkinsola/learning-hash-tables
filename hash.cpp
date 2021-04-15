#include <iostream>
#include <fstream>
#include <string>
#include <list>

#include <iomanip>
#include <cstdlib>
#include <sstream>

#include <chrono>


class Hash{
    private:
        static const int tableSize = 10;

        struct book{
            std:: string title;
            std:: string author;
            int ISBN;
            int qty;

            book* next;

        };

        book* hashTable[tableSize];


    public:
    Hash();
    int function(std::string key);
    void add(std::string title, std::string author, int ISBN, int qty);
    int numberOfBooks(int index);
    void PrintTable();
    void PrintAllBooks(int index);
    void findAuthor(std::string title);
    void removeBook(std::string title);

    void readFile(std::string file);

};

void Hash::readFile(std::string file){
    std::string text;
  std::string file;
  std::cout<<"enter name of file: ";
  std::cin>>file;

  
  std::ifstream infile(file);
  if(infile.is_open()){
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

        add(title, author, isbn, quant);

//for printing each item
/*
        std::cout<<"title: "<<title<<"\n";
        std::cout<<"author: "<<author<<"\n";
        std::cout<<"isbn: "<<isbn<<"\n";
        std::cout<<"quantity: "<<quant<<"\n";
*/

    }
  }else{
    std::cout<<"file could not be found"<<std::endl;
  }
}

//default constructor
Hash::Hash(){
    for(int i = 0; i<tableSize; i++){
        hashTable[i] = new book;
        hashTable[i]->title = "noTitle";
        hashTable[i]->author = "noAuthor";
        hashTable[i]->ISBN = 0;
        hashTable[i]->qty = 0;
        hashTable[i]->next = NULL;
    }
}

//hash function
int Hash::function(std::string key){

    int hash = 0;
    int index;

    for(int i; i<key.length(); i++){
        hash += (int)key[i];
    }

    index = hash % tableSize;

    std::cout<<hash<<std::endl;
    return index;
}

//add books to the table
void Hash::add(std::string title, std::string author, int ISBN, int qty){
    
    int hash = 0;
    int index;

    for(int i; i<title.length(); i++){
        hash += (int)title[i];
    }

    index = hash % tableSize;
    std::cout<<index<<std::endl;
    
    //int index = function(title);
    //function tends to only return 0;

    if(hashTable[index]->title == "noTitle"){
        hashTable[index]->title = title;
        hashTable[index]->author = author;
        hashTable[index]->ISBN = ISBN;
        hashTable[index]->qty = qty;
    }else{
        book* p = hashTable[index];
        book* np = new book;

        np->title = title;
        np->author = author;
        np->ISBN = ISBN;
        np->qty = qty;
        np->next = NULL;

        while(p->next != NULL){
            p = p->next;
        }

        p->next = np;
    }
}



//count number of books an index
int Hash::numberOfBooks(int index){

    int count = 0;

    if(hashTable[index]->title =="noTitle"){
        return count;
    }else{
        count++;

        book* p = hashTable[index];

        while(p->next!=NULL){
            count++;
            p=p->next;
        }
    }

    return count;
}

//output the full table
//displays number of books that are present in each index
void Hash::PrintTable(){
    
    int number;

    for(int i=0; i<tableSize; i++){

        number = numberOfBooks(i);
        std::cout<<"--------------------\n";
        std::cout<<"index = "<< i << std::endl;
        std::cout<<"title = "<< hashTable[i]->title << std::endl;
        std::cout<<"author = "<< hashTable[i]->author << std::endl;
        std::cout<<"ISBN = "<< hashTable[i]->ISBN << std::endl;
        std::cout<<"quantity = "<< hashTable[i]->qty << std::endl;
        std::cout<<"No of books"<< number << std::endl;
        std::cout<<"--------------------\n";


    }
}

//displays all books in selected index
void Hash::PrintAllBooks(int index){
    book* p = hashTable[index];

    if(p->title =="noTitle"){
        std::cout<<"index = "<<index<<" is empty";
    }else{
        std::cout<<"index "<<index<<" contains the following books:\n";

        while(p!=NULL){
            std::cout<<"--------\n";
            std::cout<<p->title<<std::endl;
            std::cout<<p->author<<std::endl;
            std::cout<<p->ISBN<<std::endl;
            std::cout<<p->qty<<std::endl;
            std::cout<<"---------\n"<<std::endl;
            p = p->next;



        }
    
    }
}

//search functionality - helps find the author of each book by the title
void Hash::findAuthor(std::string title){
    int hash = 0;
    int index;

    for(int i; i<title.length(); i++){
        hash += (int)title[i];
    }

    index = hash % tableSize;
    //std::cout<<index<<std::endl; 

    bool found = false;
    std::string auth;

    book* p = hashTable[index];
    while(p != NULL){
        if(p->title == title){
            found = true;
            auth = p->author;
        }
        p = p->next;
    }

    if(found){
        std::cout<<"the book '"<<title<<"' was written by: "<< auth<<std::endl;
    }else{
        std::cout<<"the book '"<<title<<"' does not exist"<<std::endl;
    }
}

//remove a copy of selected book from the table
void Hash:: removeBook(std:: string title){
    int hash = 0;
    int index;

    for(int i; i<title.length(); i++){
        hash += (int)title[i];
    }

    index = hash % tableSize; 
    //std::cout<<index<<std::endl;

    book* del;
    book* p1;
    book* p2;

    /*
    case 1 - index is empty
    
    case 2 
    index is has only one book stored
     
    case 3
    index is has more than one book stored
    the match is the first book
    
    case 4 
    index is has more than one book stored
     - but there is no match
     - but there is a match 
    

    case X
    each tem in the indices have more than one book (hashtabel[index]->qty != 1)

    hashtable[index]->qty -= 1; 
    else: 
        perform the functions according to the required case
    */


    if(hashTable[index]-> title =="noTitle" && hashTable[index]-> author =="noAuthor"){

        std::cout<< title << " was not found \n";
    }else if(hashTable[index]->title == title && hashTable[index]->next == NULL){

        if(hashTable[index]->qty != 1){
            hashTable[index]->qty -= 1;

            std::cout<<"You removed a book titled: "<< title << "\n";
        }else{
            hashTable[index]->title = "noTitle";
            hashTable[index]->author = "noAuthor";

            std::cout<<"You removed a book titled: "<< title << "\n";
        }

        

    }else if(hashTable[index]->title == title){

        if(hashTable[index]->qty != 1){
            hashTable[index]->qty -= 1;

            std::cout<<"You removed a book titled: "<< title << "\n";
        }else{
            del = hashTable[index];
            hashTable[index] = hashTable[index]->next;
            delete del;

            std::cout<<"You removed a book titled: "<< title << "\n";
        }
        
        
    }else{
        p1 = hashTable[index]->next;
        p2 = hashTable[index];

        while(p1 != NULL && p1 -> title != title){
            p2 = p1;
            p1 = p1->next;
        }

        if(p1 == NULL){

            std::cout<< title << " was not found \n";

        }else{

            if(p1->qty!=1){
                p1->qty -= 1;

                std::cout<<"You removed a book titled: "<< title << "\n";
            }else{
                del = p1;
                p1 = p1->next;
                p2->next = p1;

                delete del;
                std::cout<<"You removed a book titled: "<< title << "\n";
            }
            
        }
    }

    
}


int main(){
    
    /*
    Hash h;
    
    h.add("tire", "david", 4567, 1);
    h.add("rob", "david", 4567, 7);
    h.add("a b nhngh", "david", 4567, 7);
    h.add("yawn", "david", 4567, 7);
    h.add("rob patterson", "david", 4567, 1);
    h.add("a nhn", "david", 4567, 7);
    h.add("levels", "david", 4567, 3);
    h.add("final", "david", 4567, 7);
    h.add("ppppppp", "david", 4567, 1);

    //h.removeBook("rob patterson");
    h.removeBook("tired");
    
    h.PrintAllBooks(5);
*/

    

    
}
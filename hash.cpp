#include <iostream>
#include <fstream>
#include <string>
#include <list>

/*class Hash{
  private:
    static const int hashgroup = 10;
    std::list<std::pair<int, std::string>>table[hashgroup];

    public:
      bool isEmpty() const;
      int function(int key);
      void insertbook(int key, std::string t);
      void removebook(int key);
      void searchbook(int key);
      void getTable();
      

};

bool Hash::isEmpty() const{
    int sum{};//brace initialization (sum = 0)
    for(int i{}; i<hashgroup; i++){
        sum+=table[i].size();
    }

    if (!sum){
        return true;
    }
    return false;
}

int Hash::function(int key){
    return key % hashgroup;
}

void Hash::insertbook(int key, std::string t){
    int hashVal = function(key);
    auto& cell = table[hashVal];
    auto bItr = begin(cell);//iteration from the begining
    bool keyExists = false;
    for(; bItr != end(cell); bItr++){
        if(bItr->first == key){
            keyExists = true;
            bItr->second = t;
            std::cout<< "key exists. value replaced."<< std::endl;
            break;

        }
    }
    if(!keyExists){
        cell.emplace_back(key, t);
    }

    return;

}

void Hash::removebook(int key){
    int hashVal = function(key);
    auto& cell = table[hashVal];
    auto bItr = begin(cell);//iteration from the begining
    bool keyExists = false;
    for(; bItr != end(cell); bItr++){
        if(bItr->first == key){
            keyExists = true;
            bItr = cell.erase(bItr);
            std::cout<< "book removed"<< std::endl;
            break;

        }
    }

    if(!keyExists){
        std::cout<<"key not found" <<std::endl;
    }

    return;
}

void Hash:: searchbook(int key){
    int hashVal = function(key);
    auto& cell = table[hashVal];
    auto bItr = begin(cell);//iteration from the begining
    bool keyExists = false;
    for(; bItr != end(cell); bItr++){
        if(bItr->first == key){
            keyExists = true;
            std::cout<< "\n\nsearch results...";
            std::cout<< "key: " <<bItr->first<<" value: "<<bItr->second<<std::endl;
            break;

        }
    }

    if(!keyExists){
        std::cout<<"key not found" <<std::endl;
    }

    return;
}

void Hash::getTable(){
    for(int i{}; i<hashgroup; i++){
        if(table[i].size()==0) continue;

        auto bItr = table[i].begin();
        for(; bItr!=table[i].end(); bItr++){
            std::cout<< "key: " <<bItr->first<<"value: "<<bItr->second<<std::endl;
        }
    }
    return;
}

int main(){
    Hash h;

    if(h.isEmpty()){
        std::cout<<"success";
    }else{
        std::cout<<"failed"<<std::endl;
    }

    h.insertbook(155, "a");
    h.insertbook(156, "b");
    h.insertbook(153, "c");
    h.insertbook(167, "d");
    h.insertbook(138, "e");
    h.insertbook(148, "f");
    h.insertbook(169, "g");
    h.insertbook(177, "h");
    h.insertbook(120, "i");
    h.insertbook(131, "j");
    h.insertbook(191, "k");

    h.getTable();

    h.searchbook(169);

    

    if(h.isEmpty()){
        std::cout<<"failed"<<std::endl;
    }else{
        std::cout<<"success"<<std::endl;
    }


    return 0;


}*/


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

};

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



//count number of items/books in index
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
    */

    /*
    case 2 
    index is has only one book stored
    */

    /*
    case 3
    index is has more than one book stored
    the match is the first book
    */

    /*
    case 4 
    index is has more than one book stored
     - but there is no match
     - but there is a match 
    */

    /*
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


    

    



    
}
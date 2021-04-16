#include <iostream>
#include <string>
#include <fstream>

#ifndef _BOOK_H_
#define _BOOK_H_

class Book{
    private:
        std::string title;
        std:: string author;
        int ISBN;
        int quantity;
    public:
        void start();
        void addBook();
        void searchBook();
        void getBooks();
        void removeBook();
    
};

#endif
#include <iostream>
#include <string>

#ifndef _BOOK_H_
#define _BOOK_H_

class Book{
    private:
        std::string title;
        std:: string author;
        int ISBN;
        int quantity;
    public:
        Book(std::string title, std::string author, int ISBN, int quantity);
        void addBook();
        void searchBook();
        void removeBook();
    
};

#endif
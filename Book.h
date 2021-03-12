#include <iostream>
#include <string>

#ifndef _BOOK_H_
#define _BOOK_H_


class Book{
    private:
        std::string title;
        std::string author;
        std::string ISBN;
        int quantity;
    public:
        Book();
        void addBook();
        void searchBook();
        void removeBook();
    
};

#endif
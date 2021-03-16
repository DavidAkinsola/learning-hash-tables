#include <iostream>
#include <string>

#ifndef _BOOK_H_
#define _BOOK_H_

template<class T>
class Book{
    private:
        T title;
        T author;
        T ISBN;
        T quantity;
    public:
        Book();
        T addBook();
        void searchBook();
        T removeBook();
    
};

#endif
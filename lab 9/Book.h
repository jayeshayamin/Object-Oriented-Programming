#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;

public:
    Book(const string& t, const string& a, const string& i);
    string gettitle() const;
    string getauthor() const;
    string getISBN() const;
};

#endif

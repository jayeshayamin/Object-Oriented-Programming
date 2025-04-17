#include "Book.h"

Book::Book(const string& t, const string& a, const string& i) 
    : title(t), author(a), isbn(i) {}

string Book::gettitle() const {
    return title;
}

string Book::getauthor() const {
    return author;
}

string Book::getISBN() const {
    return isbn;
}

#include <iostream>
#include "Book.h"

int main() {
    Book book1("1984", "George Orwell", "1234567890");

    cout << "Title: " << book1.gettitle() << endl;
    cout << "Author: " << book1.getauthor() << endl;
    cout << "ISBN: " << book1.getISBN() << endl;

    return 0;
}

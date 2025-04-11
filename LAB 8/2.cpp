#include <iostream>
#include <string>
using namespace std;

class Librarian;

class Book {
private:
    string title;
    float price;

public:
    Book(string t, float p) {
        title = t;
        price = p;
    }

    friend class Librarian;
};

class Librarian {
public:
    void show(Book b) {
        cout << "title: " << b.title << endl;
        cout << "price: " << b.price << endl;
    }

    void discount(Book& b, float percent) {
        b.price = b.price - (b.price * percent / 100);
    }
};

int main() {
    Book b("Harry Potter", 100);
    Librarian l;

    l.show(b);
    l.discount(b, 15);
    l.show(b);

    return 0;
}

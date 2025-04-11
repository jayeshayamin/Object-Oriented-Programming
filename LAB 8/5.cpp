#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int n, int d) {
        numerator = n;
        denominator = d;
    }

    Fraction operator+(Fraction f) {
        int n = numerator * f.denominator + f.numerator * denominator;
        int d = denominator * f.denominator;
        return Fraction(n, d);
    }

    Fraction operator-(Fraction f) {
        int n = numerator * f.denominator - f.numerator * denominator;
        int d = denominator * f.denominator;
        return Fraction(n, d);
    }

    Fraction operator*(Fraction f) {
        int n = numerator * f.numerator;
        int d = denominator * f.denominator;
        return Fraction(n, d);
    }

    Fraction operator/(Fraction f) {
        int n = numerator * f.denominator;
        int d = denominator * f.numerator;
        return Fraction(n, d);
    }

    friend ostream& operator<<(ostream& out, Fraction f) {
        out << f.numerator << "/" << f.denominator;
        return out;
    }
};

int main() {
    Fraction a(1, 2);
    Fraction b(3, 4);

    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;

    return 0;
}

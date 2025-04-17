#include <iostream>
#include <string>
using namespace std;

class PaymentMethod {
public:
    virtual bool processpayment(double amount) = 0;
    virtual ~PaymentMethod() {}
};

class CreditCard : public PaymentMethod {
    string cardnumber;
public:
    CreditCard(const string& card) : cardnumber(card) {}

    bool processpayment(double amount) override {
        if (cardnumber.length() == 16) {
            cout << "credit card payment of $" << amount << " successful\n";
            return true;
        } else {
            cout << "credit card payment failed: invalid card number\n";
            return false;
        }
    }
};

class DigitalWallet : public PaymentMethod {
    double balance;
public:
    DigitalWallet(double b) : balance(b) {}

    bool processpayment(double amount) override {
        if (balance >= amount) {
            balance -= amount;
            cout << "digital wallet payment of $" << amount << " successful\n";
            return true;
        } else {
            cout << "digital wallet payment failed: insufficient balance\n";
            return false;
        }
    }
};

int main() {
    CreditCard card("1234567890123456");
    DigitalWallet wallet(100);

    PaymentMethod* p1 = &card;
    PaymentMethod* p2 = &wallet;

    p1->processpayment(50);
    p2->processpayment(30);
    p2->processpayment(80);

    return 0;
}

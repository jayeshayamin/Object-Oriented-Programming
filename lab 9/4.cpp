#include <iostream>
#include <string>
using namespace std;

class PaymentMethod {
public:
    virtual void processPayment(double amount) = 0;
    virtual ~PaymentMethod() {}
};

class CreditCard : public PaymentMethod {
private:
    string cardNumber;
public:
    CreditCard(const string& number) : cardNumber(number) {}

    void processPayment(double amount) override {
        if (cardNumber.length() == 16) {
            cout << "Credit Card payment of $" << amount << " successful.\n";
        } else {
            cout << "Credit Card payment failed: Invalid card number.\n";
        }
    }
};

class DigitalWallet : public PaymentMethod {
private:
    double balance;
public:
    DigitalWallet(double bal) : balance(bal) {}

    void processPayment(double amount) override {
        if (balance >= amount) {
            balance -= amount;
            cout << "Digital Wallet payment of $" << amount << " successful. Remaining balance: $" << balance << "\n";
        } else {
            cout << "Digital Wallet payment failed: Insufficient balance.\n";
        }
    }
};

int main() {
    CreditCard cc("1234567812345678"); 
    DigitalWallet dw(100.0);

    PaymentMethod* payment1 = &cc;
    PaymentMethod* payment2 = &dw;

    payment1->processPayment(50.0);
    payment2->processPayment(60.0);
    payment2->processPayment(50.0);

    return 0;
}

#include <iostream>
#include <exception>
using namespace std;

class InsufficientFundsException : public exception
{
    string msg;

public:
    InsufficientFundsException(double deficit)
    {
        msg = "InsufficientFundsException - Deficit: $" + to_string(deficit);
    }
    const char *what() const noexcept override
    {
        return msg.c_str();
    }
};

template <typename T>
class BankAccount
{
    T balance;

public:
    BankAccount(T b)
    {
        balance = b;
    }

    void withdraw(T amount)
    {
        if (amount > balance)
        {
            throw InsufficientFundsException(amount - balance);
        }
        balance -= amount;
    }

    void show()
    {
        cout << "Balance: $" << balance << endl;
    }
};

int main()
{
    BankAccount<double> b(500);
    b.show();

    try
    {
        b.withdraw(600);
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}

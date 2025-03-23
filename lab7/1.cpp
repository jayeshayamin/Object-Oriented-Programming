#include <iostream>
#include <string>
using namespace std;


class Account {
protected:
    string holdernum;
    int accountnum;
    double balance;
public:
    Account(string name, int accNo, double bal)
        : holdernum(name), accountnum(accNo), balance(bal) {}

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited " << amount << ". New Balance:" << balance << endl;
    }

    virtual bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn" << amount << " New Balance: " << balance << endl;
            return true;
        } else {
            cout << "Insufficient funds!" << endl;
            return false;
        }
    }

    virtual void calculateInterest() 
    {
    	balance+=balance-(balance*5/100);
	}

    virtual void printStatement() const {
        cout << "Account Holder: " << holdernum << endl;
        cout << "Account Number: " << accountnum << endl;
        cout << "Balance:" << balance << endl;
    }

    ~Account() {}
};

class SavingsAccount : public Account {
private:
    double interestrate;
    double minbalance;
public:
    SavingsAccount(string name, int accNo, double bal, double rate, double minBal)
        : Account(name, accNo, bal), interestrate(rate), minbalance(minBal) {}

    void calculateInterest() override {
        double interest = balance * interestrate / 100;
        balance += interest;
        cout << "Interest of " << interest << "added. New Balance: " << balance << endl;
    }

    bool withdraw(double amount) override {
        if ((balance - amount) < minbalance) {
            cout << "Withdrawal failed Must maintain at least" << minbalance << " in account"<<endl;
            return false;
        }
        return Account::withdraw(amount);
    }

    void printStatement() const override {
        Account::printStatement();
        cout << "Account Type: Savings\nInterest Rate: " << interestrate << "%\n";
        cout << "Minimum Balance: " << minbalance << endl;
    }
};

class CheckingAccount : public Account {
private:
    double overdraftlimit;
public:
    CheckingAccount(string name, int accNo, double bal, double overdraft)
        : Account(name, accNo, bal), overdraftlimit(overdraft) {}

    void calculateInterest() override {
        cout << "No interest on Checking Accounts.\n";
    }

    bool withdraw(double amount) override {
        if ((balance - amount) >= -overdraftlimit) {
            balance -= amount;
            cout << "Withdrawn " << amount << ". New Balance:" << balance << endl;
            return true;
        } else {
            cout << "Overdraft limit exceeded! Withdrawal denied"<<endl;
            return false;
        }
    }

    void printStatement() const override {
        Account::printStatement();
        cout << "Account Type: Checking\nOverdraft Limit:" << overdraftlimit << endl;
    }
};

class FixedDepositAccount : public Account {
private:
    double fixedinterestrate;
    int maturityYears;
public:
    FixedDepositAccount(string name, int accNo, double bal, double rate, int years)
        : Account(name, accNo, bal), fixedinterestrate(rate), maturityYears(years) {}

    void calculateInterest() override {
        double interest = balance * fixedinterestrate * maturityYears / 100;
        cout << "Fixed Deposit Interest after " << maturityYears << " years: $" << interest << endl;
    }

    bool withdraw(double amount) override {
        cout << "Withdrawal not allowed before maturity!\n";
        return false;
    }

    void printStatement() const override {
        Account::printStatement();
        cout << "Account Type: Fixed Deposit\nInterest Rate: " << fixedinterestrate << "%\n";
        cout << "Maturity: " << maturityYears << " years\n";
    }
};

int main() {
    Account* acc1 = new SavingsAccount("A", 101, 5000, 5.0, 1000);
    Account* acc2 = new CheckingAccount("B", 102, 2000, 500);
    Account* acc3 = new FixedDepositAccount("C", 103, 10000, 6.0, 5);
    acc1->printStatement();
    acc1->deposit(1000);
    acc1->calculateInterest();
    acc1->withdraw(6000);
    acc2->printStatement();
    acc2->withdraw(2300);
    acc2->calculateInterest();
    acc3->printStatement();
    acc3->calculateInterest();
    acc3->withdraw(5000);
    delete acc1;
    delete acc2;
    delete acc3;

    return 0;
}


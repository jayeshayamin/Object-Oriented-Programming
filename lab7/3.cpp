#include <iostream>
#include <string>
using namespace std;

class Currency {
public:
    double amount;
    string currencycode;
    string currencysymbol;
    float exchangerate;

    Currency(double a, string cc, string cs, float s)
        : amount(a), currencycode(cc), currencysymbol(cs), exchangerate(s) {}

    virtual void converttobase() {
        double newamount = amount * exchangerate;
        cout << "Converted to base currency (USD): " << newamount << " USD" << endl;
    }

    virtual void displaycurrency() const {
        cout << "Amount: " << amount
             << " | Currency Code: " << currencycode
             << " | Currency Symbol: " << currencysymbol
             << " | Exchange Rate: " << exchangerate
             << endl;
        cout << "***********************************************************" << endl;
    }

    virtual ~Currency() {}

    void converttocurrency(string targetcurrency);
};

class Dollar;
class Rupee;
class Euro;

class Dollar : public Currency {
public:
    Dollar(double a) : Currency(a, "USD", "$", 1.0) {}

    void converttobase() {
        cout << "Dollar remains the base currency: " << amount << " USD" << endl;
    }

    void displaycurrency() {
        cout << "Dollar: ";
        Currency::displaycurrency();
    }
};

class Rupee : public Currency {
public:
    Rupee(double a) : Currency(a, "PKR", "Rs", 0.0061) {}

    void converttobase() {
        double convertedAmount = amount * exchangerate;
        cout << "Converted Rupee to USD: " << convertedAmount << " USD" << endl;
    }

    void displaycurrency() {
        cout << "Rupee: ";
        Currency::displaycurrency();
    }
};

class Euro : public Currency {
public:
    Euro(double a) : Currency(a, "EUR", "€", 1.1) {}

    void converttobase() {
        double convertedAmount = amount * exchangerate;
        cout << "Converted Euro to USD: " << convertedAmount << " USD" << endl;
    }

    void displaycurrency() {
        cout << "Euro: ";
        Currency::displaycurrency();
    }
};

void Currency::converttocurrency(string targetcurrency) {
    if (targetcurrency == "dollar" || targetcurrency == "Dollar") {
        Dollar dollar(amount);
        dollar.converttobase();
    } else if (targetcurrency == "rupee" || targetcurrency == "Rupee") {
        Rupee rupee(amount);
        rupee.converttobase();
    } else if (targetcurrency == "euro" || targetcurrency == "Euro") {
        Euro euro(amount);
        euro.converttobase();
    } else {
        cout << "Invalid currency." << endl;
    }
}

int main() {
    Currency* usd = new Dollar(100);
    Currency* eur = new Euro(100);
    Currency* pkr = new Rupee(1000);

    usd->displaycurrency();
    eur->displaycurrency();
    pkr->displaycurrency();

    usd->converttobase();
    eur->converttobase();
    pkr->converttobase();

    pkr->converttocurrency("dollar");
    eur->converttocurrency("rupee");

    delete usd;
    delete eur;
    delete pkr;

    return 0;
}
#include <iostream>
using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;

public:
    Currency(double a, string c, string s, double r)
        : amount(a), currencyCode(c), currencySymbol(s), exchangeRate(r) {}

    virtual double convertToBase() {
        return amount * exchangeRate;
    }

    virtual double convertTo(double targetRate) {
        return (amount * exchangeRate) / targetRate;
    }

    virtual void displayCurrency() {
        cout << "Amount: " << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }

    double getExchangeRate() const { return exchangeRate; }
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}

    void displayCurrency() override {
        cout << "Dollar Amount: " << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 1.10) {}

    void displayCurrency() override {
        cout << "Euro Amount: " << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }
};

class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, "INR", "₹", 0.012) {} 

    void displayCurrency() override {
        cout << "Rupee Amount: " << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }
};

int main() {
    Dollar usd(100);
    Euro eur(100);
    Rupee inr(100);

    usd.displayCurrency();
    cout << "Converted to Base (USD): $" << usd.convertToBase() << endl << endl;

    eur.displayCurrency();
    cout << "Converted to Base (USD): $" << eur.convertToBase() << endl;
    cout << "Converted to INR: ₹" << eur.convertTo(0.012) << endl << endl; 

    inr.displayCurrency();
    cout << "Converted to Base (USD): $" << inr.convertToBase() << endl;
    cout << "Converted to Euro: €" << inr.convertTo(1.10) << endl; 

    return 0;
}

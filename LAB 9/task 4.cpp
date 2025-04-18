#include <iostream>
#include <string>
using namespace std;

class PaymentMethod {
public:
    virtual bool processPayment(double amount) = 0;
    virtual ~PaymentMethod() {}
};

class CreditCard : public PaymentMethod {
private:
    string cardNumber;

public:
    CreditCard(string number) : cardNumber(number) {}

    bool processPayment(double amount) override {
        if (!cardNumber.empty() && amount > 0) {
            cout << "CreditCard Payment of $" << amount << " successful using card: " << cardNumber << endl;
            return true;
        } else {
            cout << "CreditCard Payment failed." << endl;
            return false;
        }
    }
};

class DigitalWallet : public PaymentMethod {
private:
    double balance;

public:
    DigitalWallet(double initialBalance) : balance(initialBalance) {}

    bool processPayment(double amount) override {
        if (amount <= balance && amount > 0) {
            balance -= amount;
            cout << "DigitalWallet Payment of $" << amount << " successful. Remaining balance: $" << balance << endl;
            return true;
        } else {
            cout << "DigitalWallet Payment failed. Insufficient balance or invalid amount." << endl;
            return false;
        }
    }
};

int main() {
    CreditCard card("1234-5678-9012-3456");
    DigitalWallet wallet(100.0);

    card.processPayment(50.0);
    wallet.processPayment(30.0);
    wallet.processPayment(80.0);

    return 0;
}

#include <iostream>
#include <exception>
#include <sstream>

using namespace std;

class InsufficientFundsException : public exception {
    string msg;
public:
    InsufficientFundsException(double d) {
        ostringstream out;
        out << "InsufficientFundsException - Deficit: $" << d;
        msg = out.str();
    }

    const char* what() const noexcept override {
        return msg.c_str();
    }
};

template <typename T>
class BankAccount {
    T bal;
public:
    BankAccount(T b) : bal(b) {}

    void withdraw(T amt) {
        if (amt > bal) throw InsufficientFundsException(amt - bal);
        bal -= amt;
    }

    void show() {
        cout << "Balance: $" << bal << endl;
    }
};

int main() {
    BankAccount<double> acc(500.0);
    acc.show();

    try {
        acc.withdraw(600);
    } catch (const exception& e) {
        cerr << "Withdraw $600: " << e.what() << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

class Account {
protected:
    int accountNumber;
    float balance;
    string accountHolderName;
    string accountType;
    float* transactions; 
    int T_count;

public:
    Account(int an, float b, string ahn, string at) 
        : accountNumber(an), balance(b), accountHolderName(ahn), accountType(at), T_count(0) {
        transactions = new float[1];
        transactions[0] = balance;
    }

    virtual void deposit(float amount) {
        balance += amount;
        
        float* temp = new float[T_count + 1];
        for (int i = 0; i < T_count; i++) {
            temp[i] = transactions[i];
        }
        temp[T_count] = amount;

        delete[] transactions;
        transactions = temp;
        T_count++;

        cout << "Deposited: " << amount << ". New Balance: " << balance << endl;
    }

    virtual void withdraw(float amount) {
        if (amount <= balance) {
            balance -= amount;

            float* temp = new float[T_count + 1];
            for (int i = 0; i < T_count; i++) {
                temp[i] = transactions[i];
            }
            temp[T_count] = -amount;

            delete[] transactions;
            transactions = temp;
            T_count++;

            cout << "Withdrawn: " << amount << ". Remaining Balance: " << balance << endl;
        } else {
            cout << "Insufficient balance!\n";
        }
    }

    virtual void calculateInterest() {
        cout << "Interest calculation not applicable for base Account.\n";
    }

    virtual void printStatement() {
        cout << "\n Transaction Statement for " << accountHolderName << " :\n";
        for (int i = 0; i < T_count; i++) {
            cout << (transactions[i] < 0 ? "Withdraw: " : "Deposit: ") << abs(transactions[i]) << endl;
        }
        cout << "Current Balance: " << balance << endl;
    }

    virtual ~Account() {
        delete[] transactions;
    }
};

class SavingsAccount : public Account {
    float interestRate;
    float minimumBalance;

public:
    SavingsAccount(int an, float b, string ahn, float ir, float mb)
        : Account(an, b, ahn, "Savings"), interestRate(ir), minimumBalance(mb) {}

    void calculateInterest() override {
        float interest = balance * (interestRate / 100);
        cout << "Interest Earned: " << interest << endl;
        deposit(interest); 
    }

    void withdraw(float amount) override {
        if (balance - amount < minimumBalance) {
            cout << "Cannot withdraw! Minimum balance requirement: " << minimumBalance << endl;
        } else {
            Account::withdraw(amount);
        }
    }
};


class CheckingAccount : public Account {
    float overdraftLimit;

public:
    CheckingAccount(int an, float b, string ahn, float odLimit)
        : Account(an, b, ahn, "Checking"), overdraftLimit(odLimit) {}

    void withdraw(float amount) override {
        if (balance - amount < -overdraftLimit) {
            cout << "Overdraft limit exceeded!\n";
        } else {
            Account::withdraw(amount);
        }
    }
};


class FixedDepositAccount : public Account {
    int maturityDate;
    float fixedInterestRate;

public:
    FixedDepositAccount(int an, float b, string ahn, int md, float fir)
        : Account(an, b, ahn, "Fixed Deposit"), maturityDate(md), fixedInterestRate(fir) {}

    void calculateInterest() override {
        float interest = balance * (fixedInterestRate / 100);
        cout << "Fixed Deposit Interest Earned: " << interest << endl;
    }

    void withdraw(float amount) override {
        cout << "Withdrawals are not allowed before maturity date: " << maturityDate << endl;
    }
};


int main() {
    SavingsAccount sa(1001, 5000, "zaid", 5.0, 1000);
    CheckingAccount ca(1002, 3000, "anus", 500);
    FixedDepositAccount fda(1003, 10000, "mina", 2026, 7.0);


    sa.deposit(2000);
    sa.withdraw(1500);
    sa.calculateInterest();
    sa.printStatement();


    ca.withdraw(3500);
    ca.withdraw(500);
    ca.printStatement();


    fda.calculateInterest();
    fda.withdraw(500);
    fda.printStatement();

    return 0;
}

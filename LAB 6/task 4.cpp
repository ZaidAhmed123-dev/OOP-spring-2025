#include<iostream>
using namespace std;

class Account{
	protected:
	int accountNumber;
	float balance;
	
	public:
		Account(int an,float b):accountNumber(an),balance(b){}
		
		void displayDetails()
		{
			cout<<"Account Number: "<<accountNumber<<endl;
			cout<<"balance: "<<balance<<" Rs."<<endl;
		}
};

class SavingsAccount:public Account{
	float interestRate;
		
	public:
		SavingsAccount(int an,float b,float ir):Account(an,b),interestRate(ir){}
		
		void displayDetails()
		{
			Account::displayDetails();
			cout<<"Interest Rate: "<<interestRate<<" %"<<endl;
		}
};

class CheckingAccount:public Account{
	float overdraftlimit;
	
	public:
		CheckingAccount(int an,float b,float odl): Account(an,b),overdraftlimit(odl){}
		
		void displayDetails()
		{
			Account::displayDetails();
			cout<<"Overdraft Limit: "<<overdraftlimit<<" Rs."<<endl;
		}
};

int main()
{
	int op;
	SavingsAccount s1(500,100000,20);
	CheckingAccount c1(2500,70000,50000);
	
	while(1){
	cout<<"________________________________________\n";
	cout<<"......ABC BANK.....\n";
	cout<<"1. Savings Account\n2. Checking Account\n3. exit\n";
	cout<<"choose: ";cin>>op;

	switch(op)
	{
		case 1:
			s1.displayDetails();
			break;
		case 2:
			c1.displayDetails();
			break;
		case 3:
			return 0;
			break;
		default:
			cout<<"wrong option.\n";
	}
	}
	return 0;
}

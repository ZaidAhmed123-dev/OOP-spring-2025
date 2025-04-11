#include<iostream>
using namespace std;

class Currency{
	float amount;
	
	public:
		Currency(float a=0.0):amount(a){
		}	
		
		Currency operator-()
		{
			return Currency(-amount);
		}
		
		Currency operator+(Currency &other)
		{
			return amount+other.amount;
		}
		
		Currency operator-(Currency &other)
		{
			return amount-other.amount;
		}
		
		Currency operator+=(Currency &other)
		{
			return amount+=other.amount;
		}
		
		Currency operator-=(Currency &other)
		{
			return amount-=other.amount;
		}
		
		friend ostream& operator<<(ostream& out,const Currency &other)
		{
			out<<other.amount<<endl;
			return out;
		}
};

int main()
{
	Currency Rupee(200);
	Currency Euro(30);
	cout<<"Original values: "<<endl;
	cout<<Rupee;
	cout<<Euro<<endl;
	
	
	Currency c;
	c=Rupee+Euro;
	cout<<"Addition: ";
	cout<<c;
	
	c=Rupee-Euro;
	cout<<"Subtraction: ";
	cout<<c;
	
	
	cout<<"Negative value: ";
	cout<< (-Rupee);
	
	
	Rupee+=Euro;
	cout<<"Rupee = Rupee + Euro: ";
	cout<<Rupee;
	
	Rupee-=Euro;
	cout<<"Rupee = Rupee - Euro: ";
	cout<<Rupee;
	
}
